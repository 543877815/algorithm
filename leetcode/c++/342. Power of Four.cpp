

bool isPowerOfFour(int num){
    if (num == 0) return false;
    float tmp = (log(num)/log(4));
    return floor(tmp + 0.5) == tmp;
}

