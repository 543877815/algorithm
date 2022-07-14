// 单链表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
#include<iostream>
#include<unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main() {
    unordered_map<int, ListNode *> hashmap;
    int num, head;
    cin >> num >> head;
    ListNode *root = new ListNode(head);
    hashmap[head] = root;
    for (int i = 1; i < num; i++) {
        int a, b;
        cin >> a >> b;
        ListNode *curr = hashmap[b];
        ListNode *inserted = new ListNode(a);
        hashmap[a] = inserted;
        inserted->next = curr->next;
        curr->next = inserted;
    }
    ListNode *dummyHead = new ListNode(-1, root);
    int c;
    cin >> c;

    ListNode *pre = dummyHead;
    while (pre && pre->next && pre->next->val != c) {
        pre = pre->next;
    }
    pre->next = pre->next->next;

    pre = dummyHead;
    while (pre->next) {
        cout << pre->next->val << " ";
        pre = pre->next;
    }
    return 0;
}