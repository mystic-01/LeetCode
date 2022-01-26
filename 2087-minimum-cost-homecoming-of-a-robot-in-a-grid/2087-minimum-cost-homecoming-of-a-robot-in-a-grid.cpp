class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int cost = 0, startRow = startPos[0], startCol = startPos[1], homeRow = homePos[0], homeCol = homePos[1];
        
        if (startRow > homeRow) {
            for (int i = homeRow; i < startRow; i++) cost += rowCosts[i];                
        } else {
            for (int i = startRow; i < homeRow; i++) cost += rowCosts[i + 1];                
        };
        
        if (startCol > homeCol) {
            for (int i = homeCol; i < startCol; i++) cost += colCosts[i];                
        } else {
            for (int i = startCol; i < homeCol; i++) cost += colCosts[i + 1];                
        };
        return cost;
    };
};