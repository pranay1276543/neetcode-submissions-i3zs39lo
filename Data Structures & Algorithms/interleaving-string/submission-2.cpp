class Solution {
public:
    int solve(string s1, string s2, string s3,int i,int j,int k,vector<vector<vector<int>>>& dp){
        if(k ==s3.size() && i==s1.size() && j==s2.size()){
            return 1;
        }

        if(k>=s3.size()){
            return 0;
        }
        if(dp[k][i][j] != -1){
            return dp[k][i][j];
        }
        int a=0,b=0;
        if(s3[k] == s1[i]){
            a = solve(s1,s2,s3,i+1,j,k+1,dp);
        }
        if(s3[k] == s2[j]){
            b = solve(s1,s2,s3,i,j+1,k+1,dp);
        }

        return dp[k][i][j] = max(a,b);
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>> dp(s3.size()+1,vector<vector<int>>(s1.size()+1,vector<int>(s2.size()+1,-1)));
        return solve(s1,s2,s3,0,0,0,dp);
    }
};
