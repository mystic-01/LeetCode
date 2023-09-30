class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int n = nums.size(), score = nums[0];
        for (int i = 1; i < n; ++i) {
            // Here, we find the minimum possible score of the array, as required by the problem statement. 
            // How is this minimum you ask? 
            // Well, the more you use AND the more it reduces (or atleast keeps the same) 
            // your number of '1 bits' in the final answer. 
            // Hence, in order to get smallest AND value among 'n numbers', 
            // you can be sure that it'll be the AND of 'em all.'
            score = (score & nums[i]);
        };
        
        // If you score (cumulative AND value) is not zero, we return '1' i.e. 
        // no split is possible such that the minimum answer is maintained.
        // Why??
        // The values that make up a 'cumulative AND value'
        // will always be greater than or atleast equal to the 'cumulative AND value'.
        // This holds because AND is simply deletion of '1 bits' whenever possible 
        // (this'd be a good time to recall AND's truth tables and notice how result is always less than or equal).
        // Simply put, AND is degenarative by definition, hence even if our 'score' is as low 1 or 2, 
        // upon splitting the array, the lowest score we can possibly get is - (1 + 1 ~= 2) or (2 + 2 ~= 4) respectively.
        // However, for 0, we can have mulltiple subarrays giving '0' AND value 
        // and thereby, keeping the total score '0' as well.
        if (score != 0) return 1;
        
        int splits = 0, currScore = -1;
        for (int i = 0; i < n; ++i) {
            if (currScore == -1) currScore = nums[i];
            else currScore = (currScore & nums[i]); 

            // Here. we check for any subarrays that result in a 'currScore' equal to zero and increment the splits if we find '0' score.
            // We also reset the currScore, in orsder to drop the effects of any previous AND operations.
            if (currScore == score) splits++, currScore = -1;
        };  
        return splits;
    };
};