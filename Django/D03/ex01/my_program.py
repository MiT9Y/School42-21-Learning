from local_lib import path

def main():
	directory = path.Path('dir')
	directory.mkdir()
	file = path.Path('dir/readme.txt')
	file.touch()
	file.write_text("This is your advertising space.")
	text = file.read_text()
	print(text)

if __name__ == '__main__':
	main()