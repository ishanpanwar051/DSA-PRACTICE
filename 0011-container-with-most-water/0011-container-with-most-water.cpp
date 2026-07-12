class Solution {
public:
    int maxArea(vector<int>& height) {
       int left = 0;
       int right =height.size()-1;
       int area = 0;
       int width =0;
       int h =0;

       while(left<right){
width  = right -left;
h = min(height[right],height[left]);
int curr_area  = width*h;
if(height[left]<height[right])left++;
else right--;
if(curr_area>area) area = curr_area;
       }
        return area;
    }
   
};