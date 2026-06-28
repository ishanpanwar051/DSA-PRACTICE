class MyHashMap {
public:
static const int SIZE =1009;
vector<list<pair<int,int>>>buckets;

    MyHashMap() {
        buckets.resize(SIZE);
    }
    
    void put(int key, int value) {
        int idx =key%SIZE;

        for(auto &it:buckets[idx]){
            if(it.first == key){
                it.second =value;
                return;
            }
        }
        buckets[idx].push_back({key,value});
    }
    
    int get(int key) {
        int idx =key%SIZE;

        for(auto &it:buckets[idx]){
            if(it.first == key)
            return it.second;

        }
        return -1;
        
    }
    
    void remove(int key) {
        int idx =key%SIZE;

        for(auto it =buckets[idx].begin();it !=buckets[idx].end();++it){
            if(it->first == key){
                buckets[idx].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */