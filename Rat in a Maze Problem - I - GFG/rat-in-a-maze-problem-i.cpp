// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i, int j, int n, vector<vector<int>> m, vector<string>& ans, string ds) {
        if (i >= n || j >= n || i <= -1 || j <= -1) return;
        if (m[i][j] == 0) return;
        if (i == n - 1 && j == n - 1) {
            ans.push_back(ds); 
            return;
        };
        
        // int temp = m[i][j];
        m[i][j] = 0;
        ds += 'D';
        
        solve(i + 1, j, n, m, ans, ds);  
        ds.pop_back();
        
        ds += 'L';
        solve(i, j - 1, n, m, ans, ds);
        ds.pop_back();
        
        ds += 'R';
        solve(i, j + 1, n, m, ans, ds);
        ds.pop_back();
        
        ds += 'U';
        solve(i - 1, j, n, m, ans, ds);
        ds.pop_back();

    };  
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string ds = "";
        solve(0, 0, n, m, ans, ds);
        return ans;
    };
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends