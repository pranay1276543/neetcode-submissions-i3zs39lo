class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& curr,vector<int>& nums,int start){
       
        ans.push_back(curr);

        for(int i = start;i<nums.size();i++){
            if(i>start && nums[i] == nums[i-1]) continue;

            curr.push_back(nums[i]);
            solve(ans,curr,nums,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(ans,curr,nums,0);
        return ans;
    }
};
