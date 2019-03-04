from itertools import combinations


def get_indices(string: str) -> dict:
    ret_dict = dict()
    for index, letter in enumerate(string):
        if letter not in ret_dict:
            ret_dict[letter] = [index]
        else:
            target_value = ret_dict[letter]
            target_value.append(index)
            ret_dict[letter] = target_value
    return ret_dict


def is_palindrome(string: str) -> bool:
    return string == string[::-1]


def get_substring(string: str) -> str:
    if string == string[::-1]:
        return string
    index_table = get_indices(string)
    ret_obj = list()
    for i in index_table.items():
        indices = [j for j in combinations(i[1], 2) if j[0] < j[1]]
        palindromes = [string[j[0]:j[1]+1] for j in indices if is_palindrome(string[i[0]:i[1]+1])]
        ret_obj.append(sorted(palindromes, key=lambda x: -len(x))[0])
    return sorted(ret_obj, key=lambda x: -len(x))[0]


def main():
    input_string = input()
    result = get_substring(input_string)
    print(result)


if __name__ == "__main__":
    main()
