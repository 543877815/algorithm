// ʱ�临�Ӷȣ�O(nm)
// �ռ临�Ӷȣ�O(nmK) K Ϊ���г���
// �ڴ泬��
class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string�ַ��� the string
     * @param s2 string�ַ��� the string
     * @return string�ַ���
     */
    string LCS(string s1, string s2) {
        // write code here
        int n = s1.size(), m = s2.size();
        if (n == 0 || m == 0) return "-1";
        // dp[i][j] ��ʾ s1 ǰ i ���ַ��� s2 ǰ j ���ַ��������������
        vector<vector<string>> dp = vector<vector<string>>(n+1, vector<string>(m+1, ""));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + s1[i-1];
                } else {
                    dp[i][j] = dp[i][j-1].size() > dp[i-1][j].size() ? dp[i][j-1] : dp[i-1][j];
                }
            }
        }
        return dp[n][m].size() == 0 ? "-1" : dp[n][m];
    }
};

// ʱ�临�Ӷȣ�O(nm)
// �ռ临�Ӷȣ�O(nm)
// ��̬�滮+ջ�Ż�
class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string�ַ��� the string
     * @param s2 string�ַ��� the string
     * @return string�ַ���
     */
    string LCS(string text1, string text2) {
        // write code here
        int n = text1.size();
        int m = text2.size();
        if (n == 0 || m == 0) return "-1";
        vector <vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        stack<char> sk;
        int i = n, j = m;
        while (dp[i][j]) {
            if (dp[i][j] == dp[i][j-1]) {
                j--;
            } else if (dp[i][j] == dp[i-1][j]) {
                i--;
            } else if (dp[i][j] == dp[i-1][j-1] + 1) {
                i--;
                j--;
                sk.push(text1[i]);
            }
        }

        string res = "";
        while (!sk.empty()) {
            res += sk.top();
            sk.pop();
        }
        return res != "" ? res : "-1";
    }
};
