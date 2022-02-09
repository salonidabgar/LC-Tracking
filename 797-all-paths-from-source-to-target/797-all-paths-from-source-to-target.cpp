class Solution {
public:
    
    void path(vector<vector<int>> & g, int idx,vector<int> currpath, vector<vector<int>> &sol)
    {
        
        // cout<<g[idx].size() <<endl;
        int n = g.size();
        currpath.push_back(idx);
        
        
        // if(idx >= g[idx].size()) return sol;
        if(idx == n-1 ) 
        {
            sol.push_back(currpath);
            return;
        }
        for(int j = 0; j<g[idx].size();j++)
        {
            
            //currpath.push_back(g[idx][j]);
            
            path(g,g[idx][j] , currpath, sol);
            
            
        }
        currpath.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> currpath;
        vector<vector<int>> sol;
        path(graph, 0, currpath, sol);
        return sol;
    }
};