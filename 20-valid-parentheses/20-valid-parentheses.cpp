class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0 ) return false;
        stack<char> st;
        int i;
        for(i=0;i<s.length();i++)
        {
            // cout<<s[i]<<" "<<st.top()<<endl;
            if(s[i] == '(' or s[i] == '{' or s[i] == '[')
            {
                st.push(s[i]);
            }
            else if(s[i] == ')' and  !st.empty() and st.top() == '(')
            {
                st.pop();
                continue;
            }
            else if(s[i] == '}' and !st.empty() and st.top() == '{')
            {
                st.pop();
                continue;
            }
            else if(s[i] == ']' and !st.empty() and st.top() == '[')
            {
                st.pop();
                continue;
            }
            else return false;
            }
        if(st.empty()) return true;
        else return false;

    }
};