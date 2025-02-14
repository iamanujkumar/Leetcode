
class ProductOfNumbers {
private:
    vector<int> fan;
public:
    ProductOfNumbers() {
        fan = {1};
    }
    void add(int num) {
        if (num == 0) {
            fan = {1};
        } else {
            fan.push_back(fan.back() * num);
        }
    }
    int getProduct(int k) {
        int n = fan.size();
        if (k >= n) return 0;
        return fan.back() / fan[n - k - 1];
    }
};
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */