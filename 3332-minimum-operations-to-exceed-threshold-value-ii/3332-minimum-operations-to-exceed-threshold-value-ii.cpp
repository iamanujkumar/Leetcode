class Solution {
    #define ll long long
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>> hp(nums.begin(),nums.end());
        int pq = 0;
        while(!hp.empty()){
            ll min1 = hp.top();
            hp.pop();
            if(min1>=k)
                break;
            ll min2 = hp.top();
            hp.pop();
            
            hp.push(2*min(min1,min2)+max(min1,min2));
            pq++;
        }
        return pq;
    }
};