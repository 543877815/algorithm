/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (!headA || !headB) return NULL;
    struct ListNode *tail = headA;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = headB;
    struct ListNode *circle = tail;

    while (circle->next) {
        circle = circle->next;
        if (circle == tail) { // 如果有环
            struct ListNode *slow = headA;
            struct ListNode *fast = headA;
            do {// 找相遇点
                slow = slow->next;
                fast = fast->next->next;
            } while (slow != fast);
            // 再追一次...
            slow = headA;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            tail->next = NULL;
            return slow;
        }
    }
    tail->next = NULL;
    return NULL;
}


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length1 = 0;
        ListNode *tmp = headA;
        while (tmp) {
            tmp = tmp->next;
            length1++;
        }
        int length2 = 0;
        tmp = headB;
        while (tmp) {
            tmp = tmp->next;
            length2++;
        }

        if (length1 > length2) {
            int dis = length1 - length2;
            while (dis && headA) {
                headA = headA->next;
                dis--;
            }
        } else {
            int dis = length2 - length1;
            while (dis && headB) {
                headB = headB->next;
                dis--;
            }
        }

        while (headA != headB && headA && headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};
