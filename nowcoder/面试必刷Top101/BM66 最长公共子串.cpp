// ��̬�滮
// ʱ�临�Ӷȣ�O(nm)
// �ռ临�Ӷȣ�O(nm)
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * longest common substring
     * @param str1 string�ַ��� the string
     * @param str2 string�ַ��� the string
     * @return string�ַ���
     */
    string LCS(string str1, string str2) {
        // write code here
        int n = str1.size(), m = str2.size();
        vector <vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int index = -1;
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (str1[i] == str2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    if (dp[i + 1][j + 1] > maxLength) {
                        maxLength = dp[i + 1][j + 1];
                        index = i - maxLength + 1;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
//         cout << index << " " << maxLength;
        if (maxLength == 0) return "-1";
        return str1.substr(index, maxLength);
    }
};