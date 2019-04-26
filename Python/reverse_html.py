# The program reverses the html code without breaking the html tags.
# <html><b>Hello</b><i>World</i></html> should be converted to <html><i>dlroW</i><b>olleH</b></html>

def parse(string: str) -> str:
	output = ''
	p1, p2 = 0,0
	in_tag = False
	rev = string[::-1]
	for i in range(len(rev)):
		#this marks the start of a tag in the reversed string
    if rev[i] == '>':
			#to keep a check whether a non-tag character is part of the tag or not
      in_tag = True
      #to slice the tags from the strings
			p1 = i		
    #this marks the end if the tag
		elif rev[i] == '<':		
			in_tag = False
      #slicing the tags from the string
			tag = rev[p1:p2+1]
      #to change the opening and closing tags to each other
			if '/' in tag: tag = f'{tag[0:-2]}{tag[-1]}'
			else: tag = f'{tag[0:-1]}/{tag[-1]}'
			#re-reversing the tags in the output
      output += tag[::-1]
		#handling characters that are not part of tags
    elif not in_tag:
			output += rev[i]
		p2 += 1
	return output


def main():
 string = '<html><b>Hello</b><i>World</i></html>'
 res = parse(string)
 print(res)


if __name__ == '__main__':
 main()
