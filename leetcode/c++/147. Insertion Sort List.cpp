#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <stack>

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


// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return head;
        ListNode *dummynode = new ListNode(INT_MIN);
        dummynode->next = head;
        ListNode *pre = dummynode;
        ListNode *curr = head;
        ListNode *pre_index = curr;
        ListNode *index = pre_index->next;
        while (index) {
            pre = dummynode;
            curr = dummynode->next;
            while (true) {
                if (index->val >= pre->val && index->val < curr->val) {
                    pre->next = index;
                    pre_index->next = index->next;
                    index->next = curr;
                    index = pre_index->next;
                    break;
                } else {
                    pre = pre->next;
                    curr = curr->next;
                    if (pre == index) {
                        pre_index = index;
                        index = index->next;
                        break;
                    }
                }
            }
        }
        head = dummynode->next;
        delete dummynode;
        return head;
    }
};

int main() {
    const int len = 4;
    int arr[len] = {4, 2, 1, 3};
    ListNode *head = createLinkedList(arr, len);

    const int len2 = 5;
    int arr2[len2] = {-1, 5, 3, 4, 0};
    ListNode *head2 = createLinkedList(arr2, len2);

    Solution c = Solution();
    c.insertionSortList(head2);
}