// 快速排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
        vector<pair<int, string>> n_h;
        for (int i = 0; i < n; i++) {
            n_h.push_back(make_pair(heights[i], names[i]));
        }
        sort(n_h.begin(), n_h.end(), greater<>());
        for (int i = 0; i < n; i++) {
            names[i] = n_h[i].second;
        }
        return names;
    }
};