class Solution {
public:
    #include <set>
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char,char> m;
        set <char> values;
        for(int i =0;i<s.length();i++)
        {   
            //cout <<i<<endl;
            if (m.find(s[i])==m.end()){
                if(values.find(t[i])==values.end()){
                    m[s[i]] = t[i];
                    values.insert(t[i]);
                    continue;}
                else return false;
            }
            else {
                if(m[s[i]]!=t[i]) return false;
                else continue;
            }        
        
        }
        return true;
    }

};