/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        while (pHead1 && pHead2) {
            if (pHead1->val < pHead2->val) {
                curr->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                curr->next = pHead2;
                pHead2 = pHead2->next;
            }
            curr = curr->next;
        }
        if (pHead1) curr->next = pHead1;
        if (pHead2) curr->next = pHead2;
        return dummyHead->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode* dummyHead = new ListNode(-1001);
        int n = lists.size();
        for (int i = 0; i < n; i++) {
            dummyHead = Merge(lists[i], dummyHead);
        }
        return dummyHead->next;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp {
    bool operator()(ListNode*a, ListNode*b) {
        return a->val > b->val;
    }
};

// 优先队列
// 时间复杂度：O(nk)
// 空间复杂度：O(nk)
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return nullptr;

        ListNode *dummyHead = new ListNode(-1001);
        ListNode *curr = dummyHead;

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (ListNode *node: lists) {
            if (node) {
                pq.push(node);
            }
        }


        while (!pq.empty()) {
            curr->next = pq.top();
            pq.pop();
            curr = curr->next;
            if (curr->next) pq.push(curr->next);
        }

        return dummyHead->next;

    }
};