class Solution {
public:
    
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> cand ;
        vector<bool> visited(256, false);
        for (char c : s)
            cand[c]++;
        string result;
        for (char c : s) {
            cand[c]--;
            if (visited[c]) continue;
            while (c < result.back() && cand[result.back()]) {
                visited[result.back()] = false;
                result.pop_back();
            }
            result += c;
            visited[c] = true;
        }
        return result;
        
    }
};