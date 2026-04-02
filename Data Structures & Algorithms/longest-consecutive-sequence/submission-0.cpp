class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 || nums.size()==1){
            return nums.size();
        }
        unordered_set<int> set;
        int longest=1;
        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }
        for(int x:set){
            if(set.count(x-1)){
                continue;
            }
            int ans=1,curr=x+1;
            while(set.count(curr)){
                ans++;
                curr++;
            }
            longest = max(longest,ans);
        }
        return longest;
    }
};
