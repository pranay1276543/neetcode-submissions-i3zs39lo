class Solution {
public:
    void solve(vector<string>& ans,string str,int s,int e,int n){
        if(s == n && e == n){
            ans.push_back(str);
            return ;
        }
        if(s>n || e>n || e>s) return ;

        str+='(';
        solve(ans,str,s+1,e,n);
        str.pop_back();
        str+=')';
        solve(ans,str,s,e+1,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str="";
        solve(ans,str,0,0,n);
        return ans;
    }
};
