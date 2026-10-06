class Solution {
public:

void dfs(int r,int c , int oldColor,int newColor,vector<vector<int>>& image){
    int n  = image.size();
    int m = image[0].size();

    if(r<0 || c<0 || r>=n || c>=m) return;

    if(image[r][c] != oldColor) return;
    image[r][c] = newColor;


    dfs(r+1,c,oldColor,newColor,image);
    dfs(r-1,c,oldColor,newColor,image);
    dfs(r,c+1,oldColor,newColor,image);
    dfs(r,c-1,oldColor,newColor,image);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
int oldColor = image[sr][sc];
if(oldColor == color) return image;

dfs(sr,sc,oldColor,color,image);


return image;

    }
};