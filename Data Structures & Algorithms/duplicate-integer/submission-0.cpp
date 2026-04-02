class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i =0; i<nums.size();i++){
            if(map.contains(nums[i])){
                return true;
            }
            else{
                map[nums[i]] == 1;
            }
        }
        return false;
    }
};