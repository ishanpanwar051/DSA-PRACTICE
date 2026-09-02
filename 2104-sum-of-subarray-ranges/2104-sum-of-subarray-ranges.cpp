class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int  n = nums.size();
        long long ans = 0;

        stack<int>st;

        for(int i=0;i<=n;i++){
            while(!st.empty() && (i == n || nums[st.top()]< nums[i])){
                int j  = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right =i ;
                ans +=1LL * nums[j] * (j-left) * (right -j);
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=0;i<=n;i++){
            while(!st.empty() && (i == n || nums[st.top()] > nums[i])){
                int j = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;

                ans -= 1LL * nums[j] * (j-left) * (right -j);
            }
            st.push(i);
        }
        return ans;
    }
};