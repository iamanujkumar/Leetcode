class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9 + 7;

    vector<vector<ll>>PT;
    
    int fun(vector<int>&nums){
        int n = nums.size();
        if(n<3){
            return 1;
        }
        int root = nums[0];
        vector<int>left,right;
        for(int i=1;i<n;i++){
            if(root>nums[i]){
                left.push_back(nums[i]);
            }
            else right.push_back(nums[i]);
        }

        ll x = fun(left)%MOD;
        ll y = fun(right)%MOD;

        ll z = PT[n-1][left.size()];
        
        return (((x*y)%MOD)*z)%MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        PT.resize(n+1);
        for(int i=0;i<=n;i++){
            PT[i] = vector<ll>(i+1,1);
            for(int j=1;j<i;j++){
                PT[i][j] = (PT[i-1][j] + PT[i-1][j-1])%MOD;
            }
        }
        return ((fun(nums))-1) %MOD;
    }
};