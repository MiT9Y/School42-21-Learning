def get_dict(d):
	res = {}
	for el in d:
		if el[1] in res:
			res[el[1]] += ' ' + el[0]
		else:
			res[el[1]] = el[0]
	return res

def print_dict(d):
	for key, val in d.items():
  		print(key, ':', val)

def main():
	d = [
	('Hendrix' , '1942'),
	('Allman' , '1946'),
	('King' , '1925'),
	('Clapton' , '1945'),
	('Johnson' , '1911'),
	('Berry' , '1926'),
	('Vaughan' , '1954'),
	('Cooder' , '1947'),
	('Page' , '1944'),
	('Richards' , '1943'),
	('Hammett' , '1962'),
	('Cobain' , '1967'),
	('Garcia' , '1942'),
	('Beck' , '1944'),
	('Santana' , '1947'),
	('Ramone' , '1948'),
	('White' , '1975'),
	('Frusciante', '1970'),
	('Thompson' , '1949'),
	('Burton' , '1939')
	]	
	my_dict = get_dict(d)
	print_dict(my_dict)

if __name__ == '__main__':
	main()