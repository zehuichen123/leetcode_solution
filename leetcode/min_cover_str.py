# 最小覆盖子串
# 给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串。

# 示例：

# 输入: S = "ADOBECODEBANC", T = "ABC"
# 输出: "BANC"
# 说明：

# 如果 S 中不存这样的子串，则返回空字符串 ""。
# 如果 S 中存在这样的子串，我们保证它是唯一的答案。

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        def check_covers(hash_table):
            for i in hash_table.values():
                if i > 0:
                    return False
            return True
        hash_table = dict()
        min_len = 1000000
        for each_word in t:
            if each_word not in hash_table.keys():
                hash_table[each_word] = 1
            else:
                hash_table[each_word] += 1
        ptr1 = 0
        ptr2 = 0
        while ptr2 != len(s):
            is_true = False
            # move ptr2
            while not check_covers(hash_table):
                if ptr2 >= len(s):
                    break
                if s[ptr2] in hash_table.keys():
                    hash_table[s[ptr2]] -= 1
                ptr2 += 1
            if check_covers(hash_table):
                is_true = True
            # move ptr1
            while check_covers(hash_table):
                if ptr1 >= len(s):
                    break
                if s[ptr1] in hash_table.keys():
                    hash_table[s[ptr1]] += 1
                ptr1 += 1 
            if is_true:
                curr_len = ptr2 - ptr1 + 1
                if curr_len < min_len:
                    min_ptr1 = ptr1
                    min_ptr2 = ptr2
                    min_len = curr_len
        if min_len == 1000000:
            return ""
        else:
            return s[min_ptr1-1:min_ptr2]