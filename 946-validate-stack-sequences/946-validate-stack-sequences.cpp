class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(), j = 0;
        stack<int> s;
        for(auto i = 0; i < n; i++){
            if(pushed[i] != popped[j]){
                s.push(pushed[i]);
            }else{
                j++;
                while(!s.empty() && popped[j] == s.top()) s.pop(), j++;
            }
        }
        return s.empty();
    };
};