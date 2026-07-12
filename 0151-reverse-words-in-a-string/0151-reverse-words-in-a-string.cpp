class Solution {
public:
    void reverse(string &s, int i, int j) {
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    string reverseWords(string s) {
        int n = s.size();

        // Step 1: Remove extra spaces
        int i = 0, j = 0;
        while (j < n) {
            while (j < n && s[j] == ' ') j++;
            while (j < n && s[j] != ' ') s[i++] = s[j++];
            while (j < n && s[j] == ' ') j++;
            if (j < n) s[i++] = ' ';
        }
        s.resize(i);

        // Step 2: Reverse whole string
        reverse(s, 0, s.size() - 1);

        // Step 3: Reverse each word
        int start = 0;
        for (int end = 0; end <= s.size(); end++) {
            if (end == s.size() || s[end] == ' ') {
                reverse(s, start, end - 1);
                start = end + 1;
            }
        }

        return s;
    }
};