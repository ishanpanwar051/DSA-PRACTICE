class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> common(26, 100);

        for (string word : words) {
            vector<int> freq(26, 0);

            for (char c : word) {
                freq[c - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                common[i] = min(common[i], freq[i]);
            }
        }

        vector<string> ans;

        for (int i = 0; i < 26; i++) {
            while (common[i] > 0) {
                ans.push_back(string(1, 'a' + i));
                common[i]--;
            }
        }

        return ans;
    }
};