class Solution {
public:
    
    string removeDuplicateLetters(string s) {
        vector<bool> vis(256,false);
        unordered_map<char,int> mp;
        for(char & c:s)
        {
            mp[c]++;
        }
        string res;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]--;
            if(vis[s[i]]) continue;
            while(s[i]<res.back() and mp[res.back()])
            {
                vis[res.back()] = false;
                res.pop_back();
            }
            res+=s[i];
            vis[s[i]] = true;
        }
           return res;
                
        }
        
    
};