class Solution {
public:
    vector<int> partitionLabels(string s) {
         vector<int> sol;
        int n = s.length();
        // if(s.length()==0) return 0;
        
        int idx[26];
        for(int i=0;i<n;i++)
        {
            idx[s[i]- 'a'] = i;
        }
        int i =0;
        while(i<s.length())
        {
            int end = idx[s[i] - 'a'];
            int j =i+1;
            while(j<=end)
            {
                end = max(end, idx[s[j++] - 'a']);
            }
            sol.push_back(j-i);
            i = j;
        }
        return sol;   
    }
};