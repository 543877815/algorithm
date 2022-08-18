// 双向链表
// 时间复杂度：O(1)
// 空间复杂度：O(1)
struct DoubleLinkedListNode {
    int value;
    DoubleLinkedListNode *prev;
    DoubleLinkedListNode *next;
    DoubleLinkedListNode() : value(0), prev(nullptr), next(nullptr) {}
    DoubleLinkedListNode(int _value) : value(_value), prev(nullptr), next(nullptr) {}
};


class MyCircularDeque {
public:
    DoubleLinkedListNode *head;
    DoubleLinkedListNode *tail;
    int capacity;
    int size;
    MyCircularDeque(int k) {
        head = nullptr;
        tail = nullptr;
        capacity = k;
        size = 0;
    }

    bool insertFront(int value) {
        if (capacity == size) return false;
        DoubleLinkedListNode *node = new DoubleLinkedListNode(value);
        if (size == 0) {
            tail = head = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (capacity == size) return false;
        DoubleLinkedListNode *node = new DoubleLinkedListNode(value);
        if (size == 0) {
            tail = head = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        size++;
        return true;
    }

    bool deleteFront() {
        if (size == 0) return false;
        DoubleLinkedListNode *node = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete node;
        size--;
        return true;
    }

    bool deleteLast() {
        if (size == 0) return false;
        DoubleLinkedListNode *node = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        delete node;
        size--;
        return true;
    }

    int getFront() {
        if (size == 0) return -1;
        return head->value;
    }

    int getRear() {
        if (size == 0) return -1;
        return tail->value;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */