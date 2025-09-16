class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>v;
        int i=0,j=0;
        deque<int>q;
        while(j<nums.size()){
            while(q.size()>0 && q.back()<nums[j]){
                q.pop_back();
            }
            q.push_back(nums[j]);
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                v.push_back(q.front());
                if(q.front()==nums[i]){
                    q.pop_front();
                }
                i++;
                j++;
            }
        }
        return v;
    }
};
