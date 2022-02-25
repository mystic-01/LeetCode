// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution {
    public:
    
    static bool comp(Item a, Item b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;        
    };
    
    double fractionalKnapsack(int bag, Item v[], int n) {
        double profit = 0.00;
        
        sort(v, v + n, comp);
        for (auto i = 0; i < n; i++) {
            if (bag >= v[i].weight) {
                profit += double(v[i].value);
                bag -= v[i].weight;
                
            } else {
                profit += (double(v[i].value) * (double(bag) / v[i].weight));
                break; 
            };
            
            if (bag == 0) break;
        };
        
        return profit;
    };
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends