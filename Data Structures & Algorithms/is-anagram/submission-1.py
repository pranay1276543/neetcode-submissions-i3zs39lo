class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        check1 = [0]*26
        check2 = [0]*26

        if len(s) != len(t):
            return False
        for i in range(len(s)):
            check1[ord(s[i])-ord("a")]+=1
            check2[ord(t[i])-ord("a")]+=1

        return check1 == check2



        