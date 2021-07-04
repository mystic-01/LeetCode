class Solution {
public:
    string defangIPaddr(string address) {
        for (auto i = 0; i < address.length(); i++) {
            if (address[i] == '.') {
                address.replace(i, 1, "[.]");
                i+=2;
            };
        };
        return address;
    };
};