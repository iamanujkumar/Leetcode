class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        if (n < 3) return 0;
        
        int count = 0;
        for (int j = 1; j < n - 1; ++j) {
            int lessLeft = 0, greaterLeft = 0;
            int lessRight = 0, greaterRight = 0;
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) lessLeft++;
                if (rating[i] > rating[j]) greaterLeft++;
            }
            for (int k = j + 1; k < n; ++k) {
                if (rating[k] < rating[j]) lessRight++;
                if (rating[k] > rating[j]) greaterRight++;
            }
            count += lessLeft * greaterRight;
            count += greaterLeft * lessRight;
        }
        
        return count;
    }
};
