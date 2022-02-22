class Solution {
public:
    int titleToNumber(string c) {
        int colnumber =0;
        for(int i= 0 ;i<c.length();i++)
        {
            colnumber = colnumber*26 +( c[i] - 64);
        }
        return colnumber;
        
    }
};