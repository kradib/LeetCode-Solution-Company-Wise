//146. LRU Cache
//https://leetcode.com/problems/lru-cache/

class LRUCache {
    private:
    map<int,int> mymap;
    deque<int> dq;
    int capacity;
public:
    
    LRUCache(int c) {
        capacity=c;
    }
    
    int get(int key) {
        if(mymap.find(key)==mymap.end())
            return -1;
        deque<int>::iterator it;
        for(it=dq.begin();it!=dq.end();it++)
            if(*it==key)
                break;
        dq.erase(it);
        dq.push_front(key);
        return mymap[key];
    }
    
    void put(int key, int value) {
        if(mymap.find(key)!=mymap.end()){
            deque<int>::iterator it;
            for(it=dq.begin();it!=dq.end();it++)
                if(*it==key)
                    break;
            dq.erase(it);
            dq.push_front(key);
            mymap[key]=value;
        }
        else{
            if(dq.size()==capacity){
                mymap.erase(dq.back());
                dq.pop_back();
            }
            dq.push_front(key);
            mymap[key]=value;
        }
            
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */