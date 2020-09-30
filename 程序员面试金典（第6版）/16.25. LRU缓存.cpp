struct DoubleLinkedListNode {
    int key, value;
    DoubleLinkedListNode *prev;
    DoubleLinkedListNode *next;

    DoubleLinkedListNode() : key(0), value(0), prev(nullptr), next(nullptr) {}

    DoubleLinkedListNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList {
private:
    DoubleLinkedListNode *head;
    DoubleLinkedListNode *tail;
    int size;

public:
    DoubleLinkedList() {
        head = new DoubleLinkedListNode();
        tail = new DoubleLinkedListNode();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addLast(DoubleLinkedListNode *x) {
        x->prev = tail->prev;
        x->next = tail;
        tail->prev->next = x;
        tail->prev = x;
        size++;
    }

    void remove(DoubleLinkedListNode *x) {
        x->next->prev = x->prev;
        x->prev->next = x->next;
        size--;
    }

    DoubleLinkedListNode *removeFirst() {
        if (head->next == tail) return nullptr;
        DoubleLinkedListNode *first = head->next;
        remove(first);
        return first;
    }

    int capacity() {
        return this->size;
    }
};

class LRUCache {
private:
    unordered_map<int, DoubleLinkedListNode *> Map;
    DoubleLinkedList *cache;
    int capacity;

    /* 将某个 key 提升为最近使用的 */
    void makeRecently(int key) {
        DoubleLinkedListNode *x = Map[key];
        // 先从链表中删除这个节点
        cache->remove(x);
        // 重新插到队尾
        cache->addLast(x);
    }

    /* 添加最近使用的元素 */
    void addRecently(int key, int val) {
        DoubleLinkedListNode *x = new DoubleLinkedListNode(key, val);
        // 链表尾部就是最近使用的元素
        cache->addLast(x);
        // 别忘了在 map 中添加 key 的映射
        Map[key] = x;
    }

    /* 删除某一个 key */
    void deleteKey(int key) {
        DoubleLinkedListNode *x = Map[key];
        // 从链表中删除
        cache->remove(x);
        // 从 map 中删除
        Map.erase(key);
    }

    /* 删除最久未使用的元素 */
    void removeLeastRecently() {
        // 链表头部的第一个元素就是最久未使用的
        DoubleLinkedListNode *deleteNode = cache->removeFirst();
        // 同时别忘了从 map 中删除它的 key
        int deleteKey = deleteNode->key;
        Map.erase(deleteKey);
    }

public:

    LRUCache(int capacity) {
        this->capacity = capacity;
        cache = new DoubleLinkedList();
    }

    int get(int key) {
        if (Map.count(key) == 0) return -1;
        // 将该数据提升为最近使用的
        makeRecently(key);
        return Map[key]->value;

    }

    void put(int key, int value) {
        if (Map.count(key) != 0) {
            // 删除旧的数据
            deleteKey(key);
            // 新插入的数据为最近使用的数据
            addRecently(key, value);
            return;
        }

        if (capacity == cache->capacity()) {
            // 删除最久未使用的元素
            removeLeastRecently();
        }

        // 添加为最近使用的元素
        addRecently(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */