class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& nums,int start){
        if(start == nums.size()){
            ans.push_back(nums);
        }

        for(int i=start;i<nums.size();i++){
            swap(nums[i],nums[start]);
            solve(ans,nums,start+1);
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(ans,nums,0);
        return ans;
    }
};
