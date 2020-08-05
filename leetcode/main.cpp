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


//class Solution {
//public:
//    string multiply(string num1, string num2) {
//        reverse(num1.begin(), num1.end());
//        reverse(num2.begin(), num2.end());
//        int index1 = 0, index2 = 0, count = 0;
//        string res;
//        while (index1 < num1.size() && index2 < num2.size()) {
//            int next = (num1[index1++] - '0') * (num2[index2++] - '0') + count;
//            count = next / 10;
//            res += to_string(next % 10);
//        }
//
//        while (index1 < num1.size()) {
//            int next = num1[index1++] - '0' + count;
//            count = next / 10;
//            res += to_string(next % 10);
//        }
//
//        while (index2 < num2.size()) {
//            int next = num2[index2++] - '0' + count;
//            count = next / 10;
//            res += to_string(next % 10);
//        }
//
//        reverse(res.begin(), res.end());
//
//        return res;
//    }
//};


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

class Solution {
private:
    int d[4][2] = {
            {1,  0},
            {-1, 0},
            {0,  1},
            {0,  -1}};
    vector<vector<int>> res;
    int n, m;
    bool left_up;
    bool right_down;
    vector<vector<bool>> visited;

    bool isArea(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    void DFS(vector<vector<int>> &matrix, int x, int y) {
        if (x == 0 || y == 0) left_up = true;
        if (x == n - 1 || y == m - 1) right_down = true;
        if (left_up && right_down) return;

        for (int i = 0; i < 4; i++) {
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if (isArea(newx, newy) && !visited[newx][newy] && matrix[x][y] >= matrix[newx][newy]) {
                visited[x][y] = true;
                DFS(matrix, newx, newy);
                visited[x][y] = false;
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
        n = matrix.size();
        if (n == 0) return res;
        m = matrix[0].size();
        if (m == 0) return res;
        if (n == 1 || m == 1) return matrix;
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                left_up = false;
                right_down = false;
                if (i == 2 && j == 3) {
                    DFS(matrix, i, j);
                }
                if (left_up, right_down)
                    res.push_back({i, j});
            }
        }

        return res;
    }
};

int main() {
    Solution solution = Solution();
    string a = "aab";
    vector<vector<int>> d = {{1, 2, 2, 3, 5},
                             {3, 2, 3, 4, 4},
                             {2, 4, 5, 3, 1},
                             {6, 7, 1, 4, 5},
                             {5, 1, 1, 2, 4}};
    solution.pacificAtlantic(d);
}

