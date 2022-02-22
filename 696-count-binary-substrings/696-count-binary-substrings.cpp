class Solution {
public:
    int countBinarySubstrings(string s) {
        int a =1, b= 0, ans =0,i;
        for(i=1;i<s.length();i++)
        {
            if(s[i] == s[i-1]) a++;
            else
            {
                ans += min(a,b);
                b = a;
                a = 1;
            }
        }
        ans+=min(a,b);
        return ans;
    }
};