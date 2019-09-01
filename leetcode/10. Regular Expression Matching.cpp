// https://blog.csdn.net/zdavb/article/details/47038483

bool isMatch(char* s, char* p) {
    if(*p=='\0') return *s=='\0';//查看是否二者都进行到末尾

    //think,p+1 or p+2 will not exceed the limit of array
    if(*(p+1)!='*'){
        if(*p==*s||*p=='.'&&*s!='\0')
            return isMatch(s+1,p+1);
        return false;
    }else{
        while(*p==*s||*p=='.'&&*s!='\0'){
            if(isMatch(s,p+2))
                return true;
            s++;
        }
        return isMatch(s,p+2);
    }
}
