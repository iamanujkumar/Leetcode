class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>sf(n);
        vector<int>pr(n);
        int ans=0;
        sf[0]=height[0];
        for(int i=1;i<n;i++){
            sf[i]=max(sf[i-1],height[i]);
        }
        pr[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            pr[i]=max(pr[i+1],height[i]);
        }
        for(int i=0;i<n;i++){
            int sfMax=sf[i], prMax=pr[i];
            if(height[i]<sfMax && height[i]<prMax){
                ans+=min(sfMax,prMax)-height[i];
            }
        }
        return ans;
    }
};