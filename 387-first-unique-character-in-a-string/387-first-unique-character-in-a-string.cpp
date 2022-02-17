#include <algorithm>
#include <bits/stdc++.h>
int min(int x, int y)
{
  return (x < y) ? x : y;
}

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length(), ans = INT_MAX;
        unordered_map<char, int> mp;
        for(char& i: s)
        {
            mp[i]++;
        }
        // cout<<mp[0]<<endl;
        for(int i =0;i<n;i++)
        {
            // cout<<mp[i]<<" "<<1<<endl;
            if(mp[s[i]] ==1)
            {
                
                // cout<<i<<endl;
                // ans = min(ans,i);
                return i;
            }
            // else continue;
        }
        return -1;        
    }
};