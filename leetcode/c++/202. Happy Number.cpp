

bool isHappy(int n){
    int iter = 0;
    while(iter!=100){
        int happy = 0;
        while(n!=0) {
            int num = n % 10;
            happy += num * num;
            n /= 10;
        }
        if (happy == 1) return true;
        n = happy;
        iter ++;
    }
    return false;
}


// Hash 表
// 时间复杂度：O(logn)
// 空间复杂度：O(logn)
class Solution {
public:
    bool isHappy(int n) {
        int happy = 1;
        unordered_set<int> record;
        while(record.find(happy)==record.end()) {
            record.insert(happy);
            happy = 0;
            while(n!=0) {
                int num = n % 10;
                happy += num * num;
                n /= 10;
            }
            n = happy;
        }
        return happy == 1;
    }
};