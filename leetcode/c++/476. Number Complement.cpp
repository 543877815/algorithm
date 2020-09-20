

int findComplement(int num){
    int temp = num, c = 0;
    while(temp > 0){
        temp >>= 1;
        c =  (c << 1) + 1; // 计算有有多少位
    }
    return num ^ c;
}

