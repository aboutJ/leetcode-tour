#include "header.h"

/*
    请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
    实现 LRUCache 类：
        LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
        int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
        void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
        函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

*/

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        for(vector<pair<int, int> >::iterator it = cache.begin();it != cache.end();it++) {
            if((*it).first == key) {
                const int result = (*it).second;
                cache.erase(it);
                cache.push_back(pair<int, int>(key, result));
                return result;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(capacity == cache.size()) {
            bool isTarget = false;
            for(vector<pair<int, int> >::iterator it = cache.begin();it != cache.end();it++) {
                if((*it).first == key) {
                    cache.erase(it);
                    isTarget = true;
                    break;
                }
            }
            if (isTarget == false) {
                cache.erase(cache.begin());
            }
            
        } else {
            for(vector<pair<int, int> >::iterator it = cache.begin();it != cache.end();it++) {
                if((*it).first == key) {
                    cache.erase(it);
                    break;
                }
            }
        }
        cache.push_back(pair<int, int>(key, value));
    }
private:
    vector<pair<int, int> > cache;
    int capacity;
};

int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    lru.get(1);
    lru.put(3, 3);
    return 0;
}