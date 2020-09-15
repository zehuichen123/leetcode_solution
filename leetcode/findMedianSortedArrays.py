# 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

# 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

# 你可以假设 nums1 和 nums2 不会同时为空。

# 示例 1:

# nums1 = [1, 3]
# nums2 = [2]

# 则中位数是 2.0

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        all_arr = nums1 + nums2
        all_arr = sorted(all_arr)
        mid = int(len(all_arr) / 2)
        if len(all_arr) % 2 == 0:
            return (all_arr[mid-1] + all_arr[mid])/2
        else:
            return all_arr[mid]