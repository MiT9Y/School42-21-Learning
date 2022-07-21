import antigravity
import sys

def main():
	if len(sys.argv) == 4:
		try:
			f1 = float(sys.argv[1])
			f2 = float(sys.argv[2])
			data = sys.argv[3].encode('UTF-8')
			antigravity.geohash(f1, f2, data)
		except Exception as e:
			print("Wrong init arguments. Expected: float, float, date(example: '2005-05-26-10458.68')")
	else:
		print("Wrong number of arguments. Expected: float, float, date(example: '2005-05-26-10458.68')")

if __name__ == '__main__':
	main()