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



## 求链表中的倒数第k个节点

思路：

+ 两个指针，第一个指针走k-1步
+ 两个指针一起走
+ 第一个指针走到尾节点时，第二个指针指向倒数第k个节点

```c
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if(pListHead == NULL)
        return NULL;
    if(!k)
        return NULL;
    
    ListNode* pAhead = pListHead;
    ListNode* pBehind = pListHead;
    
    for(unsigned int i=0; i< k-1;i++) {
        pAhead=pAhead->m_pNext;
    }
    
    while(pAhead->m_pNext!=NULL) {
        pAhead=pAhead->m_pNext;
        pBehind=pBehind->m_pNext;
    }
    
    return pBehind;
}
```





## [剑指 Offer 09. 用两个栈实现队列](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)

用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )











