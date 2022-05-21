class Solution {
    public String convertToBase7(int num) {
        if(num == 0) return "0";
        String str = "";
        boolean isPos = num > 0;
        num = Math.abs(num);
        while(num != 0){
            int r = num % 7;
            str = (char)(r + 48) + str;
            num /= 7;
        }
        return isPos ?  str : '-' + str;        
    }
}