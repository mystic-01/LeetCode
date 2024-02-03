class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        
        if (a == e || b == f) {
            // Rook captures
            if (a == e) {
                int start = min(b, f), end = max(b, f);
                // If Bishop is not in between
                if (c != a || d < start || d > end) return 1;
            } else if (b == f) {
                int start = min(a, e), end = max(a, e);
                // If Bishop is not in between
                if (d != b || c < start || c > end) return 1;
            };
        };        
        if (abs(c - e) == abs(d - f)) {
            // Bishop captures
            int startRow = min(c, e), endRow = max(c, e);
            int startCol = min(d, f), endCol = max(d, f);
            // If Rook is not in between
            if (abs(c - a) != abs(d - b) || a < startRow || a > endRow || b < startCol || b > endCol) return 1;
        };
        return 2;
    };
};