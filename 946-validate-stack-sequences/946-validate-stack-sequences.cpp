class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int n1 = pushed.size(),j=0;
        for(int i=0;i<n1;++i)
        {
            s.push(pushed[i]);
            while(!s.empty() and s.top() == popped[j] )
            {
                s.pop();
                ++j;
            }
        }
        return s.empty();
        
        
            
    }
};