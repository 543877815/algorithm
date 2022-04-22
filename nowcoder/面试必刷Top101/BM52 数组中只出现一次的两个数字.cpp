// 位运算
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    // 数组一定是偶数
    vector<int> FindNumsAppearOnce(vector<int> &array) {
        // write code here
        int n = array.size();
        int xornum = 0;
        for (int i = 0; i < n; i++) {
            xornum ^= array[i];
        }

        int lsb = (xornum == INT_MIN ? xornum : (xornum & -xornum));
        int type1 = 0;
        int type2 = 0;
        for (int i = 0; i < n; i++) {
            if (lsb & array[i]) type1 ^= array[i];
            else type2 ^= array[i];
        }

        return (type1 < type2) ? vector < int > {type1, type2} : vector < int > {type2, type1};
    }
};