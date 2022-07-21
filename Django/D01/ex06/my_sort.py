def get_rev_dict(d):
	res = {}
	if type(d) is dict:
		for key, val in d.items():
			if val not in res:
				res[val] = [key]
			else:
				res[val].append(key)
	return res

def main():
	d = {
	'Hendrix' : '1942',
	'Allman' : '1946',
	'King' : '1925',
	'Clapton' : '1945',
	'Johnson' : '1911',
	'Berry' : '1926',
	'Vaughan' : '1954',
	'Cooder' : '1947',
	'Page' : '1944',
	'Richards' : '1943',
	'Hammett' : '1962',
	'Cobain' : '1967',
	'Garcia' : '1942',
	'Beck' : '1944',
	'Santana' : '1947',
	'Ramone' : '1948',
	'White' : '1975',
	'Frusciante': '1970',
	'Thompson' : '1949',
	'Burton' : '1939'
	}
	new_d = get_rev_dict(d)
	sort_years = list(new_d.keys())
	sort_years.sort()
	for i in sort_years:
		new_d[i].sort()
		for musician in new_d[i]:
			print(musician)

if __name__ == '__main__':
	main()