import sys

def get_revers_dict(d):
	res = {}
	for el in d:
		res[el[1]] = el[0]
	return res

def main():	
	if len(sys.argv) == 2:
		states = {
		"Oregon" : "OR",
		"Alabama" : "AL",
		"New Jersey": "NJ",
		"Colorado" : "CO"
		}
		states_rev = get_revers_dict(states.items())
		capital_cities = {
		"OR": "Salem",
		"AL": "Montgomery",
		"NJ": "Trenton",
		"CO": "Denver"
		}
		capital_cities_rev = get_revers_dict(capital_cities.items())
		words = sys.argv[1].split(',')
		i = 0
		while i < len(words):
			words[i] = words[i].strip()
			word = words[i].lower().title()
			if word != "":
				if word in states:
					print(capital_cities[states[word]], "is the capital of", word)
				elif word in capital_cities_rev:
					print(word, "is the capital of", states_rev[capital_cities_rev[word]])
				else:
					print(words[i], "is neither a capital city nor a state")
			i = i + 1

if __name__ == '__main__':
	main()