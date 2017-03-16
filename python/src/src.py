import os
import sys

from command import KeyCommand
from controller import Controller

#####################
#Print usage text
#####################
def PrintUsage():
	print('This is usage output')
	sys.exit()

#####################
#program entry point
#####################
if __name__=="__main__":
	
	#Sanity check for command line args
	if len(sys.argv) < 2:
		PrintUsage()
	
	
	#Define file paths for database files
	path = os.getcwd() + '\Database'
	ir_db = path + 'IRCodeDB.xml'
	#uart_db = path + 'UARTCodeDB.csv'
	
	#Load database files
	
	
	#Mode check
	is_simulation = False
	is_verify = False
	is_adhoc = False
	
	for i in range(0, len(sys.argv)):
		if sys.argv[i] == '--simulate':
			is_simulation = True
		if sys.argv[i] == '--adhoc':
			is_adhoc = True
		if sys.argv[i] == '--verify':
			is_verify = True
	
	ctrl = Controller(is_simulation, is_verify)
	
	#Ad-Hoc mode
	if(is_adhoc):
		adhoc_desc = \
		"*** Ad-Hoc Mode (a.k.a. At-Your-Will Mode) ***\n" + \
		"- Currently supports Samsung TV control only.\n" + \
		"- Type key name to send the key.\n" + \
		"- Type 'quit' to exit the program.\n"
		print(adhoc_desc)
		
		#Keep displaying input prompt until user enters 'quit'
		while True:
			print('')
			user_in = input('>> ')
			if user_in == 'quit':
				break
			#Send entered key
			cmd = KeyCommand(user_in, 'samsung_tv', 0, 1)
			ctrl.send(cmd)
		
	#Script mode
	else:
		if not is_verify: print('Begin running script...\n')
		running_time = ctrl.run_script(sys.argv[1])
		if not is_verify: print('\nCompleted running script!')
		if is_verify:
			print('Syntax check passed...')
			print('Expected running time: {0}s'.format(str(running_time / 1000)))
	