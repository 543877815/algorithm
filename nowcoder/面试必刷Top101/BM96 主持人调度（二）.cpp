// 贪心
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算成功举办活动需要多少名主持人
     * @param n int整型 有n个活动
     * @param startEnd int整型vector<vector<>> startEnd[i][0]用于表示第i个活动的开始时间，startEnd[i][1]表示第i个活动的结束时间
     * @return int整型
     */
    int minmumNumberOfHost(int n, vector <vector<int>> &startEnd) {
        // write code here
        vector<int> start;
        vector<int> end;
        for (int i = 0; i < n; i++) {
            start.push_back(startEnd[i][0]);
            end.push_back(startEnd[i][1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int res = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (start[i] >= end[j]) j++;
            else res++;
        }

        return res;
    }
};