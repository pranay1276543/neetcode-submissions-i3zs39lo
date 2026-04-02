class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left = [1]*len(nums)
        right = [1]*len(nums)
        n = len(nums)
        ans = []
        left_i = 1
        right_i = 1
        for i in range(n):
            left[i] = left_i
            left_i *= nums[i] 
            right[n-i-1] = right_i
            right_i *= nums[n-i-1]
        
        for i in range(n):
            ans.append(left[i]*right[i])

        return ans