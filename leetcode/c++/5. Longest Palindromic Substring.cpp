class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        int left = 0;
        int right = 0;
        for (int i = 0; i < length; i++) {
            int tmpL = 0;
            int tmpR = 0;
            int j = 1;
            while (i - j >= 0 && i + j <= length - 1) {
                if (s[i - j] == s[i + j]) {
                    tmpL = i - j;
                    tmpR = i + j;
                    j++;
                } else {
                    break;
                }
            }
            if (tmpR - tmpL > right - left) {
                right = tmpR;
                left = tmpL;
            }
        }
        for (int i = 0; i < length; i++) {
            int tmpL = 0;
            int tmpR = 0;
            int j = 1;
            while (i - j + 1 >= 0 && i + j <= length - 1) {
                if (s[i - j + 1] == s[i + j]) {
                    tmpL = i - j + 1;
                    tmpR = i + j;
                    j++;
                } else {
                    break;
                }
            }
            if (tmpR - tmpL > right - left) {
                right = tmpR;
                left = tmpL;
            }
        }
        int size = 0;
        string s1 = s.substr(left, right - left + 1);
        return s1;
    }
};


char *longestPalindrome(char *s) {
    int length = strlen(s);
    int **dp = (int **) malloc(sizeof(int *) * length);
    for (int i = 0; i < length; i++) {
        dp[i] = (int *) malloc(sizeof(int) * length);
    }

    // 初始化
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            if (i == j) dp[i][j] = 1;
            else dp[i][j] = 0;
        }
    }

    int dis = 1;
    int left = 0;

    for (int j = 1; j < length; j++) {
        for (int i = 0; i < j; i++) {
            if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1] == 1)) { // 奇偶回文或子回文
                dp[i][j] = 1;
                if (j - i + 1 > dis) {
                    dis = j - i + 1;
                    left = i;
                }
            }
        }
    }

    printf("%d %d", dis, left);
    char *ans = (char *) malloc(sizeof(char) * (dis + 1));
    strncpy(ans, s + left, dis);
    ans[dis] = '\0';
    return ans;
}

// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
    pair<int, int> expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        return {left + 1, right - 1};
    }

    string longestPalindrome(string s) {
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

        return s.substr(start, end - start + 1);
    }
};