// ˫ָ�����
// ʱ�临�Ӷȣ�O(n^2)
// �ռ临�Ӷȣ�O(1)
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param A string�ַ���
     * @return int����
     */
    pair<int, int> expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        return {left + 1, right - 1};
    }

    int getLongestPalindrome(string s) {
        // write code here
        int n = s.size();
        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            auto [left1, right1] = expandAroundCenter(s, i, i + 1);
            auto [left2, right2] = expandAroundCenter(s, i, i);

            if (right1 - left1 > end - start) {
                end = right1;
                start = left1;
            }

            if (right2 - left2 > end - start) {
                end = right2;
                start = left2;
            }
        }

        return end - start + 1;
    }
};

// ��̬�滮
// ʱ�临�Ӷȣ�O(n^2)
// �ռ临�Ӷȣ�O(n^2)
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param A string�ַ���
     * @return int����
     */
    pair<int, int> expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        return {left + 1, right - 1};
    }

    int getLongestPalindrome(string s) {
        // write code here
        int n = s.size();
        if (n < 2) return n;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; i++) dp[i][i] = true;
        int res = 1;

        // ö�ٳ���
        for (int L = 2; L <= n; L++) {
            // ö����߽磬��߽���������ÿ��Կ���һЩ
            for (int i = 0; i < n; i++) {
                int j = L + i - 1;
                // ����ұ߽�Խ�����˳���ǰѭ��
                if (j >= n) break;

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    // ֻҪ dp[i][L] == true �������ͱ�ʾ�Ӵ� s[i..L] �ǻ��ģ���ʱ��¼���ĳ��Ⱥ���ʼλ��
                    if (dp[i][j] && j - i + 1 > res) {
                        res = j - i + 1;
                    }
                }
            }
        }
        return res;
    }
};