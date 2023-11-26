class Solution {
public:
int largestSubmatrix(vector<vector<int>>& v) {
        if(v.size()==0)return 0;
        int n=v.size(),m=v[0].size();
        int height[m],s[m],ans=0;
        memset(height,0,sizeof height);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==0)height[j]=0;
                else height[j]++;
                s[j]=height[j];
            }
            sort(s,s+m);
            for(int j=0;j<m;j++){
                int res=s[j]*(m-j);
                ans=max(ans,res);
            }
        }
      return ans;
    }
};