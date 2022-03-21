class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> tc(7), bc(7), same(7);
        int n = tops.size();
        for(int i=0;i<tops.size();i++)
        {
            tc[tops[i]]++;
            bc[bottoms[i]]++;
            if(tops[i]== bottoms[i]) same[tops[i]]++;
        }
        
        for(int i=1;i<=6;i++)
        {
            if(tc[i]+bc[i]-same[i] == n) return n- max(bc[i], tc[i]);
            
        }
        return -1;
        
    }
};