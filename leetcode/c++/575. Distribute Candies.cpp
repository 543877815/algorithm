// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int distributeCandies(vector<int> &candyType) {
        int n = candyType.size();
        int type = n / 2;
        unordered_map<int, int> mymap;
        for (int i = 0; i < n; i++) {
            mymap[candyType[i]]++;
        }

        return min(type, (int) mymap.size());
    }
};