// 时间复杂度：O(max(n,m))
// 空间复杂度：O(1)

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 比较版本号
     * @param version1 string字符串
     * @param version2 string字符串
     * @return int整型
     */
    int compare(string version1, string version2) {
        // write code here
        int n = version1.size(), m = version2.size();
        int i = 0, j = 0;
        while (i < n || j < m) {
            int num_i = 0, num_j = 0;

            while (i < n && version1[i] != '.') {
                num_i = num_i * 10 + (version1[i] - '0');
                i++;
            }

            while (j < m && version2[j] != '.') {
                num_j = num_j * 10 + (version2[j] - '0');
                j++;
            }

            if (num_i > num_j) return 1;
            if (num_i < num_j) return -1;
            i++;
            j++;
        }

        return 0;
    }
};