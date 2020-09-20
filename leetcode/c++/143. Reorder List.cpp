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

// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        // 找中间结点
        ListNode *slow = head, *fast = head, *pre = new ListNode(0);
        pre->next = slow;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // 倒置
        slow = reverseList(slow);
        // 合并
        pre->next = NULL;
        ListNode *curr1 = head, *curr2 = slow;
        while (slow && curr1) {
            curr2 = slow;
            slow = slow->next;
            curr2->next = curr1->next;
            curr1->next = curr2;
            curr1 = curr2->next;
        }
        curr2 ->next = slow;

        int a = 0;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = curr->next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

int main() {
    const int length = 4;
    int a[length] = {1, 2, 3, 4};
    ListNode *b = createLinkedList(a, length);
    Solution c = Solution();
    c.reorderList(b);
}