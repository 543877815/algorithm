

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int media = ( nums1Size + nums2Size ) / 2;
    int flag = ( nums1Size + nums2Size ) % 2;
    int check = 0;
    int i = 0, j = 0;
    if (nums1Size == 0){
        check = 2;
    }
    if (nums2Size == 0){
        check = 1;
    }
    while((i+j)<media){
        if (i<nums1Size && j<nums2Size){
            if(nums1[i] > nums2[j]){
                j++;
                check = 2;
            }else{
                i++;
                check = 1;
            }
        }else if(i >= nums1Size){
            j++;
            check = 2;
        }else if(j >= nums2Size){
            i++;
            check = 1;
        }else if(i >= nums1Size && j >= nums2Size){
            break;
        }
    }
    printf("i: %d, j: %d, check: %d, nums1Size: %d, nums2Size: %d", i, j, check, nums1Size, nums2Size);
    
    // 1数组数完了
    if (check == 1 && i == nums1Size) {
        i = i - 1;
        if(flag == 0){        
            return ( (double) nums1[i] + (double) nums2[j] ) / 2;
        }else{
            return nums1[i] > nums2[j] ? (double) nums1[i] :  (double) nums2[j];
        }
    }
    // 2数组数完了
    if (check == 2 && j == nums2Size) {
        j = j - 1;
        if(flag == 0){        
            return ( (double) nums1[i] + (double) nums2[j] ) / 2;
        }else{
            return nums1[i] > nums2[j] ? (double) nums1[i] : (double) nums2[j];
        }
    }
    if (check == 1 && j == nums2Size) {
        if(flag == 0){        
            return ( (double) nums1[i] + (double) nums1[i - 1] ) / 2;
        }else{
            return nums1[i];
        }
    }
    if (check == 2 && i == nums1Size) {
        if(flag == 0){        
            return ( (double) nums2[j] + (double) nums2[j - 1] ) / 2;
        }else{
            return nums2[j];
        }
    }
    
    if(flag == 0){
        double max;
        if (check == 1){
            max = nums1[i-1];
        }
        if (check == 2){
            max = nums2[j-1];
        }
        double min = nums1[i] < nums2[j] ? (double) nums1[i] : (double) nums2[j];
        return ( min + max ) / 2;
    }else{
        return nums1[i] > nums2[j] ?  (double) nums2[j] : (double) nums1[i];
    }
}

