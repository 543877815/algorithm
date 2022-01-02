// 记忆化搜索
// 时间复杂度：O(nxkxm^n)
// 空间复杂度：O(nxm^n)
class Solution {
public:
    map<vector<int>, int> memo;

    int dfs(vector<int> &price, vector <vector<int>> &filterSpecial, vector<int> &currNeeds) {
        int n = price.size();
        int m = filterSpecial.size();
        if (!memo.count(currNeeds)) {
            int minPrice = 0;
            for (int i = 0; i < n; i++) minPrice += currNeeds[i] * price[i];
            for (auto &curSpecial : filterSpecial) {
                int specialPrice = curSpecial[n];
                vector<int> nxtNeeds;
                for (int i = 0; i < n; i++) {
                    if (curSpecial[i] > currNeeds[i]) { // 不能购买超出购物清单指定数量的物品
                        break;
                    }
                    nxtNeeds.emplace_back(currNeeds[i] - curSpecial[i]);
                }
                if (nxtNeeds.size() == n) { // 大礼包可以购买
                    minPrice = min(minPrice, dfs(price, filterSpecial, nxtNeeds) + specialPrice);
                }
            }
            memo[currNeeds] = minPrice;
        }
        return memo[currNeeds];

    }

    int shoppingOffers(vector<int> &price, vector <vector<int>> &special, vector<int> &needs) {
        int n = price.size();

        // 过滤不需要计算的大礼包，只保留需要计算的大礼包
        vector <vector<int>> filterSpecial;
        for (auto &sp : special) {
            int totalCount = 0, totalPrice = 0;
            for (int i = 0; i < n; ++i) {
                totalCount += sp[i];
                totalPrice += sp[i] * price[i];
            }
            if (totalCount > 0 && totalPrice > sp[n]) {
                filterSpecial.emplace_back(sp);
            }
        }

        return dfs(price, filterSpecial, needs);
    }


};