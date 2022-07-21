class HotBeverage:
	def __init__(self, price = 0.30, name = "hot beverage"):
		self.price = price
		self.name = name

	def description(self):
		return "Just some hot water in a cup."

	def __str__(self):
		res = "name : " + self.name + "\n" 
		res = res + "price : " + "%.2f" % self.price + "\n"
		res = res + "description : " + self.description() + "\n"
		return res

class Coffee(HotBeverage):
	def __init__(self):
		HotBeverage.__init__(self, 0.40, 'coffee')

	def description(self):
		return "A coffee, to stay awake."


class Tea(HotBeverage):
	def __init__(self):
		HotBeverage.__init__(self, name = 'tea')


class Chocolate(HotBeverage):
	def __init__(self):
		HotBeverage.__init__(self, 0.50, 'chocolote')

	def description(self):
		return  "Chocolate, sweet chocolate..."


class Cappuccino(HotBeverage):
	def __init__(self):
		HotBeverage.__init__(self, 0.45, 'cappuchino')

	def description(self):
		return "Un po’ di Italia nella sua tazza!"
		
def main():
	hotbeverage = HotBeverage()
	coffee = Coffee()
	tea = Tea()
	chocolate = Chocolate()
	cappuccino = Cappuccino()
	print(hotbeverage)
	print(coffee)
	print(tea)
	print(chocolate)
	print(cappuccino)

if __name__ == "__main__":
	main()