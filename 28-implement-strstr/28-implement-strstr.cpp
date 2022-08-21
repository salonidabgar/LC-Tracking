class Solution {
public:
    int strStr(string h, string n) {
        if(h == " ") return -1;
        if(n == " ") return 0;
        if(h.length()< n.length()) return -1;
        for(int i = 0;i<h.length() - n.length()+1;i++)
        {
            if(h.substr(i, n.length()) == n) return i;
        }
        return -1;
    }
};