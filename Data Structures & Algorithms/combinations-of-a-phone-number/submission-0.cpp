class Solution {
public:
    unordered_map<char,string> map = {
        {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
        {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
    };

    void solve(vector<string>& ans,string digits,string curr,int start){
        if(start == digits.size()){
            ans.push_back(curr);
            return ;        
        }
        
        string s = map[digits[start]];

        for(int j=0;j<s.size();j++){
            solve(ans,digits,curr+s[j],start+1);
        } 
        
        
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string curr="";
        if(digits.size()==0) return ans;
        solve(ans,digits,curr,0);
        return ans;
    }
};
