class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int,int>>dq;

        int ans =INT_MIN;
        for(auto &p:points){
            int x =p[0];
            int y=p[1];

            while(!dq.empty() && x-dq.front().first>k)dq.pop_front();

            if(!dq.empty()) ans =max(ans,x+y+dq.front().second);

            int curr = y-x;
            
            
            while(!dq.empty() && dq.back().second<=curr)dq.pop_back();
            
            dq.push_back({x,curr});     
               }
               return ans;
    }
};