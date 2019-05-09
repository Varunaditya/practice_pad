""""
Write an algorithm to justify text. Given a sequence of words and an integer line length k, return a list of strings
which represents each line, fully justified. More specifically, you should have as many words as possible in each line.
There should be at least one space between each word. Pad extra spaces when necessary so that each line has exactly
length k. Spaces should be distributed as equally as possible, with the extra spaces, if any, distributed starting from
the left. If you can only fit one word on a line, then you should pad the right-hand side with spaces.
Each word is guaranteed not to be longer than k.
For example, given the list of words ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"]
and k = 16, you should return the following:
["the  quick brown", # 1 extra space on the left
"fox  jumps  over", # 2 extra spaces distributed evenly
"the   lazy   dog"] # 4 extra spaces distributed evenly
"""


def handle_spaces(words: list, k: int) -> str:
    n_words = sum([len(i) for i in words])
    filler = (k - n_words)
    if len(words) == 1:
        return words[0] + ' ' * filler
    divider = len(words) - 1
    while filler > 0:
        words[filler % divider] += ' '
        filler -= 1
    return ''.join(words)


def justify(words: list, k: int) -> list:
    just_list, temp_str = list(), str()
    for word in words:
        if len(word) + len(temp_str) < k:
            temp_str += f'{word} '
            word_added = True
        else:
            temp_str = handle_spaces(temp_str.strip().split(' '), k)
            word_added = False
        if len(temp_str) >= k:
            just_list.append(temp_str)
            if not word_added:
                temp_str = f'{word} '
            else:
                temp_str = ''
    just_list.append(handle_spaces(temp_str.strip().split(' '), k))
    return just_list


def main():
    words = ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"]
    text1 = "Write an algorithm to justify text. Given a sequence of words and an integer line length k, return a " \
           "list of strings which represents each line, fully justified. More specifically, you should have as " \
           "many words as possible in each line.There should be at least one space between each word. Pad extra " \
           "spaces when necessary so that each line has exactly length k. Spaces should be distributed as equally " \
           "as possible, with the extra spaces, if any, distributed starting from the left. If you can only fit " \
           "one word on a line, then you should pad the right-hand side with spaces. Each word is guaranteed not " \
           "to be longer than k."
    justified_text = justify(text1.split(), k=50)
    for i in justified_text:
        print(i)


if __name__ == "__main__":
    main()
