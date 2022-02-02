// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
    long long int merge(int l, int mid, int r, long long * arr, long long * temp) {
        int i = l, j = mid + 1, k = l;
        long long int count = 0;
        
        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];                
            } else {
                temp[k++] = arr[j++]; 
                count += (mid + 1 - i);
            };
        };
        
        while (i <= mid) temp[k++] = arr[i++];
        while (j <= r) temp[k++] = arr[j++];
        
        for (int i = l; i <= r; i++) arr[i] = temp[i];
        return count;
    };
  
    long long int mergeSort(int l, int r, long long * arr, long long * temp) {
        long long int count = 0;
        if (r > l) {
            int mid = l + (r - l) / 2;
            count += mergeSort(l, mid, arr, temp);
            count += mergeSort(mid + 1, r, arr, temp);
            
            count += merge(l, mid, r, arr, temp);
        };
        return count;
    };
        
    long long int inversionCount(long long arr[], long long N) {
        
        long long temp[N] = {0};
        
        long long int count = 0;
        count += mergeSort(0, N - 1, arr, temp);
        return count;
        
    };

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends