// 前缀和 + 快速排序
// 时间复杂度：O(nm+nmlognmn)
// 空间复杂度：O(nm)
class Solution {
public:
    int kthLargestValue(vector <vector<int>> &matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector <vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        vector<int> record;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = prefix[i][j - 1] ^ prefix[i - 1][j] ^ prefix[i - 1][j - 1] ^ matrix[i - 1][j - 1];
                record.push_back(prefix[i][j]);
            }
        }
        sort(record.begin(), record.end(), greater<int>());
        return record[k - 1];
    }
};

// 前缀和 + 快速选择算法
// 时间复杂度：期望为O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    int kthLargestValue(vector <vector<int>> &matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector <vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        vector<int> record;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = prefix[i][j - 1] ^ prefix[i - 1][j] ^ prefix[i - 1][j - 1] ^ matrix[i - 1][j - 1];
                record.push_back(prefix[i][j]);
            }
        }
        nth_element(record.begin(), record.begin() + k - 1, record.end(), greater<int>());
        return record[k - 1];
    }
};