class ProductOfNumbers {
public:
    vector<int> vec;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        vec.push_back(num);
    }
    
    int getProduct(int k) {
        int cnt=0,i=vec.size()-1,ans=1;
        while(cnt<k)
        {
            ans*=vec[i];
            i--;
            cnt++;
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */