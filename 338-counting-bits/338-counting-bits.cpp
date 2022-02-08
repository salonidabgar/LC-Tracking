class Solution {
public:
    
    vector<int> countBits(int n) {
//       int count=0;

//     vector<int>ans;
//     for(int i=0;i<=num;i++)
//     {
//         count=0;
//         for(int j=i;j>0;)
//         {
//             j=j&(j-1);
//             count++;
//         }
//          ans.push_back(count);
//     }
//     return ans;
        
        
        vector<int> res(n+1,0);
        for(int i=1;i<=n;i++)
        {
            res[i] = res[i &(i-1)] +1;
        }
        return res;
    }
};