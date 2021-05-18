// 三重循环
// 时间复杂度：O(n)
// 空间复杂度：O(n^3)
class Solution {
public:
    int countTriplets(vector<int> &arr) {
        int n = arr.size();
        int res = 0;
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j; k < n; k++) {
                    if (prefix[i] == prefix[k + 1]) {
                        res++;
                    }
                }
            }
        }

        return res;
    }
};

// 二重循环
// 时间复杂度：O(n)
// 空间复杂度：O(n^2)
class Solution {
public:
    int countTriplets(vector<int> &arr) {
        int n = arr.size();
        int res = 0;
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        for (int i = 0; i < n; i++) {
            for (int k = i + 1; k < n; k++) {
                if (prefix[i] == prefix[k + 1]) {
                    res += k - i;
                }
            }
        }
        return res;
    }
};

// 一重循环
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int countTriplets(vector<int> &arr) {
        int n = arr.size();
        int res = 0;
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        unordered_map<int, int> cnt, total;
        for (int k = 0; k < n; k++) {
            if (cnt.count(prefix[k + 1])) {
                res += cnt[prefix[k + 1]] * k - total[prefix[k + 1]];
            }
            ++cnt[prefix[k]];
            total[prefix[k]] += k;
        }

        return res;
    }
};

// 优化
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int countTriplets(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int, int> cnt, total;
        int ans = 0, s = 0;
        for (int k = 0; k < n; ++k) {
            int val = arr[k];
            if (cnt.count(s ^ val)) {
                ans += cnt[s ^ val] * k - total[s ^ val];
            }
            ++cnt[s];
            total[s] += k;
            s ^= val;
        }
        return ans;
    }
};
