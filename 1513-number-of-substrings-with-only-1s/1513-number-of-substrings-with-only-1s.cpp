class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;


        long long ans =0;
        long long count =0;


        for (char ch: s){
            if(ch == '1'){
                count++;
                ans = (ans + count) % MOD;
            }
            else{
                count =0;
            }
        }
    return ans;

    }
};