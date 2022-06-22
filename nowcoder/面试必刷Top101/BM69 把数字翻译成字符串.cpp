// ��̬�滮
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
/*
 *  step 1���ø�������dp��ʾǰi���������뷽���ж����֡�
 *  step 2������һ���������ǿ���ֱ����������Ҳ���Խ�����ǰ���1����2����������룺���ֱ�����룬��dp[i]=dp[i?1]�����������룬��dp[i]=dp[i?2]��
 *  step 3������ֻ��һ�����뷽ʽ�ģ�ѡ����dp[i?1]���ɣ����������������뷽ʽ��10��20���ܣ�����dp[i?1]+dp[i?2]
 *  step 4��������ӣ�����dp[length]��Ϊ����𰸡�
 */
class Solution {
public:
    /**
     * ����
     * @param nums string�ַ��� ���ִ�
     * @return int����
     */
    int solve(string nums) {
        // write code here
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) {
            if (nums[0] == '0') return 0;
            else return 1;
        };
        vector<int> dp(n);
        dp[0] = 1;
        if (nums[1] == '0') {
            dp[1] = dp[0];
        } else if (nums[0] == '1' || (nums[0] == '2' && nums[1] <= '6')) {
            dp[1] = 2;
        } else {
            dp[1] = dp[0];
        }

        for (int i = 2; i < n; i++) {
            if (nums[i] == '0') {
                if (nums[i-1] > '2') return 0;
                dp[i] = dp[i-1];
            } else if (nums[i-1]=='1' && nums[i] != '0') {
                dp[i] = dp[i-2] + dp[i-1];
            } else if (nums[i-1]=='2'&& nums[i] <='6' && nums[i] > '0') {
                dp[i] = dp[i-2] + dp[i-1];
            } else {
                dp[i] = dp[i-1];
            }
        }

        return dp[n-1];
    }
};