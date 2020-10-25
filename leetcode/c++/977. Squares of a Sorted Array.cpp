

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 时间复杂度：O(nlogn)
// 空间复杂度：O(1)
int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int* sortedSquares(int* A, int ASize, int* returnSize){
    for (int i = 0; i < ASize; i++) {
        A[i] = A[i] * A[i];
    }
    qsort(A, ASize, sizeof(int), cmp);
    * returnSize = ASize;
    return A;
}

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            A[i] = A[i] * A[i];
        }

        sort(A.begin(), A.end());

        return A;
    }
};

// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> res(n, 0);
        if (n == 0) return res;
        int positive = 0;
        while (positive < n && A[positive] <= 0) positive++;
        int negative = positive - 1;
        int index = 0;
        while (negative >= 0 && positive < n && index < n) {
            if (abs(A[positive]) > abs(A[negative])) {
                res[index++] = A[negative] * A[negative];
                negative --;
            } else {
                res[index++] = A[positive] * A[positive];
                positive++;
            }
        }
        while (negative >= 0 && index < n) {
            res[index++] = A[negative] * A[negative];
            negative--;
        }

        while (positive < n && index < n) {
            res[index++] = A[positive] * A[positive];
            positive++;
        }

        return res;
    }
};
