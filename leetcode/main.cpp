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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int reverseBits(int num) {
        int count = 0;
        vector<int> nums;
        while (num) {
            if (num & 1) {
                count++;
            } else {
                nums.push_back(count);
                count = 0;
                nums.push_back(count);
            }
            num = num >> 1;
        }
        nums.push_back(count);
        int res = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                int tmp = 1;
                if (i != 0) {
                    tmp += nums[i - 1];
                }
                if (i != nums.size() - 1) {
                    tmp += nums[i + 1];
                }
                res = max(res, tmp);
            }
        }
        return res;
    }
};

int main() {
    auto *solution = new Solution();

    solution->reverseBits(7);
}
