// 时间复杂度：O(n^2)
// 空间复杂度: O(n^2)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> record;
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < D.size(); j++) {
                record[C[i]+ D[j]]++;
            }
        }
        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (record.find(0 - A[i] - B[j]) != record.end()){
                    res += record[0 - A[i] - B[j]];
                }
            }
        }
        return res;
    }
};


// c++11
// 时间复杂度：O(n^2)
// 空间复杂度: O(n^2)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> record;
        for (int i : C) {
            for (int j : D) {
                record[i + j]++;
            }
        }
        int res = 0;
        for (int i : A) {
            for (int j : B) {
                if (record.find(0 - i - j) != record.end()){
                    res += record[0 - i - j];
                }
            }
        }
        return res;
    }
};