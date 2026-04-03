class Solution:
    def isPalindrome(self, s: str) -> bool:
        left = 0
        right = len(s)-1

        while left < right:
            a = s[left]
            b = s[right]
            while not a.isalnum() and left < right:
                left+=1
                a = s[left]
            while not b.isalnum() and left < right:
                right-=1
                b = s[right]
            if a.lower() != b.lower():
                return False
            left+=1
            right-=1
        return True
        