class Solution {
public:

    bool canEat(vector<int>& piles, int h, int k){
        long long hours = 0;

        for(int pile : piles){
            hours += (pile + k - 1) / k;   // ceil(pile/k)
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = end;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(canEat(piles, h, mid)){
                ans = mid;
                end = mid - 1;   // try smaller speed
            }
            else{
                start = mid + 1; // increase speed
            }
        }

        return ans;
    }
};