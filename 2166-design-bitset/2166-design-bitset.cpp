class Bitset {

private:
    vector<int> bits;
    bool flipped= false;
    int oneCount = 0;
    
public:
    Bitset(int size) {
        bits.resize(size, 0);                        
    };
    
    void fix(int idx) {
        if (!flipped) {
            oneCount += !bits[idx];
            bits[idx] = 1;
        } else {
            oneCount += bits[idx];
            bits[idx] = 0;
        };                
    };
    
    void unfix(int idx) {
        if (!flipped) {
            oneCount -= bits[idx];
            bits[idx] = 0;
        } else {
            oneCount -= !bits[idx];
            bits[idx] = 1;
        };
    };
    
    void flip() {
        flipped = !flipped;
        oneCount = bits.size() - oneCount;
    };
    
    bool all() {
        return oneCount == bits.size();
    };
    
    bool one() {
        return oneCount >= 1;
    };
    
    int count() {
        return oneCount;
    };
    
    string toString() {
        string ans = "";
        if (!flipped) {
            for (auto i : bits) ans += (i + '0');            
        } else {
            for (auto i : bits) ans += (!i + '0');                        
        };
        return ans;
    };
};