"""
Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come
first, the Gs come second, and the Bs come last. You can only swap elements of the array.
Do this in linear time and in-place.
For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
"""


def swap(l: list, p1: int, p2: int, let: str) -> tuple:
    counter = 0
    if p1 > 0:
        while l[p1] == 'R':
            p1 += 1
    while p1 < p2:
        if l[p1] != let:
            if l[p2] != let:
                p2 -= 1
            elif l[p2] == let:
                l[p1], l[p2] = l[p2], l[p1]
                p1 += 1
                p2 -= 1
                counter += 1
        elif l[p1] == let:
            p1 += 1
            counter += 1
    return l, counter


def arrange(l: list) -> list:
    p1, p2 = 0, len(l) - 1
    l, counter = swap(l, p1, p2, 'R')
    l, counter = swap(l, counter, p2, 'G')
    return l


def main():
    letters = ['G', 'B', 'R', 'R', 'B', 'R', 'G']
    ans = arrange(letters)
    print(ans)


if __name__ == "__main__":
    main()

