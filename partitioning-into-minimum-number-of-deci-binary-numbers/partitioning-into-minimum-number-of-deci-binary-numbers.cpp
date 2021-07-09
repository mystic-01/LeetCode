class Solution {
public:
    int minPartitions(string n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        auto len = n.length();
        if (len == 1) return int(n[0])-48;            

        auto max = '1';
        auto i = 0;
        auto j = len - 1;
        while (i < len/2 + 1) {
            if (n[i] > max) max = n[i];            
            if (n[j] > max) max = n[j];
            if (max == '9') return 9;
            i++; 
            j--;
        };
        return int(max)-48;
    };
};