class Solution:
  def partition(self, nums: list, left: int, right: int, pivot: int):
    while left <= right:
      while nums[left] < pivot:   # '<' for ascending order and '>' for descending
        left += 1
       while nums[right] > pivot: # '>' for ascending order and '<' for descending
        right -= 1
       if left <= right:
        nums[left], nums[right] = nums[right], nums[left]
        left += 1
        right -= 1
    return left

  def quick_sort(self, nums: list[int], left: int, right: int) -> None:
    if left >= right: return
    pivot = nums[(left + right) // 2]
    position = self.partition(nums, left, right, pivot)
    self.quick_sort(nums, left, position - 1)
    self.quick_sort(nums, position, right)
  

def main():
  nums = [3,4,1,5,9,8]
  obj = Solution()
  obj.quick_sort(nums, 0, len(nums) - 1)
  # sorted list
  print(nums)
