// 时间复杂度：O(n)
// 空间复杂度：O(n)

// 自顶向下
class Solution {
public:
    unordered_map<int, int> mymap;

    int jumpFloor(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (mymap.find(n - 1) == mymap.end()) mymap[n - 1] = jumpFloor(n - 1);
        if (mymap.find(n - 2) == mymap.end()) mymap[n - 2] = jumpFloor(n - 2);
        return mymap[n - 1] + mymap[n - 2];
    }
};

// 自底向上
class Solution {
public:
    int jumpFloor(int n) {
        vector<int> record = vector<int>(n + 1, 0);
        record[1] = 1;
        record[2] = 2;
        for (int i = 3; i <= n; i++) {
            record[i] = record[i - 1] + record[i - 2];
        }
        return record[n];
    }
};

// 状态压缩
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    unordered_map<int, int> mymap;

    int jumpFloor(int n) {
        vector<int> record = vector<int>(n+1, 0);
        if (n == 1) return 1;
        if (n == 2) return 2;
        int a = 1;
        int b = 2;
        int res;
        for (int i = 3; i <= n; i++) {
            res = b + a;
            a = b;
            b = res;
        }
        return res;
    }
};