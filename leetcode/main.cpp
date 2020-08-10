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

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

bool compare(const Interval &a, const Interval &b) {
    if (a.end != b.end) return a.end < b.end;
    return a.end < b.end;
}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval> &intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        sort(intervals.begin(), intervals.end(), compare);

        // dp[i]表示使用intervals[0...i]的区间能构成的最长不重叠序列
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            // dp[i]
            for (int j = 0; j < i; j++) {
                if (intervals[i].start >= intervals[j].end) {
                    dp[i] = max(dp[i], dp[i] + 1);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, dp[i]);
        }

        return n - res;
    }
};


int main() {
    Solution solution = Solution();
    vector<vector<int>> nums = {{1,2}, {2,3}, {3,4}, {1,3}};
    int S = 3;
    solution.eraseOverlapIntervals(nums);
}
