class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int>mp;
    // Count frequency
    for (auto x : s) {
        mp[x]++;
    }

    // Find first character with frequency 1
    for (int i = 0; i < s.length(); i++) {
        if (mp[s[i]] == 1) {
            return i;
        }
    }

    return -1;
    }
};