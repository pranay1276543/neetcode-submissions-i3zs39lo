class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int start = 0,ans = 0;
        for(int i=0;i<s.size();i++){
            if(map.contains(s[i])){
                start = max(start,map[s[i]]+1);
            }
            map[s[i]] = i;
            ans = max(ans,i-start+1);
        }
        return ans;
    }
};
