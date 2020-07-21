

// 时间复杂度: O(m+n)
// 空间复杂度: O(m+n)
void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
    int *arr = (int *) malloc(sizeof(int) * (n + m));
    int size1 = 0, size2 = 0, size = 0;
    while (size1 != m && size2 != n && m != 0 && n != 0) {
        if (nums1[size1] < nums2[size2]) {
            arr[size++] = nums1[size1++];
        } else {
            arr[size++] = nums2[size2++];
        }
    }
    while (size1 != m && m != 0) {
        arr[size++] = nums1[size1++];
    }
    while (size2 != n && n != 0) {
        arr[size++] = nums2[size2++];
    }
    for (int i = 0; i < m + n; i++) {
        nums1[i] = arr[i];
    }
}

// 将 num2 拷贝到 num1 末尾然后用快排
// 时间复杂度: O(n)+O((m+n)log(m+n))
// 空间复杂度: O(1)


// 时间复杂度: O(m+n)
// 空间复杂度: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m+n-1; i >= 0; i--) {
            if (m <= 0) {
                nums1[i] = nums2[n-1];
                n--;
                continue;
            }
            if (n <= 0) {
                nums1[i] = nums1[m-1];
                m--;
                continue;
            }
            if (nums1[m-1] > nums2[n-1]){
                nums1[i] = nums1[m-1];
                m--;
            } else {
                nums1[i] = nums2[n-1];
                n--;
            }
        }
    }
};