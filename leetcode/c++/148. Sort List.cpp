// 递归
// 时间复杂度O(nlogn)
// 空间复杂度O(n)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* pre = head, *slow = head, *fast = head;
        while(fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        return mergeTwoList(sortList(head), sortList(slow));
    }
    ListNode* mergeTwoList(ListNode* h1, ListNode* h2) {
        if(!h1) return h2;
        if(!h2) return h1;
        if(h1->val < h2->val) {
            h1->next = mergeTwoList(h1->next, h2);
            return h1;
        } else {
            h2->next = mergeTwoList(h1, h2->next);
            return h2;
        }
    }
};


// 使用循环
// 时间复杂度：O(nlogn)
// 空间复杂度：O(1)
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

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// 根据n个元素的数组arr创建一个链表, 并返回链表的头
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



class Solution {
public:
    ListNode *sortList(ListNode *head) {
        int length = 0, count = 0, count1, count2, div = 1;
        ListNode *tmp = head, *res = new ListNode(INT_MIN);
        res->next = head;
        while (tmp) {
            length++;
            tmp = tmp->next;
        }

        while (div < length) {
            ListNode *pre = res, *curr = res->next;
            while (curr) {
                ListNode *curr1 = curr;
                count = div;
                while (curr && count) {
                    count--;
                    curr = curr->next;
                }

                if (count) break;

                ListNode *curr2 = curr;
                count = div;
                while (curr && count) {
                    count--;
                    curr = curr->next;
                }
                count1 = div;
                count2 = div - count;
                while (count1 && count2) {
                    if (curr1->val < curr2->val) {
                        pre->next = curr1;
                        curr1 = curr1->next;
                        count1--;
                    } else {
                        pre->next = curr2;
                        curr2 = curr2->next;
                        count2--;
                    }
                    pre = pre->next;
                }
                pre->next = count1 != 0 ? curr1 : curr2;
                while (count1 > 0 || count2 > 0) {
                    pre = pre->next;
                    count1--;
                    count2--;
                }
                pre->next = curr;
            }
            div *= 2;
        }
        return res->next;
    }
};

int main() {
    int a[4] = {4,2,1,3};
    ListNode *b = createLinkedList(a, 4);
    Solution c = Solution();
    c.sortList(b);
}