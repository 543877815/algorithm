// 排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    int abs(int x) {
        return x < 0 ? -x : x;
    }

    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        vector<int> res;
        int n = arr.size();
        if (n == 0) return res;
        sort(arr.begin(), arr.end(), [&](const int &a, const int &b) {
            if (abs(a - x) != abs(b - x)) return abs(a - x) < abs(b - x);
            else return a < b;
        });

        res.resize(k);
        for (int i = 0; i < k; i++) {
            res[i] = arr[i];
        }

        sort(res.begin(), res.end());
        return res;
    }

    a
};