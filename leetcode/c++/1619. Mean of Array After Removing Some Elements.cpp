// ʱ�临�Ӷȣ�O(nlogn)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        int idx = static_cast<int>((double)n * 0.05);
        sort(arr.begin(), arr.end());
        double res = 0;
        for (int i = idx; i < n - idx; i++) {
            res += arr[i];
        }

        return res / (n - idx - idx);
    }
};