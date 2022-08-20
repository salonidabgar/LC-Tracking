class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int len = 0, st = 0;
        for(int i=0;i<s.length();i++)
        {
            // cout << s[i]<<" "<< st<<" "<< len<<endl;
            if(s[i] == ' ' and len ==0)
            {
                continue;
            }
            else if(s[i] == ' ')
            {
                // cout<<"H";
                words.push_back(s.substr(st, len));
                len = 0;
            }
            else
            {
                if(len ==0)
                {
                    st = i;
                }
                len++;
            }
        }
        if(len !=0)
        {
            words.push_back(s.substr(st, len));
        }
        string ans;
        for(int i = words.size()-1 ; i>0;i--)
        {
            ans += words[i];
            ans += " ";
        }
        ans += words[0];
        return ans;
    }
};