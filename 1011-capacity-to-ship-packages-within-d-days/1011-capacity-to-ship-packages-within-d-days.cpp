class Solution {
public:
    int countDays(vector<int>& ws, int tot_cap, int cur_cap = 0, int res = 1) {
  for (auto w : ws) {
    cur_cap += w;
    if (cur_cap > tot_cap) ++res, cur_cap = w;
  }
  return res;
}
int shipWithinDays(vector<int>& ws, int D) {
  auto r = accumulate(begin(ws), end(ws), 0);
  auto l = max(r / D, *max_element(begin(ws), end(ws)));
  while (l < r) {
    auto m = (l + r) / 2;
    if (countDays(ws, m) <= D) r = m;
    else l = m + 1;
  }
  return l;
}
//     int shipWithinDays(vector<int>& weights, int days) {
//         int n = weights.size(), multiplier = ceil((double)n / days);
//         cout << multiplier << "\n";
//         int lo = (*min_element(weights.begin(), weights.end()));
//         int hi = (*max_element(weights.begin(), weights.end())) * multiplier;
//         int least = hi; 
        
//         while (lo < hi) {
//             int mid = lo + (hi - lo) / 2, capacity = mid, daysLeft = days;            
//             for (auto i = 0; i < n; i++) {
//                 if (capacity - weights[i] < 0) daysLeft--, capacity = mid;
//                 capacity -= weights[i];
//             };
//             if (daysLeft < 0) lo = mid + 1; 
//             else hi = mid, least = min(least, mid);
//         };
        
//         return least;
//     };
};