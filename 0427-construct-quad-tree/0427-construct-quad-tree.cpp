/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    
    Node* constructNode(int rStart, int rEnd, int cStart, int cEnd, vector<vector<int>>& grid) {
        int val = -1;
        for (auto i = rStart; i < rEnd; i++) {
            for (auto j = cStart; j < cEnd; j++) {
                if (val == -1) val = grid[i][j];
                else if (val != grid[i][j]) {
                    int rMid = (rEnd + rStart) / 2, cMid = (cEnd + cStart) / 2;

                    Node *topLeft = constructNode(rStart, rMid, cStart, cMid, grid);
                    Node *topRight = constructNode(rStart, rMid, cMid, cEnd, grid);
                    Node *bottomLeft = constructNode(rMid, rEnd, cStart, cMid, grid);
                    Node *bottomRight = constructNode(rMid, rEnd, cMid, cEnd, grid);

                    return new Node(val, false, topLeft, topRight, bottomLeft, bottomRight);
                };
            };
        };
        if (val != -1) return new Node(val, true);
        return new Node();
    };
    
    Node* construct(vector<vector<int>>& grid) {
        int start = 0, end = grid.size();
        return constructNode(start, end, start, end, grid);
    };
};

































