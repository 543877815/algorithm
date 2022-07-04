// ���α���
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
class Solution {
public:
    vector <vector<int>> minimumAbsDifference(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int min_dis = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (i > 0) min_dis = min(min_dis, arr[i] - arr[i - 1]);
        }

        vector <vector<int>> res;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == min_dis) {
                res.push_back({arr[i] - min_dis, arr[i]});
            }
        }

        return res;
    }
};