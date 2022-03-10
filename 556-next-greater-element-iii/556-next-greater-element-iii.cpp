class Solution {
public:
    int nextGreaterElement(int n) {
       //next permutation of n
           string s = to_string(n);
           int len = s.length();
        int i,j;
        i = len-2;
        while(i>=0 and s[i]>=s[i+1]) i--;
        if(i==-1) return -1;
        else
        {
            for(int j = len-1;j>i;j--)
            {
                if(s[j]>s[i])
                {
                    swap(s[i], s[j]);
                    break;
                }
            }
            reverse(s.begin()+i+1, s.end());
        }
        auto num = stoll(s);
        if(num > INT_MAX ) return -1;
        return num;

    }
};