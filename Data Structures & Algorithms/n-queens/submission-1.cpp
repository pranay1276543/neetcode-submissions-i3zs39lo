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

    void solve(vector<vector<string>>& ans,vector<string>& str,int i,int j,int n){
        if(j == n) return ;
        if(i == n){
            ans.push_back(str);
            return ;
        }

        bool check = safe(str,i,j,n);

        if(check){
            str[i][j] = 'Q';
            solve(ans,str,i+1,0,n);
            str[i][j]='.';
        }
        solve(ans,str,i,j+1,n);
        
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> str(n,string(n,'.'));
        solve(ans,str,0,0,n);
        return ans;
    }
};
