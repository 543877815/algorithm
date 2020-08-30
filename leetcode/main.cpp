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
    string shortestPalindrome(string s) {
        int m = s.size();
        // 构建 next 数组
        vector<int> next(m, -1);
        int j = 0, i = -1;
        while (j < m - 1) {
            if (i == -1 || s[j] == s[i])
                next[++j] = ++i;
            else
                j = next[j];
        }

        // 逆序匹配
        i = m - 1; // 主串位置
        j = 0; // 模式串位置
        while (i >= 0 && j < m) {
            if (j == -1 || s[i] == s[j]) {
                i--;
                j++;
            } else {
                j = next[j];
            }
        }
        cout << j << " " << m;
        string add = (j == m ? "" : s.substr(j, m));
        reverse(add.begin(), add.end());
        return add + s;
    }
};

int main() {
    Solution solution = Solution();
    string s = "aacecaaa";
    solution.shortestPalindrome(s);
}
