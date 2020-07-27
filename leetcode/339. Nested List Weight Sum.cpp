// reference: https://blog.csdn.net/qq_21201267/article/details/107093614
class Solution {
    int ans = 0;
public:
    int depthSum(vector <NestedInteger> &nestedList) {
        if (nestedList.empty()) return 0;
        dfs(nestedList, 1);
        return ans;
    }

    void dfs(vector <NestedInteger> &nestedList, int deep) {
        for (int i = 0; i < nestedList.size(); ++i) {
            if (nestedList[i].isInteger())
                ans += nestedList[i].getInteger() * deep;
            else
                dfs(nestedList[i].getList(), deep + 1);
        }
    }
};
