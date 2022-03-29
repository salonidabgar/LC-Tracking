class Solution {
public:
    bool halvesAreAlike(string s) {
        int c1=0,c2=0;
        int n = s.length();
        if(n%2!=0) return false;
        for(int i=0;i<n/2;i++)
        {
            if(s[i] == 'a' or s[i] ==  'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] ==  'U') c1++;
        }
        for(int j=n/2;j<n;j++)
        {
            if(s[j] == 'a' or s[j] ==  'e' or s[j] == 'i' or s[j] == 'o' or s[j] == 'u' or s[j] == 'A' or s[j] ==  'E' or s[j] ==  'I' or s[j] == 'O' or s[j] ==  'U') c2++;
        }
        // cout<< c1<<" "<<c2<<endl;
        return (c1==c2)?true:false;
    }
};