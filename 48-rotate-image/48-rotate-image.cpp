class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        reverse(m.begin(), m.end());
        int rows = m.size(), cols = m[0].size();
        for(int i=0;i<rows;i++)
        {
            for(int j = i+1;j<cols;j++)
            {
                swap(m[i][j], m[j][i]);
            }
        }
    }
};