//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
            if(pat == "") return {};
            if(txt == "") return {};
            vector<int> lps(pat.size(),0);
            int i=1, prevlps = 0;
            while(i<pat.size())
            {
                if(pat[i] == pat[prevlps])
                {
                    lps[i] = prevlps+1;
                    prevlps++;
                    i++;
                }
                else
                {
                    if(prevlps==0)
                    {
                        i++;
                    }
                    else
                    {
                        prevlps = lps[prevlps-1];
                    }
                }
            }
            vector<int> ans;
            int j=0;
            i=0;
            while(j<txt.size())
            {
                if(pat[i] == txt[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    if(i==0)
                    {
                        j++;
                    }
                    else
                    {
                        i = lps[i-1];
                    }
                }
                if(i == pat.size()) ans.push_back(j-pat.size()+1);
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends