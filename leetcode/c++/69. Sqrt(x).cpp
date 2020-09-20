int mySqrt(int x){
    // return (int)sqrt(x);
    int begin = 0; 
    int end = x;
    int middle = (begin + end) / 2;
    // 特殊情况 x = 0/1/2^32-1
    if (x == 0) return 0;
    if (x == 1) return 1;
    while(begin <= end){
        if (middle == x / middle) {
            return middle;
        } else if (middle < x / middle) {
            begin = middle + 1;
        } else {
            end = middle - 1;
        }
        middle = (begin + end) / 2;
    }
    return end;
}

