class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}
        for i in range(len(nums)):
            check = map.get(target - nums[i])
            if check != None:
                return [check,i]
            map[nums[i]] = i
            

        