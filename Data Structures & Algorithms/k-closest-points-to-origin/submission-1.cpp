class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
        pair<int,vector<int>>,
        vector<pair<int,vector<int>>>,
        greater<pair<int,vector<int>>>
        > pq;
        for(int i = 0;i<points.size();i++){
            int x,y;
            x = points[i][0];
            x=x*x;
            y = points[i][1];
            y=y*y;

            pq.push({x+y,points[i]});
        }
        vector<vector<int>>ans;
        for(int i = 0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
