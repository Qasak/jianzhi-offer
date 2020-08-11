int StrToInt(const char* str) {
    static const int MAX_INT=0x7fffffff;
    static const int MIN_INT=1<<31;
    unsigned int n = 0;
    if(str==0)
        return 0;
    while(isspace(*str))
        str++;
    int sign=1;
    if(*str=='+'||*str=='-') {
        if(*str=='-')
            sign=-1;
    	++str;
    }
    while(isdigit(*str)) {
        int c=*str-'0';
        if(sign > 0 && n > MAX_INT/10 || (n == MAX_INT / 10 && c > MAX_INT % 10)  ) {
			return MAX_INT;
        }
        else if(sign < 0 && n > (unsigned)MIN_INT/10 || (n == (unsigned)MIN_INT / 10 && c > (unsigned)MIN_INT % 10) ) {
			return MIN_INT;
        }
        else {
            n=n*10+c;
        }
        ++str;
    }
    return sign>0? n:-n;
}