class Solution {
public:
    string interpret(string command) {
        string s;
        auto i = 0;
        auto len = command.length();
        while (i < len) {
            if (command[i] == 'G') {
                s += 'G';
                i++;
            }
            else if (command[i] != 'G' && command[i+1] == 'a') {
                s += "al";
                i += 4;
            }
            else {
                s += "o";
                i += 2;
            };
        };
        return s;
    };
};