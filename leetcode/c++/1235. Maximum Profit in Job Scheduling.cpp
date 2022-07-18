class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // �ع�
        int n = startTime.size();
        vector<vector<int>> nums(n, vector<int>(3, 0));
        for (int i = 0; i < n; ++i) {
            nums[i][0] = startTime[i];
            nums[i][1] = endTime[i];
            nums[i][2] = profit[i];
        }
        // ������ʱ������
        sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        // ��ʼ��dp, n + 1 ��������Խ�紦��
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            // ���ֲ���
            int l = 1, r = n;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (nums[mid - 1][1] <= nums[i - 1][0]) l = mid + 1; // l �����������ʱ��� i �Ŀ�ʼʱ����
                else r = mid - 1;
            }
            dp[i] = max(dp[i - 1], dp[l - 1] + nums[i - 1][2]);
        }
        return dp[n];
    }
};

