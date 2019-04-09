"""
3. Longest Substring Without Repeating Characters
Medium

5197

271

Favorite

Share
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
"""


class Solution:
    def lengthOfLongestSubstring(self, s):
        l1 = []
        count = 0
        for i, char in enumerate(s):
            if char in l1:
                count = max(len(l1), count)
                # 如果是第一个
                if l1[0] is char:
                    l1.remove(char)
                # 如果在末尾
                elif l1[len(l1) - 1] is char:
                    l1 = []
                # 如果在中间
                else:
                    l1 = l1[l1.index(char) + 1:]
            l1.append(char)
        return max(len(l1), count)


s = Solution()
print(s.lengthOfLongestSubstring("ckilbkd"))
