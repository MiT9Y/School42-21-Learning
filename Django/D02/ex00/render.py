import sys, os, re

def parser_settings(data):
	res = {}
	lines = data.split('\n')
	for line in lines:
		if line.strip() != '':
			tmp = line.split('=')
			res[tmp[0].strip()] = tmp[1].strip()[1:-1]
	return res

def get_html_content(setting_dict, template):
	for key, val in setting_dict.items():
		template = re.sub('\{' + key + '\}', val, template)
	return template

def main(settings_file):
	if len(sys.argv) != 2:
		print("Wrong number of arguments. Expected: render.py file_name")
		return
	input_file_name = os.path.splitext(sys.argv[1])
	if input_file_name[1] != '.template':
		print("Invalid file extension, expected: *.template")
		return
	if os.access(sys.argv[1], os.R_OK) == False: 
		print("Input file:", '"' + sys.argv[1] + '"', "not found or not open for read")
		return
	if os.access(settings_file, os.R_OK) == False: 
		print("Settings file:", '"' + settings_file + '"', "not found or not open for read")
		return
	f = open(settings_file, 'r')
	settings_content = f.read()
	f.close()
	f = open(sys.argv[1], 'r')
	template_content = f.read()
	f.close()
	settings_dict = parser_settings(settings_content)
	try:
		f= open(input_file_name[0] + ".html", "w")
		f.write(get_html_content(settings_dict, template_content))
		f.close()
	except BaseException as e:
		print(e)

if __name__ == '__main__':
	main("settings.py")