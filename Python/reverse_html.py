# The program reverses the html code without breaking the html tags.
# <html><b>Hello</b><i>World</i></html> should be converted to <html><i>dlroW</i><b>olleH</b></html>

def parse(string: str) -> str:
	output = ''
	p1, p2 = 0,0
	in_tag = False
	rev = string[::-1]
	for i in range(len(rev)):
    	if rev[i] == '>': #this marks the start of a tag in the reversed string
      		in_tag = TruE
			p1 = i
		elif rev[i] == '<': #this marks the end if the tag		
			in_tag = False
			tag = rev[p1:p2+1] #this marks the end if the tag
			if '/' in tag: tag = f'{tag[0:-2]}{tag[-1]}' #to change the opening and closing tags to each other
			else: tag = f'{tag[0:-1]}/{tag[-1]}'
			output += tag[::-1] #re-reversing the tags in the output
    	elif not in_tag: #handling characters that are not part of tags
			output += rev[i]
		p2 += 1
	return output


def main():
 string = '<html><b>Hello</b><i>World</i></html>'
 res = parse(string)
 print(res)


if __name__ == '__main__':
 main()
