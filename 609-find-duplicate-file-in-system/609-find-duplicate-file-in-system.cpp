class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> m;
        for (auto &str : paths) {
            string root = "", file = "", text = "";
            bool spaceFound = false, openBracket = false;
            for (auto &ch : str) {
                if (ch == '(') openBracket = true;

                if (!spaceFound && ch == ' ') root += '/', spaceFound = true;
                else if (spaceFound && !openBracket && ch != ' ') file += ch;
                else if (spaceFound && openBracket && ch != ')' && ch != '(') text += ch;
                else if (spaceFound && openBracket && ch == ')') 
                    m[text].push_back(root + file), openBracket = false, file = "", text = "";
                
                if (!spaceFound) root += ch;
            };                    
        };
        
        vector<vector<string>> v;
        for (auto &i : m) {
            if (i.second.size() > 1) v.push_back(i.second);
        };
        return v;
    };
};