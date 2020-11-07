// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
bool cmp(int a, int b) {
    if (__builtin_popcount(a) != __builtin_popcount(b))
        return __builtin_popcount(a) < __builtin_popcount(b);
    else return a < b;
}


class Solution {
public:
    vector<int> sortByBits(vector<int> &arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};