"""
Given a multiset of integers, return whether it can be partitioned into two subsets whose sums are the same.
For example, given the multiset {15, 5, 20, 10, 35, 15, 10}, it would return true, since we can split it up 
into {15, 5, 10, 15, 10} and {20, 35}, which both add up to 55. Given the multiset {15, 5, 20, 10, 35}, it 
would return false, since we can't split it up into two subsets that add up to the same sum.
"""


#!/usr/bin/python3

def can_be_divided(nums: list) -> bool:
    nums = sorted(nums)
    target_sum = sum(nums) / 2
    curr_sum = 0
    for i in nums:
        if curr_sum + i <= target_sum:
            curr_sum += i
    return False if curr_sum != target_sum else True



def main():
    nums = [15, 5, 20, 10, 35, 15, 10]
    res = can_be_divided(nums)
    print(f'Can Be Divided: {res}')


if __name__ == '__main__':
    main()
