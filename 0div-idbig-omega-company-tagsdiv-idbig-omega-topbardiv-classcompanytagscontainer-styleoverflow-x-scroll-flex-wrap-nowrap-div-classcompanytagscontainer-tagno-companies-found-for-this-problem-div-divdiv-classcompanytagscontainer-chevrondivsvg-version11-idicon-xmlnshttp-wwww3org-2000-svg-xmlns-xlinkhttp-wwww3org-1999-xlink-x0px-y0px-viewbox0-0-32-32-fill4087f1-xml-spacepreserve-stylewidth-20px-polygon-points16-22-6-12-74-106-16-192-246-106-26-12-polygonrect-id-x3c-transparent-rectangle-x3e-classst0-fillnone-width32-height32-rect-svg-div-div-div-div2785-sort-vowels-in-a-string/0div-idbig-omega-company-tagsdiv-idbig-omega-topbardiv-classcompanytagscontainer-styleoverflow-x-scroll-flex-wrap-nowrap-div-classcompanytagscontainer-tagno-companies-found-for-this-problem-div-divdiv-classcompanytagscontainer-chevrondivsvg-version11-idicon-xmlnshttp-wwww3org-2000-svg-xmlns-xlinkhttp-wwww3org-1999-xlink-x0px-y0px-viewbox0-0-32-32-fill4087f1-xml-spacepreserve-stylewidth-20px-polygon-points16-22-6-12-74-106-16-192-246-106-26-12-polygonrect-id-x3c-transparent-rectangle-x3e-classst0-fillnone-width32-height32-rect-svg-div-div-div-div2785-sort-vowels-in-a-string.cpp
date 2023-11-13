class Solution {
public:
    string sortVowels(string s) {
        set<char> vowels = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        string currVow = "";
        int idx = 0;
        
        for (auto &ch : s) if (vowels.find(ch) != vowels.end()) currVow += ch; 
        sort(currVow.begin(), currVow.end());
        for (auto &ch : s) if (vowels.find(ch) != vowels.end()) ch = currVow[idx++]; 

        return s;
    };
};