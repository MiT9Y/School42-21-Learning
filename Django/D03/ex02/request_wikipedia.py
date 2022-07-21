import requests, json, dewiki, sys

def main():
	if len(sys.argv) !=2:
		print("Expecting name of the search parameter.")
		return

	if sys.argv[1].strip() == '':
		print("Need something to search.")
		return
	filename = "_".join(sys.argv[1].split()) + ".wiki"
	url_servise = 'https://en.wikipedia.org/w/api.php'

	params = {
		"action": "parse",
		"page": sys.argv[1].strip(),
		"prop": "wikitext",
		"format": "json",
		"redirects": True,
		"formatversion": 2
	}
	res = requests.get(url = url_servise, params=params)
	if res.ok == False:
		print("Error", res.status_code, ":", res.reason)
		return
	res = res.json()
	if 'parse' in res.keys():
		res = res['parse']
		if 'wikitext' in res.keys():
			res = res['wikitext']
		else:
			res = None
	else:
		res = None
	if res is None:
		print("No result")
		return
	res = dewiki.from_string(res)

	try:
		f = open(filename, "w")
		f.write(res)
		f.close()
	except BaseException as e:
		print("Error write file:", e)

if __name__ == '__main__':
	main()