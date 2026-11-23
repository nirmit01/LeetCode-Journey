class ProductOfNumbers {
public:
    vector<int> vec;
    ProductOfNumbers() {
        vec.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            vec.clear();
            vec.push_back(1);
        } else{
            vec.push_back(num*vec.back());
        }
    }
    
    int getProduct(int k) {
        if((int)vec.size()<=k)  return 0;
        return vec.back()/vec[vec.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */