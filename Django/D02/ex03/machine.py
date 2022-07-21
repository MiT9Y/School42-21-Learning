import random, beverages

class CoffeeMachine:
	class BrokenMachineException(Exception):
		def __init__(self):
			Exception.__init__(self, "This coffee machine has to be repaired.")

	class EmptyCup(beverages.HotBeverage):
		def __init__(self):
			beverages.HotBeverage.__init__(self, 0.90, "empty cup")
		def description(self):
			return "An empty cup?! Gimme my money back!"

	def __init__(self):
		self.servises_sum = 0

	def repair(self):
		self.servises_sum = 0

	def serve(self, beverages_class):
		if self.servises_sum == 10:
			raise self.BrokenMachineException()
		elif not issubclass(beverages_class, beverages.HotBeverage):
			return self.EmptyCup()
		else:
			self.servises_sum += 1
			return beverages_class() if random.randrange(5) else self.EmptyCup()

def main():
	max_len = 23
	all_beverages = (beverages.Coffee, beverages.Tea, beverages.Chocolate, beverages.Cappuccino)
	coffeemachine = CoffeeMachine()
	while max_len > 0:
		try:
			print(coffeemachine.serve(all_beverages[random.randrange(len(all_beverages))]))
		except Exception as e:
			print(e, "\n")
			coffeemachine.repair()
		max_len -= 1

if __name__ == "__main__":
	main()