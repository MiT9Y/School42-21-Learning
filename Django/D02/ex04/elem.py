#!/usr/bin/python3

class Text(str):
	def __str__(self):
		val = super().__str__()
		val = val.replace('<', "&lt;")
		val = val.replace('>', "&gt;")
		val = val.replace('"', "&quot;")
		return val.replace('\n', '\n<br />\n')

class Elem:
	def __init__(self, tag='div', attr={}, content=None, tag_type='double'):
		if not Elem.check_type(content) and not isinstance(content, None.__class__):
			raise Elem.ValidationError
		if not isinstance(attr, dict):
			raise Elem.ValidationError
		self.tag_type = tag_type
		self.indent_level = 0
		if isinstance(content, None.__class__):
			self.content = []
		else:
			self.content = [content] if not isinstance(content, list) else content
		self.attr = attr
		self.tag = tag

	def __str__(self):
		result = ''
		if self.tag_type == 'double':
			result += "<" + str(self.tag) + self.__make_attr() + ">"
			result += self.__make_content()
			result += "</" + str(self.tag) + ">"
		elif self.tag_type == 'simple':
			result += "<" + str(self.tag) + self.__make_attr() + " />"
		return result

	def __make_attr(self):
		result = ''
		for pair in sorted(self.attr.items()):
			result += ' ' + str(pair[0]) + '="' + str(pair[1]) + '"'
		return result

	def __make_content(self):
		if len(self.content) == 0:
			return ''
		result = '\n'
		for elem in self.content:
			if elem != '':
				result += '  ' + str(elem).replace('\n', '\n  ') + '\n'
		return result if result != '\n' else ''

	def add_content(self, content):
		if not Elem.check_type(content):
			raise Elem.ValidationError
		if type(content) == list:
			self.content += [elem for elem in content if elem != Text('')]
		elif content != Text(''):
			self.content.append(content)

	@staticmethod
	def check_type(content):
		return (isinstance(content, Elem) or type(content) == Text or
				(type(content) == list and all([type(elem) == Text or
												isinstance(elem, Elem)
												for elem in content])))

	class ValidationError(Exception):
		def __init__(self):
			Exception.__init__(self, "Error of validation content.")

def main():
	html = Elem(tag='html')
	head = Elem(tag='head', content=Elem(tag='title', content=Text('"Hello ground!"')))
	body = Elem(tag='body', content=[Elem(tag='h1', content=Text('"Oh no, not again!"'))])
	body.add_content(Elem(tag='img', tag_type='simple', attr={'src':'http://i.imgur.com/pfp3T.jpg'}))
	html.add_content([head,body])
	print(html)

if __name__ == '__main__':
	main()
