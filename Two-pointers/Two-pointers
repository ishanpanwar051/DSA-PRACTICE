#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int water =0;
        int left =0;
        int right =n-1;
        
        while(left<right){
            water =max(water,min(height[left],height[right]) *(right-left));
           
            if(height[left]<height[right])left++;
            else right--;
 
        }
        return water;
    }
};

int main(){

    int n;
    cout<<"enter the size";
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
 Solution sol;
    cout << sol.maxArea(v);
}