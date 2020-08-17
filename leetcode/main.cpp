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

class MedianFinder {
private:
    vector<int> min_heap;
    vector<int> max_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        // 如果是偶数
        if ((min_heap.size() + max_heap.size() && 1) == 0) {
            if (max_heap.size() > 0 && num < max_heap[0]) {
                max_heap.push_back(num);
                push_heap(max_heap.begin(), max_heap.end(), less<int>());

                num = max_heap[0];

                pop_heap(max_heap.begin(), max_heap.end(), less<int>());
                max_heap.pop_back();
            }
            min_heap.push_back(num);
            push_heap(min_heap.begin(), min_heap.end(), greater<int>());
        } else { // 如果是奇数
            if (min_heap.size() > 0 && min_heap[0] < num) {
                min_heap.push_back(num);
                push_heap(min_heap.begin(), min_heap.end(), greater<int>());

                num = min_heap[0];

                pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
                min_heap.pop_back();
            }
            max_heap.push_back(num);
            push_heap(max_heap.begin(), max_heap.end(), less<int>());
        }
    }

    double findMedian() {
        int size = min_heap.size() + max_heap.size();

        double median = 0;
        if ((size & 1) == 1) median = min_heap[0]; // 如果是奇数
        else median = (min_heap[0] + max_heap[0]) / 2; // 如果是偶数
        return median;
    }
};

int main() {
    Codec solution = Codec();
    TreeNode *root = new TreeNode(-1);
    TreeNode *two = new TreeNode(0);
    TreeNode *three = new TreeNode(1);
    TreeNode *four = new TreeNode(4);
    TreeNode *five = new TreeNode(5);
    root->left = two;
    root->right = three;
    three->left = four;
    three->right = five;
    string res = solution.serialize(root);
    TreeNode *aaa = solution.deserialize(res);
}
