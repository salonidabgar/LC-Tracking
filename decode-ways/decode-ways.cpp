class Solution {
public:
    int numDecodings(string A) {
        const int N = 1000000007;

    int n = A.length();
    if(n==0) return 0;
    // if(n==2) return ((1<=('A' - 64)<=26) ? 2: 1);
    
    // for(int i=3; i<=n; i++)
    // {
        
    // }

    int dp[n+1];
    dp[0] = 1;
    if(A[0] == '0') return 0;

    for(int i =1;i<n;i++)
    {
        if(A[i-1] == '0' and A[i] == '0')
        {
            dp[i] = 0;

        }
        else if(A[i-1] == '0' and A[i] != '0')
        {
            dp[i] = dp[i-1] ;
        }
        else if(A[i-1] != '0' and A[i] == '0')
        {
            if(A[i-1] == '1' or A[i-1] == '2')
            {
                dp[i] = ( i>= 2 ? dp[i-2]: 1) ;
            }
            else
            {
                dp[i] = 0;
            }
        }
        else
        {
            if(A.substr(i-1, 2) <= "26")
            {
                dp[i] = (dp[i-1] +( i>= 2 ? dp[i-2]: 1)) ;
            }
            else
            {
                dp[i] = dp[i-1];
            }

        }

        
    }

    return dp[n-1] ;
        
    }
};