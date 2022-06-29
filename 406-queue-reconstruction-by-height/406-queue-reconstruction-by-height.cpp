class Solution {
public:
    static bool compare(vector<int>fst, vector<int>snd) {
        if (fst[1] == snd[1])
            return fst[0] < snd[0];
        return fst[1] < snd[1];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> ans;
        
        for (int i = 0; i < people.size(); i++) {
            vector<int> v = people[i];
            
            if (v[1] == 0) {
                ans.push_back(v);
            }
            else {
                int inFront = v[1];
                int placeAt = 0;

                while (placeAt < ans.size() && inFront > 0) {
                    if (ans[placeAt][0] >= v[0]) {
                        inFront--;
                    }
                    placeAt++;
                }  

                if (inFront == 0) {
                    while(placeAt < ans.size() && ans[placeAt][0] <= v[0]){
                        placeAt++;
                    }
                    ans.insert(ans.begin() + placeAt, v);
                }
            }
        }
        
        return ans;
    }
};