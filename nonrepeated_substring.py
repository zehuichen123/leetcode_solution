# 最长子串长度

# 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

# 示例 1:

# 输入: "abcabcbb"
# 输出: 3 
# 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        def check(counter):
            for each_num in counter.values():
                if not (each_num == 0 or each_num == 1):
                    return False
            return True
        from collections import defaultdict
        max_dist = 0
        counter = defaultdict(lambda: 0)
        ptr1 = 0; ptr2 = 0
        while ptr2 <= len(s):
            while True:
                if ptr2 > len(s) -1:
                    break
                counter[s[ptr2]] += 1
                if check(counter):
                    ptr2 += 1
                else:
                    break
            if max_dist < ptr2 - ptr1:
                max_dist = ptr2 - ptr1
            if ptr2 > len(s) -1:
                break
            while True:
                counter[s[ptr1]] -= 1
                ptr1 += 1
                if check(counter):
                    break
            if ptr2 - ptr1 > max_dist:
                max_dist = ptr2 - ptr1
            ptr2 += 1
        return max_dist
