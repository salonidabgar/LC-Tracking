class Solution {
public:
    // void makeZero(int r, int c, vector<vector<int>> &m)
    // {
    //     for(int i = r-1 ;i>=0;i--)
    //     {
    //         m[i][c] = 0;
    //     }
    //     for(int i = r+1;i< m.size();i++)
    //     {
    //         m[i][c] = 0;
    //     }
    //     for(int j =c+1;j<m[0].size();j++)
    //     {
    //         m[r][j] = 0;
    //     }
    //     for(int j = c-1;j>=0; j--)
    //     {
    //         m[r][j] = 0;
    //     }
    // }
    void setZeroes(vector<vector<int>>& m) {
        int rows = m.size(), cols = m[0].size();
        bool col = false, row =false;
        for(int i =0;i<rows;i++)
        {
            for(int j = 0;j< cols;j++)
            {
                if(m[i][j] == 0)
                {
                    if(i ==0) row = true;
                    if(j ==0) col = true;
                    m[i][0] = 0;
                    m[0][j] =0;
                }
            }
        }
        
        for(int i = 1;i<rows;i++)
        {
            for(int j =1;j<cols;j++)
            {
                if(m[i][0] == 0 || m[0][j] == 0)
                {
                    m[i][j] = 0;
                }
            }
        }
        if(row)
        {
            for(int j = 0;j<cols;j++)
            {
                m[0][j] = 0;
            }
        }
        
        if(col)
        {
            for(int i = 0;i<rows;i++)
            {
                m[i][0] = 0;
            }
        }
    }
};