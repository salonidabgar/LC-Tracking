class Solution {
public:
    string SCS(string s1, string s2, int l1, int l2)
    {
        vector<vector<int>> dp(l1+2, vector<int>(l2+2,0));
        
        for(int i=0;i<=l1;i++)
        {
            for(int j=0;j<=l2;j++)
            {
                if(i==0 or j==0) dp[i][j] = 0;
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // cout << dp[l1][l2]<< endl;
        string ans = "";
        int i = l1, j = l2;
        while(i>0 and j>0)
        {
                if(s1[i-1] == s2[j-1])
                {
                    ans.push_back(s1[i-1]);
                    i = i-1;
                    j = j-1;
                    // continue;
                }
                else
                {
                    
                    if(dp[i-1][j] > dp[i][j-1])
                    {
                        ans.push_back(s1[i-1]);
                        i = i-1;
                        // continue;
                    }
                    else
                    {
                        ans.push_back(s2[j-1]);
                        j = j-1;
                        // continue;
                    }
                }
            }
        
        while(i>0)
        {
            ans.push_back(s1[i-1]);
            i--;
        }
        while(j>0)
        {
            ans.push_back(s2[j-1]);
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string shortestCommonSupersequence(string s1, string s2) {
        // return SCS(s1, s2, s1.length(), s2.length());
        
        int n=s1.size(); 
        int m=s2.size();
        int t[n+1][m+1]; //table generated while computing LCS length
        string res; // result	
        // compute LCS length using tabulation      
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
                t[i][j]=0;
            else if(s1[i-1]==s2[j-1])
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else
            {
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }     
       //print lcs
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            res.push_back(s1[i-1]);
            i--;
            j--;
        }
        else
        {
            if(t[i-1][j]>t[i][j-1])
            {
                res.push_back(s1[i-1]);
                i--;
            } else{
                res.push_back(s2[j-1]);
                j--;
            }
        }
    }
    while(i>0) // if s1 characters are still left
    {
        res.push_back(s1[i-1]);
        i--;
    }
    while(j>0) //if s2 characters are still left
    {
        res.push_back(s2[j-1]);
        j--;
        
    }
        reverse(res.begin(),res.end()); 
        return res;
    }
};