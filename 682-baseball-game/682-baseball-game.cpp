class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<string> st;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i] == "C")
            {
                st.pop();
            }
            else if(ops[i] == "+")
            {
                int top = stoi(st.top());
                st.pop();
                int stop = stoi(st.top());
                st.push(to_string(top));
                st.push(to_string(top+stop));
            }
            else if(ops[i] == "D")
            {
                int top = stoi(st.top());
                st.push(to_string(2*top));
            }
            else
            {
                st.push(ops[i]);
            }
        }
        int sum =0;
        while(!st.empty())
        {
            sum+=stoi(st.top());
            st.pop();
        }
        return sum;
    }
};