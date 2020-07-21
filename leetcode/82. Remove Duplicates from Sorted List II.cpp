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

// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        unordered_map<int, int> record;
        ListNode *curr = head;
        while (curr) {
            record[curr->val]++;
            curr = curr->next;
        }

        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode *pre = dummyHead;
        curr = head;

        while (curr) {
            if (record.find(curr->val) != record.end() && record[curr->val] > 1) {
                pre->next = curr->next;
                ListNode *del = curr;
                curr = curr->next;
                delete del;
            } else {
                pre = pre->next;
                curr = curr->next;
            }
        }

        head = dummyHead->next;
        return head;
    }
};

int main() {
    const int len = 5;
    int arr[len] = {1, 1, 1, 2, 3};
    ListNode *head = createLinkedList(arr, len);

    const int len2 = 7;
    int arr2[len2] = {1, 2, 3, 3, 4, 4, 5};
    ListNode *head2 = createLinkedList(arr2, len2);

    Solution c = Solution();
    c.deleteDuplicates(head);
}