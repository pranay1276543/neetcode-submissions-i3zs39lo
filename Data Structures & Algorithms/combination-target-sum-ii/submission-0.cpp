class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& curr,vector<int>& candidates,int start,int n,int sum,int target){
        //base case
        if(sum == target) {
            ans.push_back(curr);
            return ;
        }
        if(start==n || sum>target){
            return ;
        }

        for(int i=start;i<n;i++){

            if(i>start && candidates[i] == candidates[i-1]) {
                continue;
            }
            if(candidates[i] > target) break;
            curr.push_back(candidates[i]);
            solve(ans,curr,candidates,i+1,n,sum+candidates[i],target);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());

        solve(ans,curr,candidates,0,candidates.size(),0,target);
        return ans;
    }
};
