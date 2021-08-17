// trick
// 时间复杂度：O(1)
// 空间复杂度：O(n)
class Solution {
public:
    int table[16] = {0, 1, 2, 3, 8, 10, 36, 41, 132, 250, 700, 750, 4010, 4237, 10680, 24679};

    int countArrangement(int N) {
        return table[N];
    }
};

// 回溯
// 时间复杂度：O(n!)
// 空间复杂度：O(n^2)
class Solution {
public:
    int res = 0;

    void backward(vector<bool> &visited, int index) {
        int n = visited.size();
        if (index == n) {
            res++;
            return;
        }
        for (int i = 1; i < n; i++) {
            if (visited[i]) continue;
            if (i % index == 0 || index % i == 0) {
                visited[i] = true;
                backward(visited, index + 1);
                visited[i] = false;
            }
        }
    }

    int countArrangement(int n) {
        vector<bool> visited = vector<bool>(n + 1, false);
        backward(visited, 1);
        return res;
    }
};

// 动态规划
// 时间复杂度：O(nx2^n)
// 空间复杂度：O(2^n)
class Solution {
public:
    // 若 mask 中的第 i 位为 1（从 0 开始编号），则数 i+1 已经被选取，否则就还未被选取。
    int countArrangement(int n) {
        vector<int> f(1 << n); // 令 f[mask] 表示状态为 mask 时的可行方案总数
        f[0] = 1;
        for (int mask = 1; mask < (1 << n); mask++) {  // mask表示被选取情况
            int num = __builtin_popcount(mask); // 统计已经遍历的个数, 第i个位置
            for (int i = 0; i < n; i++) {
                // mask & (1<<i) 用来判断 mask 第 i 位是否为 1，如果为 1，说明第 i+1 个数字被选取
                if (mask && (1 << i) && (num % (i+1) == 0 || (i+1) % num == 0)) {
                    // 第 i+1 个数字被选取的方案数等于其加上第 i+1 个数字没被选取的方案数
                    f[mask] += f[mask ^ (1 << i)];
                }
            }
        }
        return f[(1<<n) - 1];
    }
};