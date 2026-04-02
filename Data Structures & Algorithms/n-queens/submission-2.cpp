class Solution {
public:
    bool safe(vector<string>& str,int i,int j,int n){

        for(int k=0;k<i;k++){
            if(str[k][j] == 'Q'){
                return false;
            }
        }
        int a=i,b=j;

        while(a>=0 && b>=0){
            if(str[a][b] == 'Q') return false;
            a--;
            b--;
        }
        a=i;
        b=j;
        while(a>=0 && b<n){
            if(str[a][b] == 'Q') return false;
            a--;
            b++;
        }
        return true;
    }

    void solve(vector<vector<string>>& ans,vector<string>& str,int i,int n){
        if(i == n){
            ans.push_back(str);
            return ;
        }

        for(int k=0;k<n;k++){
            if(safe(str,i,k,n)){
                str[i][k]='Q';
                solve(ans,str,i+1,n);
                str[i][k]='.';
            }
        }
        
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> str(n,string(n,'.'));
        solve(ans,str,0,n);
        return ans;
    }
};
