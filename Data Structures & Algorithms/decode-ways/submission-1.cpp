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
        // vector<int> dp(s.size()+2,-1);
        // return solve(s,0,dp);

        vector<int> dp(s.size()+2,0);
        dp[s.size()] = 1;

        for(int i=s.size()-1;i>=0;i--){
            int single = dp[i+1];
            int d=0;
            if(s[i] == '0'){
                dp[i] = 0;
                continue;
            }
            if((s[i] == '2' && s[i+1]<='6' && s[i+1]>='0') || s[i] == '1'){
                d = dp[i+2];
            }
            dp[i] = single + d;
        }
        return dp[0];
    }
};
