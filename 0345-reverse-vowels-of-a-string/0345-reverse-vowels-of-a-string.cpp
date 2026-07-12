class Solution {
public:

bool isvowel(char ch){
 ch = tolower(ch);
if(ch == 'a'||ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u') return true;
else
return false;
        
    }
    string reverseVowels(string s){
        int left = 0;
        int right=s.size()-1;
        while(left<right){
            if(!isvowel(s[left]))left++;
            else if (!isvowel(s[right])) right--;
            else {
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};