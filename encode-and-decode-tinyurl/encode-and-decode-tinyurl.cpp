class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) { 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        return longUrl + "short";
    };

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) { 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        return shortUrl.substr(0, shortUrl.length() - 5);

    };
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));