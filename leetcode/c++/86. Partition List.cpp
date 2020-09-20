#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

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

// 空间复杂度：O(1)
// 时间复杂度：O(n)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        ListNode* large_head = NULL, *large_curr = NULL;
        ListNode* small_head = NULL, *small_curr = NULL;
        while(head) {
            if (head->val < x) {
                if (!small_head) {
                    small_head = head;
                    small_curr = small_head;
                } else {
                    small_curr->next = head;
                    small_curr = small_curr->next;
                }
            } else {
                if (!large_head) {
                    large_head = head;
                    large_curr = large_head;
                } else {
                    large_curr->next = head;
                    large_curr = large_curr->next;
                }
            }
            head = head->next;
        }
        if (small_head) {
            head = small_head;
            small_curr -> next = large_head;
        } else if(large_head){
            head = large_head;
        }
        if (large_curr) large_curr -> next = NULL;

        return head;
    }
};

int main() {
    const int len = 6;
    int arr[len] = {1,4,3,2,5,2};
    ListNode *head = createLinkedList(arr, len);
    Solution c = Solution();
    c.partition(head, 3);
}