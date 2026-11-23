class ProductOfNumbers {
public:
    vector<long long> products;
    int idx;
    ProductOfNumbers() {
        idx = 0;
        products = {1};
    }
    
    void add(int num) {
        if(num==0) {
            products = {1};
            idx = 0;
        } else {
            int prod = products[idx]*num;
            products.push_back(prod);
            idx++;
        }
    }
    
    int getProduct(int k) {
        if(k>idx) return 0;
        long long x = products[idx];
        long long y = products[idx-k];
        return x/y;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */