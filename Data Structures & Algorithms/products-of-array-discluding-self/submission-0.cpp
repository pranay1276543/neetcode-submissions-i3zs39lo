class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l=1,r=1,n=nums.size();
        vector<int> ans(n);
        vector<int> left(n);
        vector<int> right(n);
        for(int i=0;i<n;i++){
            left[i] = l;
            right[n-i-1]= r;
            l*=nums[i];
            r*=nums[n-i-1];
        }
        for(int i=0;i<n;i++){
            ans[i] = left[i]*right[i];
        }
        return ans;
    }
};
