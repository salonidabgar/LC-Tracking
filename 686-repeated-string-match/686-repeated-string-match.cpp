class Solution {
public:
    
    bool solve(string b, string s)
    {
        int slen = s.length();
        int blen = b.length();
        for(int i = 0;i <= slen - blen;i++)
        {
            int j = 0;
            while(j<blen)
            {
                if(s[i+j] != b[j])
                {
                    break;
                }
                j++;
            }
            if(j == blen) return true;
                
            
        }
        return false;
    }
    
    int repeatedStringMatch(string a, string b) {
        int n = a.length();
        int m = b.length();
        
        int ans =1; 
        string S = a;
        while(S.length() < b.length())
        {
            S+=a;
            ans++;
        }
        
        if(solve(b,S))
        {
            return ans;
        }
        if(solve(b, S+a))
        {
            return ans+1;
        }
        return -1;
    }
};