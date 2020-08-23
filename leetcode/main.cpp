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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = l1;
        ListNode *pre = NULL;
        int count = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + count;
            count = sum / 10;
            l1->val = sum % 10;
            if (!l1->next) pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            int sum = l1->val + count;
            count = sum / 10;
            l1->val = sum % 10;
            if (!l1->next) pre = l1;
            l1 = l1->next;
        }

        while (l2) {
            int sum = l2->val + count;
            count = sum / 10;
            pre->next = new ListNode(sum % 10);
            pre = pre->next;
            l2 = l2->next;
        }

        if (count != 0) pre->next = new ListNode(count);

        return res;
    }
};

int main() {
    ListNode *a = new ListNode(5);
    ListNode *b = new ListNode(5);
    Solution solution = Solution();
    solution.addTwoNumbers(a, b);
}
