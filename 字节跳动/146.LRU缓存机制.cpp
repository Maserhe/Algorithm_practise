struct DLinkedNode {
    int key;
    int value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int _capacity) : capacity(_capacity), size(0) {
        head = new DLinkedNode(); // dummy head for quick pinpoint/positioning
        tail = new DLinkedNode(); // dummy tail for quick pinpoint/positioning
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }

        DLinkedNode* node = cache[key];
        moveToHead(node); // visited, update to head
        return node->value;
    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if (size > capacity) {
                // 删除双向列表的尾部元素
                DLinkedNode* removed = removeTail();
                // 删除哈希表中对应的元素
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        } else {
            // already exist
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Thanks to dummy tail, no need to 
    // worry node->next is empty case
    void untieNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        untieNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        auto node = tail->prev;
        untieNode(node);
        return node;
    }

private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head; // pseudo head
    DLinkedNode* tail; // pseudo head
    int size;
    int capacity;
};