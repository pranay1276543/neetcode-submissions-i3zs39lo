class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& curr,vector<int>& nums,int i,int sum,int tar){
        //base case
        if(i>=nums.size()){
            if(sum == tar) ans.push_back(curr);
            return ;
        }
        if(sum == tar){
            ans.push_back(curr);
            return ;
        }
        if(sum>tar) return ;

        curr.push_back(nums[i]);
        solve(ans,curr,nums,i,sum+nums[i],tar);
        curr.pop_back();
        solve(ans,curr,nums,i+1,sum,tar);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(ans,curr,nums,0,0,target);
        return ans;
    }
};
