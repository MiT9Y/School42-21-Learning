from elem import Elem, Text

class Html(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='html', attr=attr, content=content, tag_type='double')

class Head(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='head', attr=attr, content=content, tag_type='double')

class Body(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='body', attr=attr, content=content, tag_type='double')

class Title(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='title', attr=attr, content=content, tag_type='double')

class Meta(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='meta', attr=attr, content=content, tag_type='simple')

class Img(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='img', attr=attr, content=content, tag_type='simple')

class Table(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='table', attr=attr, content=content, tag_type='double')

class Th(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='th', attr=attr, content=content, tag_type='double')

class Tr(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='tr', attr=attr, content=content, tag_type='double')

class Td(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='td', attr=attr, content=content, tag_type='double')

class Ul(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='ul', attr=attr, content=content, tag_type='double')

class Ol(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='ol', attr=attr, content=content, tag_type='double')

class Li(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='li', attr=attr, content=content, tag_type='double')

class H1(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='h1', attr=attr, content=content, tag_type='double')

class H2(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='h2', attr=attr, content=content, tag_type='double')

class P(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='p', attr=attr, content=content, tag_type='double')

class Div(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='div', attr=attr, content=content, tag_type='double')

class Span(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='span', attr=attr, content=content, tag_type='double')

class Hr(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='hr', attr=attr, content=content, tag_type='simple')

class Br(Elem):
	def __init__(self, content=None, attr={} ):
		Elem.__init__(self, tag='br', attr=attr, content=content, tag_type='simple')

def main():
	html = Html()
	html.add_content([
		Head(Title(Text('"Hello ground!"'))), 
		Body([
			H1(Text('"Oh no, not again!"')),
			Img(attr={'src':'http://i.imgur.com/pfp3T.jpg'})
		])
	])
	print(html)
"""	
	print(Html([Hr(), Text('Test')], {'attr':'test'}))
	print(Head([Hr(), Text('Test')], {'attr':'test'}))
	print(Body([Hr(), Text('Test')], {'attr':'test'}))
	print(Meta([Hr(), Text('Test')], {'attr':'test'}))
	print(Img([Hr(), Text('Test')], {'attr':'test'}))
	print(Table([Hr(), Text('Test')], {'attr':'test'}))
	print(Th([Hr(), Text('Test')], {'attr':'test'}))
	print(Tr([Hr(), Text('Test')], {'attr':'test'}))
	print(Td([Hr(), Text('Test')], {'attr':'test'}))
	print(Ul([Hr(), Text('Test')], {'attr':'test'}))
	print(Ol([Hr(), Text('Test')], {'attr':'test'}))
	print(Li([Hr(), Text('Test')], {'attr':'test'}))
	print(H1([Hr(), Text('Test')], {'attr':'test'}))
	print(H2([Hr(), Text('Test')], {'attr':'test'}))
	print(P([Hr(), Text('Test')], {'attr':'test'}))
	print(Div([Hr(), Text('Test')], {'attr':'test'}))
	print(Span([Hr(), Text('Test')], {'attr':'test'}))
	print(Hr([Hr(), Text('Test')], {'attr':'test'}))
	print(Br([Hr(), Text('Test')], {'attr':'test'}))
"""

if __name__ == '__main__':
	main()