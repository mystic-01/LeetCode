class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        int max_h = INT_MIN,max_w = INT_MIN;
        hc.insert(hc.begin(),0);
        vc.insert(vc.begin(),0);
        hc.push_back(h);
        vc.push_back(w);
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        for(int i = 1; i < hc.size(); i++){
            max_h = max(abs(hc[i] - hc[i-1]),max_h);
        }
        for(int i = 1; i < vc.size();i++){
            max_w =  max(abs(vc[i] - vc[i-1]),max_w);
        }
        
        return (1LL*max_w*max_h)%1000000007;
    };
};