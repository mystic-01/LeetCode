class Solution {
public:
    int recurse (int xLeft, int yLeft, int zLeft, int prev, int (*arr)[51][51][4]) {
        int takeX = 0, takeY = 0, takeZ = 0;
        if (arr[xLeft][yLeft][zLeft][prev] != -1) return arr[xLeft][yLeft][zLeft][prev];
        
        if (prev == 0) {
            takeX = 1 + recurse(xLeft - 1, yLeft, zLeft, 1, arr);
            takeY = 1 + recurse(xLeft, yLeft - 1, zLeft, 2, arr);
            takeZ = 1 + recurse(xLeft, yLeft, zLeft - 1, 3, arr);
        } else if (prev == 1) {
            takeY = (yLeft == 0 ? 0 : 1 + recurse(xLeft, yLeft - 1, zLeft, 2, arr));
        } else  {
            takeX = (xLeft == 0 ? 0 : 1 + recurse(xLeft - 1, yLeft, zLeft, 1, arr));
            takeZ = (zLeft == 0 ? 0 : 1 + recurse(xLeft, yLeft, zLeft - 1, 3, arr));            
        };
        
        return arr[xLeft][yLeft][zLeft][prev] = max(takeY, max(takeX, takeZ));            
    };
    
    int longestString(int x, int y, int z) {
        int arr[51][51][51][4];
        for (auto i = 0; i < 51; i++) {
            for (auto j = 0; j < 51; j++) {
                for (auto k = 0; k < 51; k++) {
                    for (auto l = 0; l < 4; l++) {
                        arr[i][j][k][l] = -1;
                    };
                };
            };
        };
        
        return recurse(x, y, z, 0, arr) * 2;
    };
};


/*

x = "AA", 1
y = "BB", 1
z = "AB", 1

x -> y
y -> x | z
z -> x | z

1 + 

*/