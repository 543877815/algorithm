// ����
// ʱ�临�Ӷȣ�O(nlogn)
// �ռ临�Ӷȣ�O(n)
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

// ����ѡ��+��·�з�
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // ����ѡ����λ���������� mid ��
        auto midptr = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;

        int n = nums.size();

        // 3-way-partition
        int i = 0, j = 0, k = n - 1;
        while (j < k) {
            // ���������λ����������ұ�
            if (nums[j] > mid) {
                swap(nums[j], nums[k]);
                k--;
                // ���С����λ������������
            } else if (nums[j] < mid) {
                // ����λ�����м俿£
                swap(nums[j], nums[i]);
                i++;
                j++;
                // ���������λ����������
            } else {
                j++;
            }
        }

        if(nums.size() % 2) ++midptr;
        vector<int> tmp1(nums.begin(), midptr);
        vector<int> tmp2(midptr, nums.end());
        for(int i = 0; i < tmp1.size(); ++i){
            // ����
            nums[2 * i] = tmp1[tmp1.size() - 1 - i];
        }
        for(int i = 0; i < tmp2.size(); ++i){
            // ����
            nums[2 * i + 1] = tmp2[tmp2.size() - 1 - i];
        }
    }
};