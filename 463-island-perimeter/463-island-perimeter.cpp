class Solution {
public: 
   
    int islandPerimeter(vector<vector<int>>& grid) {
        int count =0, rep =0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    count++;
                    if(i!=0 and grid[i-1][j] ==1 ) rep++;
                    if(j!=0 and grid[i][j-1] == 1) rep++;
                }
            }
        }
        return 4*count - 2*rep;
    }
};