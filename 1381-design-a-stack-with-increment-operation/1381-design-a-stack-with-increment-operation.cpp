class CustomStack {
public:

vector<int>st;
int capacity;

    CustomStack(int maxSize) {
        capacity = maxSize;
    }
    
    void push(int x) {
        if(st.size() < capacity){
            st.push_back(x);
        }
    }
    
    int pop() {
        if(st.empty()){
            return -1;
        }
        int x = st.back();
        st.pop_back();

        return x;
    }
    
    void increment(int k, int val) {
        
        int n = min(k , (int)st.size());
        for(int  i=0;i<n;i++){
            st[i] += val;
                    }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */