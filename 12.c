#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>

int main()
{
    //数组名是首元素地址
    //例外：1.sizeof(数组名)-数组名表示整个数组  2.&数组名-数组名表示整个数组
    int a[] = {1,2,3,4};
    printf("%d\n",sizeof(a));               //16
    printf("%d\n",sizeof(a+0));             //4/8
    printf("%d\n",sizeof(*a));              //4
    printf("%d\n",sizeof(a+1));             //4/8
    printf("%d\n",sizeof(a[1]));            //4
    printf("%d\n",sizeof(&a));              //4/8
    printf("%d\n",sizeof(*&a));             //16
    printf("%d\n",sizeof(&a+1));            //4/8
    printf("%d\n",sizeof(&a[0]));           //4/8
    printf("%d\n",sizeof(&a[0]+1));         //4/8


    char arr[] = {'a','b','c','d','e','f'};
    printf("%d\n",sizeof(arr));             //6
    printf("%d\n",sizeof(arr+0));           //4/8
    printf("%d\n",sizeof(*arr));            //1
    printf("%d\n",sizeof(arr[1]));          //1
    printf("%d\n",sizeof(&arr));            //4/8
    printf("%d\n",sizeof(&arr+1));          //4/8
    printf("%d\n",sizeof(&arr[0]+1));       //4/8


    //char arr[] = {'a','b','c','d','e','f'};
    printf("%d\n",strlen(arr));             //随机值
    printf("%d\n",strlen(arr+0));           //随机值
    //printf("%d\n",strlen(*arr));          //err
    //printf("%d\n",strlen(arr[1]));        //err
    printf("%d\n",strlen(&arr));            //随机值
    printf("%d\n",strlen(&arr+1));          //随机值
    printf("%d\n",strlen(&arr[0]+1));        //随机值





    return 0 ;
}