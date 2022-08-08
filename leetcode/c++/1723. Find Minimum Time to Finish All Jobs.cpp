// ����
// ʱ�临�Ӷȣ�O(nlogn+log(S-M)xk^n)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    bool backtrack(vector<int> &jobs, vector<int> &workloads, int idx, int limit) {
        if (idx >= jobs.size()) return true;
        int cur = jobs[idx];
        for (auto &workload: workloads) {
            if (workload + cur <= limit) {
                workload += cur;
                if (backtrack(jobs, workloads, idx + 1, limit)) return true;
                workload -= cur;
            }
            if (workload == 0 || workload + cur == limit) break;
        }

        return false;
    }

    bool check(vector<int> &jobs, int k, int limit) {
        vector<int> workloads(k, 0);
        return backtrack(jobs, workloads, 0, limit);
    }

    int minimumTimeRequired(vector<int> &jobs, int k) {
        int n = jobs.size();
        sort(jobs.begin(), jobs.end(), greater<int>());
        int l = jobs[0], r = accumulate(jobs.begin(), jobs.end(), 0);
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(jobs, k, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

// ��̬�滮+״̬ѹ��
// ʱ�临�Ӷȣ�O(nx3^n)
// �ռ临�Ӷȣ�O(nx2^n)
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> sum(1 << n);
        for (int i = 1; i < (1 << n); i++) {
            int x = __builtin_ctz(i), y = i - (1 << x);  // x��ʾѡi��y��ʾ��ѡi
            sum[i] = sum[y] + jobs[x];  // ����ǰ׺��
        }

        vector<vector<int>> dp(k, vector<int>(1 << n)); // dp[i][j] ��ʾ��ǰi���˷��乤���������ķ������Ϊjʱ��������й��������ʱ�䡣
        for (int i = 0; i < (1 << n); i++) {
            dp[0][i] = sum[i];
        }

        for (int i = 1; i < k; i++) {   // ����Ա��
            for (int j = 0; j < (1 << n); j++) {   // ��������Ĺ���
                int minn = INT_MAX;
                for (int x = j; x; x = (x - 1) & j) {   // ������С�����Ŀ�����
                    minn = min(minn, max(dp[i - 1][j - x], sum[x]));
                }
                dp[i][j] = minn;
            }
        }

        return dp[k-1][(1 << n) - 1];
    }
};