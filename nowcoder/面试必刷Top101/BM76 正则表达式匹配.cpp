// ��̬�滮
// ʱ�临�Ӷȣ�O(nm)
// �ռ临�Ӷȣ�O(nm)
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param str string�ַ���
     * @param pattern string�ַ���
     * @return bool������
     */
    bool match(string str, string pattern) {
        // write code here
        str = " " + str;
        pattern = " " + pattern;
        int n = str.size(), m = pattern.size();
        // dp[i][j] ��ʾ sǰi���ַ���pǰj���ַ���ƥ�����
        vector <vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pattern[j - 1] != '*') { // �������ͨ���
                    if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.') { // ������ֶ���ͬ�����������ַ���̎��aa, aa��aa, a.
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                } else { // �����һ����ͨ���
                    if (str[i - 1] != pattern[j - 2] && pattern[j - 2] != '.') { // �������aa, .*��aa, ab*���t�J��ƥ��[i][j-2]
                        dp[i][j] = dp[i][j - 2];
                    } else {
                        dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j]; // �����.*���t������ƥ��
                    }
                }
            }
        }


        return dp[n][m];
    }
};