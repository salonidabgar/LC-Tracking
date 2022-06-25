class Solution {
public:
    int countAsterisks(string s) {
        int count =0,vert =0;
        for(int i=0;i<s.length();i++)
        {
              if(s[i] == '|')
              {
                  vert++;

              }
            if(vert%2==0 and s[i] == '*') count++;
        }
        return count;
        
    }
};