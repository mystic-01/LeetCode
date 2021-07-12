class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector <string> v;
        for (int i = 0; i < words.size(); i++) {
          string key = words[i];
            for (int j = 0; j < words.size(); j++) {
                auto flag = 0;
                if (j == i) continue;
                else {
                  for (int k = 0; k < words[j].length(); k++) {
                        if (words[j].substr(k, key.length()) == key) {
                            v.push_back(key);
                            flag = 1;
                            break;
                        };
                  };
                if (flag == 1) break;
                };
            };
        };
        return v;
    };
};