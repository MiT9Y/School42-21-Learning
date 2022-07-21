import sys

def get_dict(d):
	res = {}
	for el in d:
		res[el[1]] = el[0]
	return res

def main():
	states = {
	"Oregon" : "OR",
	"Alabama" : "AL",
	"New Jersey": "NJ",
	"Colorado" : "CO"
	}
	capital_cities = {
	"OR": "Salem",
	"AL": "Montgomery",
	"NJ": "Trenton",
	"CO": "Denver"
	}
	states = get_dict(states.items())
	capital_cities = get_dict(capital_cities.items())
	if len(sys.argv) == 2:
		if sys.argv[1] in capital_cities:
			print(states[capital_cities[sys.argv[1]]])
		else:
			print("Unknown capital city")

if __name__ == '__main__':
	main()