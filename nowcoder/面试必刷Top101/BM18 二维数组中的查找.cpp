// 时间复杂度：O(nm)
// 空间复杂度：O(1)
class Solution {
public:
    bool Find(int target, vector <vector<int>> array) {
        int n = array.size();
        int m = array[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (array[i][j] == target) return true;
            }
        }

        return false;
    }
};

// 时间复杂度：O(n+m)
// 空间复杂度：O(1)
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int n = array.size();
        int m = array[0].size();
        int i = n - 1, j = 0;
        while (i >= 0 && j < m) {
            if (array[i][j] == target) return true;
            else if (array[i][j] > target) i--;
            else j++;
        }

        return false;
    }
};