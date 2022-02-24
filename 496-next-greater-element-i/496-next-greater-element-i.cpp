class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), n2 = nums2.size();
        vector<int> res(n, -1); 
        stack<int> st;
        unordered_map<int, int> m;
        
        for(int i = n2 - 1; i >= 0; i--) {
            while(!st.empty() && nums2[i] >= st.top()) st.pop();
            if (!st.empty()) m[nums2[i]] = st.top();
            st.push(nums2[i]);
        };
        
        for(int i = 0; i < n; i++) {
            if (m.find(nums1[i]) != m.end()) res[i] = m[nums1[i]];
        };
        return res;
    };
};