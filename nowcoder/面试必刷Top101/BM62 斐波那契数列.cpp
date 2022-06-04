// 时间复杂度：O(n)
// 空间复杂度：O(n)

// 自顶向下
class Solution {
public:
    unordered_map<int, int> mymap;

    int Fibonacci(int n) {
        if (n == 1 || n == 2) return 1;
        if (mymap.find(n - 1) == mymap.end()) mymap[n - 1] = Fibonacci(n - 1);
        if (mymap.find(n - 2) == mymap.end()) mymap[n - 2] = Fibonacci(n - 2);
        return mymap[n - 1] + mymap[n - 2];
    }
};

// 自底向上
class Solution {
public:
    int Fibonacci(int n) {
        vector<int> record = vector<int>(n+1, 0);
        record[1] = 1;
        record[2] = 1;
        for (int i = 3; i <= n; i++) {
            record[i] = record[i-1] + record[i-2];
        }
        return record[n];
    }
};