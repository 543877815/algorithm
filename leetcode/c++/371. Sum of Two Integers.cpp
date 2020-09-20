// cheating
int getSum(int a, int b){
    return a + b;
}

// 没有负数
int getSum(int a, int b){
    int sum = a ^ b; // 无进位相加
    int carry = (a & b) << 1; // 得到进位
    if (carry != 0) {  // 加进位
        return getSum(sum, carry);
    }
    return sum;
}

// 通过解法
int getSum(int a, int b){
    unsigned long c = a;
    unsigned long d = b;
    while (d > 0) {
        unsigned long carry = c & d; 
        c = c ^ d; // 无进位相加
        d = carry << 1; // 得到进位
    }
    return (int) c;
}

