class Intern:
	def __init__(self, name = "My name? I’m nobody, an intern, I have no name."):
		self.name = name
		self.coffee = self.Coffee()

	def __str__(self):
		return self.name

	class Coffee:
		def __str__(self):
			return "This is the worst coffee you ever tasted."

	def work(self):
		raise Exception("I’m just an intern, I can’t do that...")

	def make_coffee(self):
		return self.coffee

def main():
	intern = Intern()
	mark = Intern("Mark")
	print(intern)
	print(mark)
	coffee = mark.make_coffee()
	print(coffee)
	try:
		intern.work()
	except Exception as e:
		print(e)

if __name__ == "__main__":
	main()