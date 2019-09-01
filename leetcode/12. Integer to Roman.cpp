

char * intToRoman(int num){
    static char str[17];
    int size = 0;
    char romanChar[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int index = 0;
    while(num != 0) {
        int carry = num % 10;
        while(true) {
            if (carry == 9) {
                str[size++] = romanChar[index + 2];
                carry = 1;
            }
            if (carry == 8) {
                str[size++] = romanChar[index];
                carry--;
            }
            if (carry == 7) {
                str[size++] = romanChar[index];
                carry--;
            }
            if (carry == 6) {
                str[size++] = romanChar[index];
                carry--;
            }
            if (carry == 5) {
                str[size++] = romanChar[index + 1];
                break;
            }
            if (carry == 4) {
                str[size++] = romanChar[index + 1];
                carry = 1;
            }
            if (carry == 3) {
                str[size++] = romanChar[index];
                carry--;
            }
            if (carry == 2) {
                str[size++] = romanChar[index];
                carry--;
            }
            if (carry == 1) {
                str[size++] = romanChar[index];
                break;
            }
            if (carry == 0) {
                break;
            }
        }
        index += 2;
        num /= 10;
    }
    
    for (int i = 0; i < size / 2; i++) {
        char tmp = str[i];
        str[i] = str[size - 1 - i];
        str[size - 1 - i] = tmp;
    }
    str[size] = 0;
    return str;
}

