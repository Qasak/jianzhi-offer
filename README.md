## 字符串转换成整数

`int StrToInt(const char * str)`

实现字符串转换成整数的功能，不能使用库函数`atoi`

```c
int StrToInt(const char *str {
    int n = 0;
    while (*str != 0) {
        int c = *str - '0';
        n = n * 10 + c;
        ++str;
    }
    return n;
}
```

- sign用来处理数字的正负，当为正时sign > 0，当为负时sign < 0
- n存放最终转换后的结果
- c表示当前数字

1. 空指针

2. 正负号

3. 非法字符

4. 整型溢出

   + 只比较n和MAX_INT/10的大小

     + 若n>MAX_INT/10,返回MAX_INT

     + 若n==MAX_INT/10,比较最后一个数字c和MAX_INT%10的大小

       若c>MAX_INT%10,返回MAX_INT

```c
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
```

填坑:实现string到double的转换











