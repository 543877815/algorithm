/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */




struct ListNode *create() {
    struct ListNode *T = (struct ListNode *) malloc(sizeof(struct ListNode));
    T->next = NULL;
    return T;
}


struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *root = NULL, *p = NULL;
    while (l1 && l2) {
        if (root == NULL) {
            root = create();
            p = root;
            if (l1->val < l2->val) {
                root->val = l1->val;
                l1 = l1->next;
            } else {
                root->val = l2->val;
                l2 = l2->next;
            }
        } else {
            struct ListNode *node = create();
            if (l1->val < l2->val) {
                node->val = l1->val;
                l1 = l1->next;
            } else {
                node->val = l2->val;
                l2 = l2->next;
            }
            p->next = node;
            p = p->next;
        }
    }
    while (l1) {
        if (root == NULL) {
            root = create();
            p = root;
            root->val = l1->val;
        } else {
            struct ListNode *node = create();
            node->val = l1->val;
            p->next = node;
            p = p->next;
        }
        l1 = l1->next;
    }
    while (l2) {
        if (root == NULL) {
            root = create();
            p = root;
            root->val = l2->val;
        } else {
            struct ListNode *node = create();
            node->val = l2->val;
            p->next = node;
            p = p->next;
        }
        l2 = l2->next;
    }
    return root;
}


/**
   两两合并，测试用例130超时
 */


struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (listsSize == 1) return lists[0];
    struct ListNode *head = NULL;
    for (int i = 0; i < listsSize - 1; i++) {
        if (head == NULL) head = mergeTwoLists(lists[i], lists[i + 1]);
        else head = mergeTwoLists(lists[i + 1], head);
    }
    return head;
}

/**
   归并优化
 */

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (listsSize == 1) return lists[0];
    if (listsSize == 0) return NULL;
    int interval = 1;
    while (interval < listsSize) {
        for (int i = 0; i < listsSize - interval; i = i + interval * 2) {
            lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
        }
        interval *= 2;
    }

    return lists[0];
}


// c++，优先队列

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <stack>
#include <math.h>
#include <queue>
#include <assert.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *createLinkedList(int arr[], int n) {

    if (n == 0)
        return NULL;

    ListNode *head = new ListNode(arr[0]);
    ListNode *curNode = head;
    for (int i = 1; i < n; i++) {
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;
}

struct cmp {
    bool operator()(ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return nullptr;

        ListNode *dummyhead = new ListNode(-1);
        ListNode *curr = dummyhead;

        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (ListNode *node: lists)
            if (node)
                pq.push(node);

        while (!pq.empty()) {
            curr->next = pq.top();
            pq.pop();
            curr = curr->next;
            if (curr->next) pq.push(curr->next);
        }

        return dummyhead->next;

    }
};

int main() {
    int a[3] = {1, 4, 5};
    int b[3] = {1, 3, 4};
    int c[2] = {2, 6};

    ListNode *aa = createLinkedList(a, 3);
    ListNode *bb = createLinkedList(b, 3);
    ListNode *cc = createLinkedList(c, 2);

    vector<ListNode *> lists = {aa, bb, cc};

    Solution solution = Solution();
    solution.mergeKLists(lists);


}

