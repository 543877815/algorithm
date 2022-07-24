// 一次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination) {
        int n = distance.size();
        int a = 0;
        if (start > destination) swap(start, destination);
        for (int i = start; i < destination; i++) {
            a += distance[i];
        }

        int b = 0;
        int j = destination;
        while (j != start) {
            b += distance[j];
            j++;
            if (j == n) j = 0;
        }

        return min(a, b);
    }
};