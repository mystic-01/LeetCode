class Solution {
public:
    string encode(string longUrl) { 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        return longUrl + "short";
    };
    string decode(string shortUrl) { 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        return shortUrl.substr(0, shortUrl.length() - 5);

    };
};
