def insert_el_in_list(l, insert_val, index = -1):
	if type(l) is list:
		len_list = len(l)
		if index == -1 or index == len_list:
			l.append(insert_val)
		elif index < len_list:
			l[index] = insert_val
		else:
			while len_list < index:
				l.append(None)
				len_list = len_list + 1
			l.append(insert_val)

def get_html(data):
	if type(data) is not list:
		return ''
	res = '<!DOCTYPE html>\n'
	res = res + '<html lang="en">\n'
	res = res + '<head>\n'
	res = res + '<meta charset="utf-8">'
	res = res + '<title>Periodic table</title>\n'
	res = res + '<style>\n'
	res = res + 'table {border-collapse: collapse; margin: auto; table-layout: fixed; width: 2160px}\n'
	res = res + 'td {border: 1px solid black;}\n'
	res = res + 'th {padding: 10px;}\n'
	res = res + 'li {list-style-type: none;}\n'
	res = res + 'ul {margin-left: 10px;padding-left: 10px;}\n'
	res = res + 'h4 {display: block;text-align: center;}\n'
	res = res + '</style>\n'
	res = res + '</head>\n'
	res = res + '<body>\n'
	res = res + '<table>\n'
	res = res + '<tr><th colspan="18">GROUPS</th></tr>\n'
	res = res + '<tr><th>1</th><th>2</th><th>3</th><th>4</th><th>5</th><th>6</th><th>7</th><th>8</th><th>9</th><th>10</th><th>11</th><th>12</th><th>13</th><th>14</th><th>15</th><th>16</th><th>17</th><th>18</th></tr>\n'
	index = 0
	i = 0
	while i < len(data):
		if data[i] is not None:
			data[i].append(str(i + 1))
			while index != data[i][1]:
				if index == 0:
					res = res + '<tr>'
				res = res + '<td></td>'
				index = index + 1
				if index == 18:
					res = res + '</tr>\n'
					index = 0
			if index == 0:
				res = res + '<tr>'
			res = res + '<td><h4>' + data[i][0] + '</h4><ul>'
			res = res + '<li>No ' + data[i][4] + '</li>'
			res = res + '<li>' + data[i][2] + '</li>'
			res = res + '<li>' + data[i][3] + '</li></ul></td>'
			index = index + 1
			if index == 18:
				res = res + '</tr>\n'
				index = 0
		i = i + 1
	while index != 0:
		res = res + '<td></td>'
		index = index + 1
		if index == 18:
			res = res + '</tr>\n'
			index = 0
	res = res + '</table>\n</body>\n</html>'
	return res

def get_data():
	res = []
	f = open("periodic_table.txt", "r")
	content = f.read()
	f.close()
	content = content.split('\n')
	for str_data in content:
		str_data = str_data.strip()
		if str_data != '':
			line_data = str_data.split(',')
			index = line_data[1].split(':')
			try:
				index = int(index[1])
				val = ['', '', '' , '']
				tmp = line_data[0].split('=')
				val[0] = tmp[0].strip()
				tmp = tmp[1].split(':')
				val[1] = int(tmp[1].strip())
				tmp = line_data[2].split(':')
				val[2] = tmp[1].strip()
				tmp = line_data[3].split(':')
				val[3] = tmp[1].strip()
				insert_el_in_list(res, val, index - 1)
			except:
				pass
	return res

def main():
	try:
		src_dict = get_data()
		f= open("periodic_table.html","w")
		f.write(get_html(src_dict))
		f.close()

	except BaseException as e:
		print(e)

if __name__ == '__main__':
	main()