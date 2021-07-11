// 排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
class Solution {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end(), greater<int>());
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i + 1 <= citations[i]) res = max(res, i + 1);
            else break;
        }

        return res;
    }
};

// 计数排序
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        int total = 0;
        vector<int> counter(n + 1);
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n) {
                counter[n]++;
            } else {
                counter[citations[i]]++;
            }
        }

        for (int i = n; i >= 0; i--) {
            total += counter[i];
            if (total >= i) return i;
        }

        return 0;
    }
};