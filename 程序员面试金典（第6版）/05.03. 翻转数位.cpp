// 时间复杂度: O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int reverseBits(int num) {
        int count = 0;
        vector<int> nums;
        while (num) {
            if (num & 1) {
                count++;
            } else {
                nums.push_back(count);
                count = 0;
                nums.push_back(count);
            }
            num = num >> 1;
        }
        nums.push_back(count);
        if (nums.back() != 0) nums.push_back(0);
        int res = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                int tmp = 1;
                if (i != 0) {
                    tmp += nums[i - 1];
                }
                if (i != nums.size() - 1) {
                    tmp += nums[i + 1];
                }
                res = max(res, tmp);
            }
        }
        return res;
    }
};

// 时间复杂度: O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int reverseBits(int num){
        int ans = 0;
        int cnt = 0, pre = 0;
        while(num){
            if(num & 1){
                cnt ++;
            }
            else{
                ans = max(ans, cnt + pre + 1);
                pre = cnt;
                cnt = 0;
            }
            num >>= 1;
        }
        ans = max(ans, cnt + pre + 1);
        return ans;
    }

};

