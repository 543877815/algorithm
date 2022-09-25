// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int res = INT_MAX;
        unordered_map<int, int> mymap;
        int n = cards.size();
        for (int i = 0; i < n; i++) {
            if (mymap.find(cards[i]) != mymap.end()) {
                res = min(res, i - mymap[cards[i]] + 1);
            }
            mymap[cards[i]] = i;
        }

        return res == INT_MAX ? -1 : res;
    }
};