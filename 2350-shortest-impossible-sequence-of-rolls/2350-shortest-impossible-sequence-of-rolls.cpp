class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        set<int>s;
        int res =0;
        for(auto a: rolls)
        {
            s.insert(a);
            if(s.size() == k)
            {
                res++;
                s.clear();
            }
        }
        return res+1;
    }
};