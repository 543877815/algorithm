// 时间复杂度：O(k)
// 空间复杂度：O(nm)
// 模拟
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int up = 0, down = m - 1, left = 0, right = n - 1;
        int direction = 1;
        int i = 0, j = 0;
        while (head) {
            res[i][j] = head->val;
            if (direction == 1) {  // towards right
                j++;
                if (j == right + 1) {
                    j--;
                    i++;
                    up++;
                    direction = 2;
                }
            } else if (direction == 2) { // towards down
                i++;
                if (i == down + 1) {
                    i--;
                    j--;
                    right--;
                    direction = 3;

                }
            } else if (direction == 3) { // towards left
                j--;
                if (j == left - 1) {
                    j++;
                    i--;
                    down--;
                    direction = 4;
                }
            } else if (direction == 4) { // towards up
                i--;
                if (i == up - 1) {
                    i++;
                    j++;
                    left++;
                    direction = 1;
                }
            }
            head = head->next;
        }

        return res;
    }
};