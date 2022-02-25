// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    int maxMeetings(int start[], int end[], int n) {
        vector<vector<int>> v(n);
        vector<int> curr(3), ans;
        
        for (auto i = 0; i < n; i++) {
            curr[0] = end[i], curr[1] = start[i], curr[2] = i;
            v[i] = (curr);
        };
        sort(v.begin(), v.end());
        ans.push_back(v[0][2]);
        
        int timeLimit = v[0][0];
        
        for (auto i = 1; i < n; i++) {
            if (v[i][1] > timeLimit) {
                ans.push_back(v[i][2]);
                timeLimit = v[i][0];
            };            
        };
        return ans.size();
    };
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends