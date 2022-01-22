// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    int k;
    unordered_map<int, int> record;

    Solution(int n, vector<int> &blacklist) {
        sort(blacklist.begin(), blacklist.end(), less<int>());
        int m = blacklist.size();
        k = n - m - 1;
        int i = n - 1, j = m - 1;
        int index = lower_bound(blacklist.begin(), blacklist.end(), k) - blacklist.begin();
        index = index == m ? m - 1 : index;
        while (index >= 0 && blacklist[index] > k) index--;
        while (i > 0 && index >= 0 && j >= 0) {
            if (blacklist[j] != i) {
                record[blacklist[index]] = i;
                index--;
            } else {
                j--;
            }
            i--;
        }
    }

    int pick() {
        int index = rand() % (k + 1);
        if (record.count(index)) return record[index];
        else return index;
    }
};
