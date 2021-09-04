// 寻找链表中间、反转链表、链表重组
// 时间复杂度：O(n)
// 空间复杂度：O(1)
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <cstring>
#include <numeric>
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
    struct ListNode *reverseList(struct ListNode *head) {
        struct ListNode *prev = NULL;
        struct ListNode *curr = head;
        struct ListNode *nextTemp = NULL;
        while (curr) {
            nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    void reorderList(ListNode *head) {
        int len = 0;
        ListNode *pre = new ListNode(-1);
        pre->next = head;
        ListNode *curr = head;
        while (curr) {
            len++;
            curr = curr->next;
        }
        curr = head;
        int half = len / 2;
        while (half != 0) {
            half--;
            curr = curr->next;
            pre = pre->next;
        }
        pre->next = NULL;
        ListNode *halfCurr = reverseList(curr);

        curr = head;
        while (curr && halfCurr) {
            ListNode *currNext = curr->next;
            ListNode *halfNext = halfCurr->next;
            curr->next = halfCurr;
            halfCurr->next = currNext ? currNext : halfCurr->next;
            curr = currNext;
            halfCurr = halfNext;
        }
    }
};

int main() {
    const int len = 2;
    int arr[len] = {1, 2};
    ListNode *head = createLinkedList(arr, len);

    const int len2 = 4;
    int arr2[len2] = {1, 2, 3, 4};
    ListNode *head2 = createLinkedList(arr2, len2);

    Solution c = Solution();
    c.reorderList(head);
}