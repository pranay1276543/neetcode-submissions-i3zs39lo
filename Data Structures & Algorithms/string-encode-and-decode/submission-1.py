class Solution:

    def encode(self, strs: List[str]) -> str:
        ans = ""

        for word in strs:
            ans+=str(len(word))
            ans+='#'
            ans+=word
        return ans

    def decode(self, s: str) -> List[str]:
        ans = []
        i=0
        word_len = ""
        while i<len(s):
            if s[i] == '#':
                ans.append(s[i+1:i+int(word_len)+1])
                i= i+int(word_len)+1
                word_len=""
            else:
                word_len+=s[i]
                i+=1  
            
        return ans    
            
