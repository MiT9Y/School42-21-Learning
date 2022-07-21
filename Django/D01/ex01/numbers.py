def main():
	f = open("numbers.txt", "r")
	content = f.read()
	f.close()
	numbers = content.split(',')
	for number in numbers:
		print(number.strip())

if __name__ == '__main__':
	main()