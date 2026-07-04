class Solution {
public:

bool ispalidorome(string&s , int left ,int right){

    while(left<right){
        if(s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}


    bool validPalindrome(string s) {
        int left =0;
        int right = s.size()-1;

        while(left<right){
            if(s[left] == s[right]){
left++;
right--;
            }
            else{
                return ispalidorome(s,left+1,right) || 
                ispalidorome(s,left,right-1);
            }
        }
        return true;
    }
};