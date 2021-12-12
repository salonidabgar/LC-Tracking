class Solution {
public:
    int findlen(string &s, int k, int ch){
        int n = s.length();
        int maxlen =1;
        int l=0,r=0;
        int c =0;
        while(r<n)
        {
            if(s[r]!= ch)
            {
                c++;
            }
            
            while(c>k)
            {
                if(s[l]!=ch)
                {
                    c--;
 
                }
                l++;
            }
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
            
        
    }
    int characterReplacement(string s, int k) {
        int maxlen = 1;
        int st =0, end ;
        for(int i=0;i<26;i++){
        maxlen = max(maxlen, findlen(s, k, i+'A'));
        }
        
        return maxlen; 
    }
};