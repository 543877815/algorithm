// 遍历
// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)
class Solution {
public:
    vector<int> getVersion(string &version) {
        int n = version.size();
        vector<int> record;
        int num = 0;
        bool notzero = false;
        for (int i = 0; i < n; i++) {
            if (version[i] == '.') {
                record.push_back(num);
                num = 0;
                notzero = false;
            } else if (version[i] != '0') {
                notzero = true;
                num = num * 10 + version[i] - '0';
            } else if (version[i] == '0' && notzero) {
                num = num * 10;
            }
        }
        record.push_back(num);
        return record;
    }

    int compareVersion(string version1, string version2) {
        vector<int> record1 = getVersion(version1);
        vector<int> record2 = getVersion(version2);

        int n = record1.size();
        int m = record2.size();

        int minN = min(n, m);
        int maxN = max(n, m);
        for (int i = 0; i < minN; i++) {
            if (record1[i] > record2[i]) return 1;
            else if (record1[i] < record2[i]) return -1;
        }

        for (int i = minN; i < maxN; i++) {
            if (i < n && record1[i] > 0) return 1;
            if (i < m && record2[i] > 0) return -1;
        }

        return 0;
    }
};


// 双指针
// 时间复杂度：O(n+m)
// 空间复杂度：O(1)
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size(), m = version2.size();
        int i = 0, j = 0;
        while (i < n || j < m) {
            int x = 0;
            for (; i < n && version1[i] != '.'; i++) {
                x = x * 10 + version1[i] - '0';
            }
            i++;
            int y = 0;
            for (; j < m && version2[j] != '.'; j++) {
                y = y * 10 + version2[j] - '0';
            }
            j++;
            if (x != y) {
                return x > y ? 1 : -1;
            }
        }
        return 0;
    }
};