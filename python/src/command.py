class KeyCommand:
	def __init__(self, name, device, delay, repeat):
		self._name = name
		self._device = device
		self._delay = delay
		self._repeat = repeat
		
	@property
	def name(self):
		return self._name
	
	@property
	def device(self):
		return self._device
	
	@property
	def delay(self):
		return self._delay
	
	@property
	def repeat(self):
		return self._repeat
	
