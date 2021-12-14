class Solution {
public:
    string longestPalindrome(string s) {
          int i=0,j=0, n = s.length();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));        
      
    int index =0, len =1 ;
        
    for(int g = 0; g< n;g++)
    {
     for(int i=0,j=g;j<n;j++,i++)
        {
            if(g == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            
            else if(g == 1)
            {
                if(s[i]==s[j])
                {
                    index =i;
                    // g =2;
                    len =2 ;
                    dp[i][j]=1;
                }
            }
            else 
            {
                if(s[i]==s[j] && dp[i+1][j-1])
            {
                    index = i;
                    len = g+1;
                    dp[i][j]=1;
            }
            }
        }
    }
        
        // for(int i =0;i<n;i++)
        // {
        //     for(int j = i;j<n;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return s.substr(index, len);
    }
};