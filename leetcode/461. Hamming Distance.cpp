int hammingWeight(uint32_t n) {
    int num = 0;
    for(int i = 0; i < 32; i++) {
        num += n & 1;
        n = n >> 1;
    }
    return num;
}

int hammingDistance(int x, int y){
    int tmp = x ^ y;
    return hammingWeight(tmp);
}

