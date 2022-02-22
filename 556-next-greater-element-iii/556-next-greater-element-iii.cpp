class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> v;
        int b = n;
        while(n)
        {
            v.push_back(n%10);
            n/=10;
        }
        reverse(v.begin(), v.end());
        
        next_permutation(v.begin(), v.end());
        
        for(int i =0;i<v.size();i++)
        {
            if(n > INT_MAX/10  || (n==INT_MAX/10 && v[i] > 7))
            {
                return -1;
            }
            n = n*10 + v[i];
        }
        if(n <= b)
        {
            return -1;
        }
        return n;
    }
};