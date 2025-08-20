class Solution:
  def singleNumber(self, nums: List[int]) -> int:
    if len(nums) == 1:
      return nums[0]
    
    repeatedNumbers = set()
    singleNumber = 0
    dic = dict()
    count = 0

    for number in nums:
      if not dic.get(number):
        dic[number] = 1
      else:
        dic[number] += 1
  
    for key in dic:
      if dic.get(key) == 1:
        singleNumber = key
    # find where the value is 1 and get the key.
    
    return singleNumber
