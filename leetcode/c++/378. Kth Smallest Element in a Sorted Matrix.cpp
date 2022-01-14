// 归并排序
// 时间复杂度：O(klogn)
// 空间复杂度：O(n)
class Solution {
public:
    int kthSmallest(vector <vector<int>> &matrix, int k) {
        int n = matrix.size();
        struct point {
            int val, x, y;

            point(int val, int x, int y) : val(val), x(x), y(y) {}

            bool operator>(const point &a) const { return this->val > a.val; }
        };
        priority_queue <point, vector<point>, greater<point>> que;
        for (int i = 0; i < n; i++) {
            que.emplace(matrix[i][0], i, 0);
        }
        for (int i = 0; i < k - 1; i++) {
            point now = que.top();
            que.pop();
            if (now.y != n - 1) {
                que.emplace(matrix[now.x][now.y + 1], now.x, now.y + 1);
            }
        }

        return que.top().val;
    }
};

// 二分查找
// 时间复杂度：O(nlog(r-l))
// 空间复杂度：O(1)
class Solution {
public:
    bool check(vector <vector<int>> &matrix, int mid, int k) {
        int n = matrix.size();
        int count = 0;
        int i = n - 1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                count += i + 1;
                j++;
            } else {
                i--;
            }
        }

        return count >= k;
    }

    int kthSmallest(vector <vector<int>> &matrix, int k) {
        int n = matrix.size();
        uanc
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (check(matrix, mid, k)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};