// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void generator(vector<vector<int>> &m, vector<string> & sol,
    string ans,vector<vector<int>> & vis, int i, int j, int n)
    {
        if(i==n-1 and j==n-1) 
        {
            sol.push_back(ans);
            return;
        }
        
        //down
        if(i+1 <n and !vis[i+1][j] and m[i+1][j] == 1)
        {
            vis[i][j] = 1;
            generator(m, sol, ans + 'D', vis, i+1,j,n);
            vis[i][j] = 0;
        }
        //left
        if(j-1 >=0 and !vis[i][j-1] and m[i][j-1] == 1)
        {
            vis[i][j] = 1;
            generator(m, sol, ans +'L', vis, i, j-1,n);
            vis[i][j] = 0;
        }
        //right
        if(j+1< n and !vis[i][j+1] and m[i][j+1] == 1)
        {
            vis[i][j] = 1;
            generator(m, sol, ans +'R', vis, i,j+1,n);
            vis[i][j] = 0;
        }
        //up
        if(i-1 >=0 and !vis[i-1][j] and m[i-1][j] ==1)
        {
            vis[i][j] = 1;
            generator(m, sol , ans+'U', vis, i-1,j,n);
            vis[i][j] = 0;
        }
     

    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int> >vis(n, vector<int>(n,0));
        vector<string> sol;
        if(m[0][0] == 1) generator(m, sol,"", vis, 0, 0,n);
        return sol;
        
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends