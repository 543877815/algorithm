// 时间复杂度：O(n)
// 空间复杂度：O(n)

class Solution {
public:
    int minimumOperations(string leaves) {
        int n = leaves.size();
        vector <vector<int>> f(n, vector<int>(3));
        f[0][0] = (leaves[0] == 'y');
        f[0][1] = f[0][2] = f[1][2] = INT_MAX;
        for (int i = 1; i < n; i++) {
            int isRed = (leaves[i] == 'r');
            int isYellow = (leaves[i] == 'y');
            f[i][0] = f[i - 1][0] + isYellow;
            f[i][1] = min(f[i - 1][0], f[i - 1][1]) + isRed;
            if (i >= 2) f[i][2] = min(f[i - 1][1], f[i - 1][2]) + isYellow;
        }

        return f[n - 1][2];
    }
};

// 时间复杂度：O(n)
// 空间复杂度：O(1)

class Solution {
public:
    int minimumOperations(string leaves) {
        int n = leaves.size();
        int a, b, c;
        a = (leaves[0] == 'y');
        b = c = INT_MAX;
        for (int i = 1; i < n; i++) {
            int isRed = (leaves[i] == 'r');
            int isYellow = (leaves[i] == 'y');
            int temp_a = a, temp_b = b, temp_c = c;
            a = temp_a + isYellow;
            b = min(temp_a, temp_b) + isRed;
            if (i >= 2) c = min(temp_b, temp_c) + isYellow;
        }

        return c;
    }
};


// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int minimumOperations(string leaves) {
        int n = leaves.size();
        int a, b, c;
        a = (leaves[0] == 'y');
        b = c = INT_MAX;
        for (int i = 1; i < n; i++) {
            int isRed = (leaves[i] == 'r');
            int isYellow = (leaves[i] == 'y');
            if (i >= 2) c = min(b, c) + isYellow;
            b = min(a, b) + isRed;
            a = a + isYellow;
        }

        return c;
    }
};


// 时间复杂度：O(n)
// 空间复杂度：O(1)

class Solution {
public:
    int minimumOperations(string leaves) {
        int n = leaves.size();
        int g = (leaves[0] == 'y' ? 1 : -1);
        int gmin = g;
        int ans = INT_MAX;
        for (int i = 1; i < n; ++i) {
            int isYellow = (leaves[i] == 'y');
            g += 2 * isYellow - 1;
            if (i != n - 1) {
                ans = min(ans, gmin - g);
            }
            gmin = min(gmin, g);
        }
        return ans + (g + n) / 2;
    }
};

