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
ListNode* createLinkedList(int arr[], int n){

    if(n == 0)
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curNode = head;
    for(int i = 1 ; i < n ; i ++){
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        struct ListNode *prev = NULL;
        struct ListNode *curr = head;
        struct ListNode *nextTemp = NULL;
        while(curr) {
            nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        stack<int> num1, num2;
        while (l1) {
            num1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            num2.push(l2->val);
            l2 = l2->next;
        }

        ListNode *res = nullptr, *curr = nullptr;
        int carry = 0;
        int sum = 0;
        while (!num1.empty() && !num2.empty()) {
            sum = num1.top() + num2.top() + carry;
            if (!res) {
                res = new ListNode(sum % 10);
                curr = res;
            } else {
                curr->next = new ListNode(sum % 10);
                curr = curr->next;
            }
            carry = sum / 10;
            num1.pop();
            num2.pop();
        }

        while (!num1.empty()) {
            sum = num1.top() + carry;
            if (!res) {
                res = new ListNode(sum % 10);
                curr = res;
            } else {
                curr->next = new ListNode(sum % 10);
                curr = curr->next;
            }
            carry = sum / 10;
            num1.pop();
        }

        while (!num2.empty()) {
            sum = num2.top() + carry;
            if (!res) {
                res = new ListNode(sum % 10);
                curr = res;
            } else {
                curr->next = new ListNode(sum % 10);
                curr = curr->next;
            }
            carry = sum / 10;
            num2.pop();
        }

        if (carry != 0) {
            curr->next = new ListNode(carry);
            curr = curr->next;
        }

        return reverseList(res);
    }
};


int main() {
    const int len = 4;
    int arr[len] = {7, 2, 4, 3};
    ListNode *head = createLinkedList(arr, len);

    const int len2 = 3;
    int arr2[len2] = {5, 6, 4};
    ListNode *head2 = createLinkedList(arr2, len2);

    Solution c = Solution();
    c.addTwoNumbers(head, head2);
}