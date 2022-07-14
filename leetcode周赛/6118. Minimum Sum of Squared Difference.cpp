// 时间复杂度：O(n+logk)
// 空间复杂度：O(n)
class Solution {
public:
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2) {
        int n = nums1.size();
        if (n == 0) return 0;
        long long sum = 0;
        vector<int> diff(n, 0);
        for (int i = 0; i < n; i++) {
            int different = abs(nums1[i] - nums2[i]);
            sum += different;
            diff[i] = different;
        }
        int k = k1 + k2;
        if (sum <= k) return 0;
        int avg = sum / n;
        map<int, int, greater<int>> mymap;
        for (int i = 0; i < n; i++) {
            mymap[diff[i]]++;
        }
        while (k > 0) {
            auto it = mymap.begin();
            if (it->second > k) {
                it->second -= k;
                mymap[it->first - 1] += k;
                k = 0;
                if (it->second == 0) {
                    mymap.erase(it->first);
                }
            } else {
                mymap[it->first - 1] += it->second;
                k -= it->second;
                mymap.erase(it->first);
            }
        }
        long long res = 0;
        for (auto [key, value]: mymap) {
            res += ((long long) key * (long long) key) * (long long) value;
        }
        return res;
    }
};