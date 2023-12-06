class Solution {
public:
    int distMoney(int money, int children) {
        if ((money -= children) < 0) return -1;
        if (money < 7) return 0;
        int valid = min(children, money / 7);
        return max(0, valid + (((money % 7 == 3 && (valid == children || valid == children - 1)) 
                                || ((money % 7 || valid * 7 < money) && money / 7 >= children)) ? - 1 : 0));        
    };
};