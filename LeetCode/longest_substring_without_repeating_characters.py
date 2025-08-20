class Solution:
  def lengthOfLongestSubstring(self, s: str) -> int:
    if s == "":
      return 0

    start = 0
    end = 0
    maxLength = 0
    characters = set()

    while end < len(s):
      if s[end] not in characters:
        characters.add(s[end])
        end += 1
        maxLength = max(maxLength, len(characters))
      else:
        characters.remove(s[start])
        start += 1
    return maxLength
