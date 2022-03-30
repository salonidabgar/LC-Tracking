class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag =0;
        cout<<m<<"space"<<n<<endl;
        int hi=n-1,lo=0,i;
        if(target < matrix[0][0] or target > matrix[m-1][n-1]  ) return false;
        for(i=0;i<m;i++)
        {
            cout<< matrix[i][0]<<" "<<matrix[i][n-1]<<endl;
            if(target >= matrix[i][0] and target <= matrix[i][n-1])
            {
                // cout<<i<<endl;
                flag = 1;
                break;
                
            }
        }
        if(!flag)
        {
           i--; 
        }
        while(lo<hi)
        {
            
            int mid = lo +(hi-lo)/2;
            cout<<hi<<" "<<lo<<" "<<mid<<endl;
            if(target== matrix[i][mid]) return true;
            else if(target<matrix[i][mid]) 
            {
                hi = mid;
            }
            else
            {
                lo = mid+1;
            }
            
        }
        return (matrix[i][lo]==target)?true:false;
    }
};