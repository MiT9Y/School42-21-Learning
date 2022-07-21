import sys, requests
from bs4 import BeautifulSoup

def brackets_del(text):
	count_l = 0
	count_r = 0
	pos_l = text.find('(')
	if pos_l != -1:
		count_l += 1
		pos = pos_l
	while pos_l != -1:
		pos_r = text.find(')', pos + 1)
		pos = text.find('(', pos + 1)
		if count_l > 10:
			return
		if pos_r == -1:
			return ''
		if pos != -1 and pos < pos_r:
			count_l += 1
		else:
			pos = pos_r
			count_r += 1
		if count_l == count_r:
			if text[pos_l:pos_r].find('<') != -1:
				text = text[:pos_l] + text[pos_r + 1:]
				count_l = 0
				count_r = 0
				pos_l = text.find('(')
				if pos_l != -1:
					count_l += 1
					pos = pos_l
			else:
				count_l = 0
				count_r = 0
				pos_l = text.find('(', pos_r + 1)
				if pos_l != -1:
					count_l += 1
					pos = pos_l
	return text

def get_next_search(search):
	session = requests.Session()
	res = session.get(url='https://en.wikipedia.org/wiki/' + search)
	if res.ok == False:
		return None	
	data = res.text
	soup = BeautifulSoup(data, 'html.parser')
	soup = BeautifulSoup(str(soup.find('div', id='mw-content-text')), 'html.parser')
	find_p = soup.find_all('p')
	for tag_p in find_p:
		find_a = BeautifulSoup(brackets_del(str(tag_p)), 'html.parser').find_all('a')
		for tag_a in find_a:
			if tag_a.has_attr('title') and tag_a.has_attr('href'):
				if (tag_a['href'].startswith('/wiki/') and tag_a['href'].find('Help:') == -1):
					return tag_a['href'][6:]
	return None

def main():
	if len(sys.argv) !=2:
		print("Expecting name of the search parameter.")
		return
	if sys.argv[1].strip() == '':
		print("Need something to search.")
		return
	res_list = ['_'.join(sys.argv[1].split())]
	f_err = 0
	while res_list[len(res_list) - 1] != 'Philosophy':
		res = get_next_search(res_list[len(res_list) - 1])
		if res is None:
			print("It's a dead end!")
			f_err = 1
			break
		elif res in res_list:
			print("Found endless cycle (" + res + ")!")
			f_err = 1
			break
		res_list.append(res)
	if f_err:
		return
	for el in res_list:
		print(el.replace('_', ' '))
	print(len(res_list), "roads from", res_list[0].replace('_', ' '), "to", res_list[len(res_list) - 1], "!")

if __name__ == '__main__':
	main()