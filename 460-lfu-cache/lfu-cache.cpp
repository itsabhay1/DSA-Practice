class LFUCache {
private:
    struct Node {
        int key, value, freq;
        Node *prev, *next;
        Node(int key, int value) {
            freq = 1;
            this->key = key;
            this->value = value;
            prev = next = nullptr;
        }
    };

    struct FreqDLL {                  // stores nodes of same freq for lru with same freq
        Node *head;
        Node *tail;
        int size;

        FreqDLL(): size(0) {
            head = new Node(-1,-1);
            tail = new Node(-1,-1);
            head->next = tail;
            tail->prev = head;
        }

        ~FreqDLL() {
            delete head;
            delete tail;
        }

        void addNode(Node* node){               // adding to front of freq DLL
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            size++;
        }

        void removeNode(Node* node){
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }

        Node* removeLRU(){
            if(size==0) return nullptr;
            Node* lru = tail->prev;
            removeNode(lru);
            return lru;
        }

    };

    int capacity, minFreq;
    unordered_map<int, Node*>mpp;          // key -> node
    unordered_map<int, FreqDLL*>freqMap;       // freq -> list of nodes

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* node){
        int oldFreq = node->freq;
        FreqDLL* oldList = freqMap[oldFreq];
        oldList->removeNode(node);

        if(oldList->size == 0){
            if(oldFreq == minFreq) minFreq++;
            delete oldList;
            freqMap.erase(oldFreq);
        }

        node->freq++;
        if(freqMap.find(node->freq) == freqMap.end()){
            freqMap[node->freq] = new FreqDLL();
        }
        freqMap[node->freq]->addNode(node);
    }
    
    int get(int key) {
        if(capacity == 0 || mpp.find(key) == mpp.end()){
            return -1;
        }
        Node* node = mpp[key];
        updateFreq(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;

        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        if(mpp.size() == capacity){        // if full capacity then we delete lru with min freq
            FreqDLL* minList = freqMap[minFreq];
            Node* lru = minList->removeLRU();
            mpp.erase(lru->key);
            delete lru;

            if(minList->size == 0){
                delete minList;
                freqMap.erase(minFreq);
            }
        }
        Node* newNode = new Node(key,value);
        mpp[key] = newNode;
        minFreq = 1;
        if(freqMap.find(minFreq) == freqMap.end()){
            freqMap[minFreq] = new FreqDLL();
        }
        freqMap[minFreq]->addNode(newNode);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */