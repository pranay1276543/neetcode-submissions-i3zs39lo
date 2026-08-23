class Solution {
public:
    int solve(const string &s,int i,vector<int>& dp){
        if(i == s.size()){
            return 1;
        }
        if(i>s.size() || s[i] == '0'){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int single = solve(s,i+1,dp);
        int d = 0;

        if((s[i] == '2' && s[i+1]<='6' && s[i]>=0) || s[i] == '1'){
            d = solve(s,i+2,dp);
        }

        return dp[i] = single + d;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+2,-1);
        return solve(s,0,dp);
    }
};
