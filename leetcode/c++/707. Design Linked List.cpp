// struct ListNode {
//     int val;
//     ListNode *next;

//     ListNode(int x) : val(x), next(NULL) {}
// };

class MyLinkedList {
private:
    ListNode *dummyNode;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        dummyNode = new ListNode();
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode *root = dummyNode->next;
        while (index != 0 && root) {
            root = root->next;
            index--;
        }
        return (index == 0 && root) ? root->val : -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *root = dummyNode->next;
        ListNode *newNode = new ListNode(val);
        newNode->next = root;
        dummyNode->next = newNode;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *pre = dummyNode;
        ListNode *curr = dummyNode->next;
        while (curr) {
            pre = curr;
            curr = curr->next;
        }
        ListNode *newNode = new ListNode(val);
        pre->next = newNode;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode *pre = dummyNode;
        ListNode *curr = dummyNode->next;
        while (index != 0 && curr) {
            pre = curr;
            curr = curr->next;
            index--;
        }
        ListNode *newNode = new ListNode(val);
        pre->next = newNode;
        newNode->next = curr;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        ListNode *pre = dummyNode;
        ListNode *curr = dummyNode->next;
        while (index != 0 && curr) {
            pre = curr;
            curr = curr->next;
            index--;
        }
        if (curr) pre->next = curr->next;
        delete curr;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */