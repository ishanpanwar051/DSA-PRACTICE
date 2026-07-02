class Solution {
public:
    int longestWPI(vector<int>& hours) {

        unordered_map<int,int> mp;

        int prefix = 0;
        int ans = 0;

        for(int i = 0; i < hours.size(); i++) {

            if(hours[i] > 8)
                prefix += 1;
            else
                prefix -= 1;

            if(prefix > 0) {

                ans = i + 1;

            } else {

                if(mp.count(prefix - 1))
                    ans = max(ans, i - mp[prefix - 1]);
            }

            if(!mp.count(prefix))
                mp[prefix] = i;
        }

        return ans;
    }
};