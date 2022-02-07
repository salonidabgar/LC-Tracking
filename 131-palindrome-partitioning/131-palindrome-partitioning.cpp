class Solution {
public:
    bool palindromic(string s)
    {
        int l =0, r = s.length()-1;
        
        while(l <= r) {
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
    void partitioner(string s, vector<string>& ans, vector<vector<string>>& res)
    {
        if(s.empty() or s.length() == 0)
        {
            res.push_back(ans);
            return;
        }
        
        for(int i=1;i<=s.length();i++)
        {
            string temp = s.substr(0,i);
            
            if(!palindromic(temp)) continue;
            
            ans.push_back(temp);
            partitioner(s.substr(i, s.length()),ans, res);
            ans.pop_back();
    
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res; vector<string> ans;
        if(s.empty() or s.length() == 0)
        {
            return res;
        }
        
        partitioner(s,ans,res);
        return res;
        
    }
};