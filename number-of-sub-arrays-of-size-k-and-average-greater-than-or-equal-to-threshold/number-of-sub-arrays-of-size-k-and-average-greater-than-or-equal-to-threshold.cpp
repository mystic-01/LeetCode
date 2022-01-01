class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        auto low = 0, sum = 0, count = 0;
        for(auto i = 0; i < k; i++) {
            sum += arr[i];
        }
        if (sum / k >= threshold) count++;

        for(auto i = k; i < arr.size(); i++) {
            sum = (sum - arr[low++]) + arr[i];
            if (sum / k >= threshold) count++;
        }
        return count;
    };
};