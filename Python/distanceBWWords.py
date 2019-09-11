"""
Find an efficient algorithm to find the smallest distance (measured in number of words) between any two given words in
a string. For example, given words "hello", and "world" and a text content of "dog cat hello cat dog dog hello cat
world", return 1 because there's only one word "cat" in between the two words.
"""

def getDist(inp: str, w1: str, w2: str):
    _dist = float('inf')
    startPos = 0
    seenW1, seenW2 = False, False
    for index, word in enumerate(inp):
        if word == w1:
            seenW1 = True
            if seenW2:
                if (index - startPos - 1) < _dist:
                    _dist = index - startPos - 1
                    seenW2 = False
            startPos = index
        elif word == w2:
            seenW2 = True
            if seenW1:
                if (index - startPos - 1) < _dist:
                    _dist = index - startPos - 1
                    seenW1 = False
            startPos = index
    return _dist


def main():
    inp = ['dog', 'cat', 'hello', 'cat', 'dog', 'world', 'hello', 'cat', 'world', 'test']
    w1, w2 = 'hello', 'world'
    print(getDist(inp, w1, w2))


if __name__ == "__main__":
    main()
