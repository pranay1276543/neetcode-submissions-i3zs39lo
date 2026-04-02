class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_arr(26,0),t_arr(26,0);
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0 ;i<s.size();i++){
            s_arr[s[i]-'a']++;
            t_arr[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(s_arr[i] != t_arr[i]){
                return false;
            }
        }
        return true;
    }
};
