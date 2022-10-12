/*自用gets函数
 * 读取整行输入，并用空字符代替换行符
 * 或者读取一部分输入，并丢弃剩余字符*/

#include <stdio.h>
//数组表示法
char * s_gets(char Buffer[], int maxCount){
    char * ret_value;
    int i = 0;
    ret_value = fgets(Buffer, maxCount, stdin);
    if (ret_value){
        //替换'\n'为'\0'
        while (Buffer[i] != '\n' && Buffer[i] != '\0') {
            i++;
        }
        if (Buffer[i] == '\n')
            Buffer[i] = '\0';
        else{
            while (getchar() != '\n');
        }
    }
    return ret_value;
}

//指针表示法
char * s_gets(char * Buffer, int maxCount){
    char * ret_value;
    ret_value = fgets(Buffer, maxCount, stdin);
    if (ret_value){
        //替换'\n'为'\0'
        while (*Buffer != '\n' && *Buffer != '\0')
            Buffer++;
        if (*Buffer == '\n')
            *Buffer = '\0';
        else{
            while (getchar() != '\n');
        }
    }
    return ret_value;
}
