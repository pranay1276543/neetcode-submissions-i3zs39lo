class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& curr, vector<int>& nums,int i,int n){
        //base case
        if(i == n){
            ans.push_back(curr);
            return ;
        }
        curr.push_back(nums[i]);
        solve(ans,curr,nums,i+1,n);
        curr.pop_back();
        solve(ans,curr,nums,i+1,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;\
        solve(ans,curr,nums,0,nums.size());
        return ans;
    }
};
