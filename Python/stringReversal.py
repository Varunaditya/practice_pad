"""
Given a string and a set of delimiters, reverse the words in the string while 
maintaining the relative order of the delimiters. 
For example, given "hello/world:here", return "here/world:hello"
"""

from sys import argv, exit


alphabets = ['a', 'b', 'c', 'd', 'e',
			 'f' , 'g', 'h', 'i', 'j',
			 'k', 'l', 'm', 'n', 'o', 
			 'p', 'q', 'r', 's', 't', 
			 'u', 'v', 'w', 'x', 'y', 'z']


def delims_handler(ch: str, delims: dict, wc: int) -> dict:
	if wc not in delims:
		delims[wc] = ch
 	else:
		delims[wc] += ch
 	return delims


def get_words_delims(inp: str) -> (list, dict):
	global alphabets
	prev_delim = False
	words, word, word_count = list(), str(), 0
	delims = dict()
	for char in inp:
		if char.lower() in alphabets:
			prev_delim = False
			word += char
		else:
			words.append(word)
   			word = str()
			if not prev_delim:
    			word_count += 1
				prev_delim = True
   			delims = delims_handler(char, delims, word_count)
	if word:
		words.append(word)
	return (words, delims)


def rearr(inp: str) -> str:
	words, delims = get_words_delims(inp)
	output = str()
	word_count = 0
	for word in words[::-1]:
		if word_count in delims:
			output += delims[word_count]
			output += word
		word_count += 1
	if word_count in delims:
		output += delims[word_count]
	return output


def main():
	if len(argv) <= 1 : 
	print('No Input!')
	exit(-1)
inp = argv[1]
new_sent = rearr(inp)
print(new_sent)


if __name__ == '__main__':
	main()

