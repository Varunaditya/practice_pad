#!/bin/python3
"""
A newly opened multinational brand has decided to base their company logo on the three most common characters in the company name. They are now trying out various combinations of company names and logos based on this condition. Given a string , which is the company name in lowercase letters, your task is to find the top three most common characters in the string.

* Print the three most common characters along with their occurrence count.
* Sort in descending order of occurrence count.
* If the occurrence count is the same, sort the characters in alphabetical order.
"""


def counter(letters):
    dict_count = dict()
    for letter in letters:
        if letter not in dict_count:
            dict_count[letter] = 1
        else:
            dict_count[letter] += 1
    new_dict = dict()
    for letter, count in dict_count.items():
        if count not in new_dict:
            new_dict[count] = [letter]
        else:
            target_list = new_dict[count]
            target_list.append(letter)
            new_dict[count] = target_list
    return new_dict

def get_top_letters(string):
    letter_count = counter(string)
    sorted_letters_wc = sorted(letter_count.items(), key = lambda x: -x[0])
    count = 0
    flag = 0
    for combo in sorted_letters_wc:
        occur = combo[0]
        sorted_letters = sorted(combo[1])
        for letter in sorted_letters:
            if count < 3:
                print(letter +' '+str(occur))
                count += 1
            elif count >= 3:
                flag = 1
                break
        if flag:
            break


if __name__ == '__main__':
    s = input()
    get_top_letters(s)
