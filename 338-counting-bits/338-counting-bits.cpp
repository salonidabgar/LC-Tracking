class Solution {
public:
    
    vector<int> countBits(int num) {
      int count=0;

    vector<int>ans;
    for(int i=0;i<=num;i++)
    {
        count=0;
        for(int j=i;j>0;)
        {
            j=j&(j-1);
            count++;
        }
         ans.push_back(count);
    }
    return ans;
    }
};