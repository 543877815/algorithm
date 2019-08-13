

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int* arr = (int *)malloc(sizeof(int)*(n+m));
    int size1 = 0, size2 = 0, size = 0;
    while(size1 != m && size2 != n && m != 0 && n != 0) {
        if (nums1[size1] < nums2[size2]) {
            arr[size++] = nums1[size1++];
        } else {
            arr[size++] = nums2[size2++];
        }
    }
    while(size1 != m && m != 0) {
        arr[size++] = nums1[size1++];
    }
    while(size2 != n && n != 0) {
        arr[size++] = nums2[size2++];
    }
    for (int i = 0; i < m + n; i++) {
        nums1[i] = arr[i];
    }
}

