class Solution {
    void sieveOfEratosthenes(vector<int>& primes,int maxVal){
        bool sieve[maxVal+1];
        memset(sieve,false,sizeof(sieve));
        for(int i=2;i*i<maxVal;++i){
            if(sieve[i]==false){
                for(int j=2;i*j<maxVal;++j)
                    sieve[i*j]=true;
            }
        }
        for(int i=2;i<maxVal;++i)
            if(sieve[i]==false)
                primes.push_back(i);
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes;
        int maxVal = *max_element(nums.begin(),nums.end());
        sieveOfEratosthenes(primes,maxVal);
        for(int i=0;i<nums.size();++i){
            int rs = i==0?nums[0]-1:nums[i]-nums[i-1]-1;
            int rsr = lower_bound(primes.begin(),primes.end(),rs)-primes.begin();

            if(rsr==primes.size() or primes[rsr]>rs)        rsr--;
            if(rsr<0){
                if(i==0 or nums[i]>nums[i-1])    continue;
                else  return false;
            }
            nums[i]-=primes[rsr];
        }
        return true;
    }
};