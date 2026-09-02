class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>st;
        int ans =0;

        for(int i=0;i<=n;i++){
            int curr = (i == n ? 0 : heights[i]);
            while(!st.empty() && heights[st.back()] > curr){
                int h = heights[st.back()];
                st.pop_back();

                int left = st.empty() ? -1 :st.back();
                int width = i - left - 1;

                ans = max(ans, h*width);
            }
            st.push_back(i);
        }
        return ans;
    }
};