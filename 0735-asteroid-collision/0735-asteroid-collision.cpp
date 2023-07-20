class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int &x : asteroids) {
            if (x < 0) {
                if (st.empty() || st.top() < 0) st.push(x);
                else {
                    int neg = x * -1; 
                    while (!st.empty() && st.top() > 0 && neg > st.top()) st.pop();
                    if (st.empty() || neg > st.top()) st.push(x);
                    else if (neg == st.top()) st.pop();
                };
            } else st.push(x);    
        };

        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) ans[i] = st.top(), st.pop();
        return ans;
    };
};