class Solution {
public:
    // Using only a vector, no stack needed!!!
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int &x : asteroids) {
            if (x < 0) {
                if (!ans.size() || ans.back() < 0) ans.push_back(x);
                else {
                    int neg = x * -1; 
                    while (ans.size() && ans.back() > 0 && neg > ans.back()) ans.pop_back();
                    if (!ans.size() || neg > ans.back()) ans.push_back(x);
                    else if (neg == ans.back()) ans.pop_back();
                };
            } else ans.push_back(x);    
        };
        return ans;
    };
};