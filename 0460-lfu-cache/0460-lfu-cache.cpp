class LFUCache {
public:
    struct Node {
        int key;
        int value;
        int freq;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
        }
    };
    int capacity;
    int minFreq;
    unordered_map<int, list<Node>> freqList;
    unordered_map<int, list<Node>::iterator> keyNode;
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    int get(int key) {
        if (keyNode.find(key) == keyNode.end())
            return -1;

        auto it = keyNode[key];
        int value = it->value;
        int freq = it->freq;
        freqList[freq].erase(it);
        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }
        freqList[freq + 1].push_front(Node(key, value));
        keyNode[key] = freqList[freq + 1].begin();
        keyNode[key]->freq = freq + 1;
        return value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;
        if (keyNode.find(key) != keyNode.end()) {
            keyNode[key]->value = value;
            get(key);               
            return;
        }
        if (keyNode.size() == capacity) {

            auto node = freqList[minFreq].back();

            keyNode.erase(node.key);
            freqList[minFreq].pop_back();

            if (freqList[minFreq].empty())
                freqList.erase(minFreq);
        }
        minFreq = 1;
        freqList[1].push_front(Node(key, value));
        keyNode[key] = freqList[1].begin();
    }
};