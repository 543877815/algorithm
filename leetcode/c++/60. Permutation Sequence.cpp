// 直接回溯, 超时
class Solution {
private:
    vector<bool> visited;
    string_view res;
public:
    void DFS(int n, int k, int &count) {
        if (res.size() == n) {
            count++;
            if (k == count) return;
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                res = res.data() + to_string(i);
                DFS(n, k, count);
                if (k == count) return;
                res = res.substr(0, res.size() - 1);
                visited[i] = false;
            }
        }
    }

    string getPermutation(int n, int k) {
        visited = vector<bool>(n, false);
        int count = 0;
        DFS(n, k, count);
        return res.data();
    }
};

// 数学找规律
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    string getPermutation(int n, int k) {
        vector factorial(n, 1);
        for (int i = 1; i < n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
        k--;
        string ans;
        vector<int> valid(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            int order = k / factorial[n - i] + 1;
            for (int j = 1; j <= n; j++) {
                order -= valid[j];
                if (!order) {
                    ans += (j + '0');
                    valid[j] = 0;
                    break;
                }
            }
            k %= factorial[n - i];
        }
        return ans;
    }
};