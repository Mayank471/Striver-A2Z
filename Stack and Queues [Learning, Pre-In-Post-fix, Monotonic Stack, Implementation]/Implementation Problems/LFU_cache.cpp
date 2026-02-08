class LFUCache {
public:
    int capacity;
    int minFreq;

    // key -> {value, freq}
    unordered_map<int, pair<int,int>> keyInfo;

    // freq -> list of keys (LRU order)
    unordered_map<int, list<int>> freqList;

    // key -> iterator in its freq list
    unordered_map<int, list<int>::iterator> pos;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (capacity == 0 || !keyInfo.count(key)) return -1;

        int value = keyInfo[key].first;
        int freq = keyInfo[key].second;

        // remove from old freq list
        freqList[freq].erase(pos[key]);

        // if it was minFreq and becomes empty
        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq) minFreq++;
        }

        // move to next freq
        freq++;
        keyInfo[key].second = freq;
        freqList[freq].push_back(key);
        pos[key] = --freqList[freq].end();

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyInfo.count(key)) {
            keyInfo[key].first = value;
            get(key);  // bump frequency
            return;
        }

        // eviction
        if (keyInfo.size() == capacity) {
            int evict = freqList[minFreq].front();
            freqList[minFreq].pop_front();
            if (freqList[minFreq].empty()) {
                freqList.erase(minFreq);
            }
            keyInfo.erase(evict);
            pos.erase(evict);
        }

        // insert new key
        keyInfo[key] = {value, 1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1;
    }
};
