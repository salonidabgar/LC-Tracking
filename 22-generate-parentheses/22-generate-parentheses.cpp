class Solution {
public:
    void generator(vector<string> &res, string str, int n, int m)
    {
        if(n==0 and m==0)
        {
            res.push_back(str);
            return;
        }
        if(m>0)
        {
            generator(res, str+')', n, m-1);
        }
        if(n>0)
        {
            generator(res, str+'(', n-1, m+1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        generator(res, "", n, 0);
        return res;
    }
};