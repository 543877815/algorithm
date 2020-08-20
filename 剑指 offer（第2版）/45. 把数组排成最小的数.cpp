// 排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
bool cmp(const int &a, const int &b) {
    string ab = to_string(a) + to_string(b);
    string ba = to_string(b) + to_string(a);
    int n = ab.size(), i = 0;
    while (i < n) {
        if (ab[i] != ba[i]) {
            return ab[i] < ba[i];
        } else {
            i++;
        }
    }
    return a > b;
}

class Solution {
public:
    string minNumber(vector<int> &nums) {
        string res;
        int n = nums.size();
        if (n == 0) return res;
        sort(nums.begin(), nums.end(), cmp);
        for (auto i : nums) {
            res += to_string(i);
        }
        return res;
    }
};