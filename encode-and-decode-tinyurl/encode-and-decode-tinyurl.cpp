class Solution {
public:

    // Encodes a URL to a shortened URL.
    hash<string> h;
    unordered_map<string, string> mp;
    
    string encode(string longUrl) {
        
        mp[to_string(h(longUrl))] = longUrl;
        return to_string(h(longUrl)) ;
        
        
        
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));