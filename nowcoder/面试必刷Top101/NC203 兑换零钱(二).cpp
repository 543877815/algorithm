// ��ʱ
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param target int����
     * @param nums int����vector
     * @return int����
     */

    int res = 0;

    void search(int target, vector<int> &nums, int idx) {
        if (target == 0) {
            res++;
            return;
        }
        int n = nums.size();
        for (int i = idx; i < n; i++) {
            if (target - nums[i] >= 0) {
                search(target - nums[i], nums, i);
            }
        }
    }

    int change(int target, vector<int> &nums) {
        // write code here
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        search(target, nums, 0);
        return res;
    }
};

// ��̬�滮
// ʱ�临�Ӷȣ�O(n)
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param target int����
     * @param nums int����vector
     * @return int����
     */
    int change(int target, vector<int> &nums) {
        // write code here
        int n = nums.size();
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= target; i++) {
                if (i - nums[j] >= 0) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};