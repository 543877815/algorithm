// 排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        int n = nums.size();
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int x = (n + 1) / 2;
        for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, j--, k--) {
            nums[i] = arr[j];
            if (i + 1 < n) {
                nums[i + 1] = arr[k];
            }
        }
    }
};

// 快速选择+三路切分
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // 快速选择中位数，保存在 mid 中
        auto midptr = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;

        int n = nums.size();

        // 3-way-partition
        int i = 0, j = 0, k = n - 1;
        while (j < k) {
            // 如果大于中位数，则放在右边
            if (nums[j] > mid) {
                swap(nums[j], nums[k]);
                k--;
                // 如果小于中位数，则放在左边
            } else if (nums[j] < mid) {
                // 让中位数向中间靠拢
                swap(nums[j], nums[i]);
                i++;
                j++;
                // 如果等于中位数，不处理
            } else {
                j++;
            }
        }

        if(nums.size() % 2) ++midptr;
        vector<int> tmp1(nums.begin(), midptr);
        vector<int> tmp2(midptr, nums.end());
        for(int i = 0; i < tmp1.size(); ++i){
            // 反序
            nums[2 * i] = tmp1[tmp1.size() - 1 - i];
        }
        for(int i = 0; i < tmp2.size(); ++i){
            // 反序
            nums[2 * i + 1] = tmp2[tmp2.size() - 1 - i];
        }
    }
};