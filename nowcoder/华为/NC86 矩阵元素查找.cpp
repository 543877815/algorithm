// �ռ临�Ӷȣ�O(1)
// ʱ�临�Ӷȣ�O(n+m)
class Solution {
public:
    vector<int> findElement(vector <vector<int>> mat, int n, int m, int x) {
        // write code here
        vector<int> res;
        int j = 0, i = n - 1;
        while (i >= 0 && j < m) {
            if (mat[i][j] == x) break;
            else if (mat[i][j] > x) i--;
            else j++;
        }

        return {i, j};
    }
};