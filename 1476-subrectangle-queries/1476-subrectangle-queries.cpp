class SubrectangleQueries {
public:
    vector<vector<int>> rec, queries;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rec = rectangle;    
    };
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        queries.push_back({ row1, col1, row2, col2, newValue });
    };
    
    int getValue(int row, int col) {
        int n = queries.size();  
        for (auto i = n - 1; i >= 0; i--) {
            if (row >= queries[i][0] && row <= queries[i][2] 
                && col >= queries[i][1] && col <= queries[i][3]) 
                return queries[i][4];
        };
        return rec[row][col];         
    };
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */