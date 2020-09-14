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
private:
    int dp[4][2] = {
            {1,  0},
            {0,  1},
            {-1, 0},
            {0,  -1}
    };
    int m, n;
    vector<vector<int>> visited;

    bool isArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void DFS(vector<vector<int>> &image, int x, int y, int oldColor, int newColor) {
        image[x][y] = newColor;
        for (int i = 0; i < 4; i++) {
            int newx = x + dp[i][0];
            int newy = y + dp[i][1];
            if (isArea(newx, newy) && !visited[newx][newy] && image[newx][newy] == oldColor) {
                visited[newx][newy] = true;
                DFS(image, newx, newy, oldColor, newColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        m = image.size();
        if (m == 0);
        return image;
        n = image[0].size();
        if (n == 0) return image;
        visited = vector<vector<int>>(m, vector<int>(n, false));
        DFS(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};

int main() {
    auto *solution = new Solution();

    solution->reverseBits(7);
}
