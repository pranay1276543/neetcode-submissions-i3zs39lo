class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        ans = {}

        for str in strs:
            check = [0]*26
            for i in range(len(str)):
                check[ord(str[i])-ord('a')]+=1
            
            key = tuple(check)
            ans[key] = ans.get(key,[]) + [str]

        return list(ans.values())