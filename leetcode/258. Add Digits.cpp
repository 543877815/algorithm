int addDigits(int num){
    int res = num % 9;
    if( res == 0 && num > 0)
        return 9;
    else
        return res;
}