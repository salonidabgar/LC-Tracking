class Solution {
public:
    void printvector(vector<int> &v)
    {
        for(int i : v)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
    
    bool checkInclusion(string s1, string s2) {
    
        int n = s1.length();
        int n2 = s2.length();
        
        vector<int> m(27,0);
        vector<int> m2(27,0);
        
        for(char ch:s1)
        {
            m[ch-'a']++;
        }
        
        // printvector(m);
        
        for(int i =0;i<n2;i++)
        {
            if(i<n)
            {
                m2[s2[i]-'a']++;
                if(i == n-1)
                {
                     if(m == m2)
                {
                    return true;
                }
                }
                
            }
            if(i>=n)
            {
                // printvector(m2);
                if(m == m2)
                {
                    return true;
                }
                
            m2[s2[i-n]-'a']--;
            m2[s2[i]-'a']++;
                if(m == m2)
                {
                    return true;
                }
            }
            
        }
       return false;
        
    }
};