class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(n, quantities, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool canDistribute(int n, const vector<int>& quantities, int maxProductsPerStore) {
        int og = 0;
        for (int quantity : quantities) {
            og += (quantity + maxProductsPerStore - 1) / maxProductsPerStore;
        }
        return og <= n;
    }
};
