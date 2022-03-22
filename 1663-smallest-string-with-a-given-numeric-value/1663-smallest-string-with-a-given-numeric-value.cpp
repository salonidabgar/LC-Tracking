class Solution {
public:
    string getSmallestString(int n, int k) {
        string c(n,'a');
        k -=n;
        while(k>0)
        {
            c[--n] +=min(25,k);
             k -=min(25,k);
        }
        return c;
    }
};