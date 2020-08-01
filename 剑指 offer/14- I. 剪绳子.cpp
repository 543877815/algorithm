// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> record = {0,1,1,2,4,6,9};
        for (int i = 7; i <= n; i++) {
            int num = max(record[i-3]*3, record[i-2]*2);
            record.push_back(num);
        }
        return record[n];
    }
};

// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 2) return 0;
        if (n == 2) return 1;
        if (n == 3) return 2;

        int timesOf3 = n / 3;

        if (n - timesOf3 * 3 == 1) timesOf3--;
        int timesOf2 = (n - timesOf3 * 3) / 2;

        return (int)(pow(3, timesOf3)) * (int)(pow(2, timesOf2));

    }
};