from command import KeyCommand
import time
import sys
from subprocess import call

class Controller:
	#Constructor
	def __init__ (self, is_simulation, is_verify):
		self.is_simulation = is_simulation
		self.is_verify = is_verify
	
	#Sends an IR packet for given command
	def send(self, cmd):
		for i in range(cmd.repeat):
			is_sent = False
			if not self.is_simulation and not self.is_verify:
				#Send actual IR packet via RedRat
				call(["irsend", "SEND_ONCE", cmd.device, cmd.name])
				is_sent = True
			
			if is_sent or self.is_simulation:
				#Pretty-print the time
				if cmd.delay >= 1000:
					delay_str = str(float(cmd.delay / 1000)) + 's'
				else:
					delay_str = str(cmd.delay) + 'ms'
				
				if cmd.repeat == 1:
					print('Sent [{0}] to [{1}]; waiting {2}'.format( \
					cmd.name, cmd.device, delay_str))
				else:
					print('Sent [{0}] to [{1}]; waiting {2}; {3}/{4}'.format( \
					cmd.name, cmd.device, delay_str, i + 1, cmd.repeat))
				time.sleep(cmd.delay / 1000)
			elif not self.is_verify:
				print('Failed to send [{0}] to [{1}]'.format( \
				cmd.name, cmd.device))
				sys.exit(1)
	
	#Interprets and executes the given script
	def run_script(self, path):
		with open(path, 'r') as f:
			content = f.readlines()
		
		#Trim whitespaces from each line
		script = []
		for line in content:
			script.append(line.strip())
		
		#Declare various parameters with default values
		is_defined = False
		is_define_block = False
		is_test_block = False
		test_name = ''
		test_delay = 0
		test_count = 0
		test_complete = 0
		idx_test_begin = 0
		running_time = 0
		
		#Loop through each line of script
		i = 0
		while i < len(script):
			#Beginning of definition block
			if script[i] == 'define':
				if is_define_block or is_test_block:
					self.print_error(path, script[i], i, \
					'Error: nested blocks not allowed')
					sys.exit(1)
				is_define_block = True
			
			#Beginning of test block
			elif script[i].startswith('test('):
				if is_define_block or is_test_block:
					self.print_error(path, script[i], i, \
					'Error: netsted blocks not allowed')
					sys.exit(1)
				if not is_defined:
					self.print_error(path, script[i], i, \
					'Error: missing define block')
					sys.exit(1)
				
				#Extract arguments
				test_param = script[i][5:-1].split(',')
				if len(test_param) != 3:
					self.print_error(path, script[i], i, 'Error: missing arguments')
					sys.exit(1)
				test_name = test_param[0].strip('"')
				test_delay = self.parse_time(test_param[1])
				test_count = int(test_param[2])
				
				is_test_block = True
				idx_test_begin = i
				if not self.is_verify:
					print('{0}: {1} / {2}'.format(test_name, test_complete + 1, test_count))
				
			#End of blocks
			elif script[i] == 'end':
				#End of define block
				if is_define_block:
					is_define_block = False
					is_defined = True
				#End of test block
				elif is_test_block:
					test_complete += 1
					is_test_block = False
					
					#Ignore time delay if in 'verify' mode
					running_time += test_delay
					if not self.is_verify:
						#Pretty-print the time
						if test_delay >= 1000:
							delay_str = str(float(test_delay / 1000)) + 's'
						else:
							delay_str = str(test_delay) + 'ms'
						print('Pausing for {0}...\n'.format(delay_str))
						time.sleep(test_delay / 1000)
					#Repeat current test block if needed
					if test_complete < test_count:
						i = idx_test_begin
						continue
					else:
						if not self.is_verify: print('{0}: End'.format(test_name))
						test_name = ''
						test_delay = 0
						test_complete = 0
						test_count = 0
						idx_test_begin = 0
				#Orphan 'end'
				else:
					self.print_error(path, script[i], i, \
					'Error: orphan \'end\' found')
			
			#All other cases
			else:
				#Within define block
				if is_define_block:
					x = 0
				#Within test block
				elif is_test_block:
					#Extract arguments
					idx_open = script[i].index('(')
					func_name = script[i][:idx_open]
					func_param = script[i][idx_open+1:-1].split(',')
					
					#'key_send' function
					if func_name == 'key_send':
						device = func_param[1].strip()
						key = func_param[0].strip()
						delay = self.parse_time(func_param[2].strip())
						repeat = int(func_param[3].strip())
						cmd = KeyCommand(device, key, delay, repeat)
						self.send(cmd)
						running_time += delay * repeat
					#'pause' function
					elif func_name == 'pause':
						delay = self.parse_time(func_param[0])
						running_time += delay
						if not self.is_verify:
							#Pretty-print the time
							if delay >= 1000:
								delay_str = str(float(delay / 1000)) + 's'
							else:
								delay_str = str(delay) + 'ms'
							print('Pausing for {0}...'.format(delay_str))
							time.sleep(delay / 1000)
							
					#'print' function
					elif func_name == 'print':
						if not self.is_verify: print(func_param[0].strip('"'))
					#'scipt' function
					elif func_name == 'script':
						self.run_script(func_param[0])
					
				#Outside of block
				else:
					if not script[i].startswith('//') and not script[i] == '':
						self.print_error(path, script[i], i, \
						'Error: statement must be within a block')
						sys.exit(1)
			i += 1	#increment loop counter
		return running_time
	
	#Parses user-given time string to a floating point (in milisec)
	def parse_time(self, time_str):
		time_str = time_str.strip('s')
		if time_str.endswith('m'):
			return float(time_str.strip('m'))
		else:
			return float(time_str) * 1000
	
	#Prints error messages for scripts
	def print_error(self, file, statement, line_num, error):
		print('File: "{0}", line {1}'.format(file, line_num))
		print('  {0}'.format(statement))
		print('')
		print(error)