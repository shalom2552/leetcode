/*
Motivation: map, and heap.
    Using two map for the cache values and heap for the timestamp of the keys.
    On cunstruct we save the capacity and initizlize timestamp to 0.
    On get we return update both map and heap timestamps of the key to the current ts.
    On put we update as in get but remove the oldest if capacity exceeded.
    In the cache map we save as the value a pair with the cache value and the ts.
Complexity:
    Time - O(log(n)): Erasing from the heap.
    Space - O(n): the cache and the heap.
*/
class LRUCache {
public:
    LRUCache(int capacity)
        : m_timestamp(1)
        , m_capacity(capacity)
    {
        m_cache.reserve(capacity + 1);
    }
    
    int get(int key) {
        auto it = m_cache.find(key);
        if (it == m_cache.end()) return -1;

        update_timestamp(key);
        it->second.second = m_timestamp;
        return it->second.first;
    }
    
    void put(int key, int value) {    
        update_timestamp(key);
        m_cache[key] = {value, m_timestamp};
        remove_oldest();        
    }

private:
    /* update the timestamp of a key in the cache */
    void update_timestamp(const int key) {
        ++m_timestamp;
        m_heap.erase(m_cache[key].second);
        m_heap[m_timestamp] = key;
    }

    /* remove the oldest value in the cache */
    void remove_oldest(void) {
        if (m_cache.size() > m_capacity) {
            auto oldest = m_heap.begin();
            m_cache.erase(oldest->second);
            m_heap.erase(oldest);
        }
    }

private:
    int m_capacity;
    uint64_t m_timestamp;
    map<uint64_t, int> m_heap; // ts: key
    unordered_map<int, pair<int, uint64_t>> m_cache; // key: {val, ts}
};
