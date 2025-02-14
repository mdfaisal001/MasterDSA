class ProductOfNumbers {
private:
    vector<int> prefixProduct; // Vector to store the prefix products

public:
    ProductOfNumbers() {
        // Initialize with 1 as the first element for easy calculation
        prefixProduct.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            // Reset the prefix product vector if 0 is encountered
            prefixProduct.clear();
            prefixProduct.push_back(1);
        } else {
            // Add the product of the last element and num
            prefixProduct.push_back(prefixProduct.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefixProduct.size();
        if (k >= n) {
            // If k is greater than the valid sequence, return 0
            return 0;
        }
        // Return the product of the last k elements
        return prefixProduct.back() / prefixProduct[n - k - 1];
    }
};


/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */