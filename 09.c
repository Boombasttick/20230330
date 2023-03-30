#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu
{
    char name[20];
    int age;
};
int com_int(const void* e1 ,const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}
int com_float(const void* e1 , const void* e2)
{
    if (*(float*)e1-*(float*)e2>0)
    return 1;
    else if (*(float*)e1-*(float*)e2==0)
    return 0;
    else 
    return -1;
}
int com_stu_by_age(const void* e1 , const void* e2)
{
    return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}
int com_stu_by_name(const void* e1 , const void* e2)
{
    return strcmp(((struct stu*)e1)->name , ((struct stu*)e2)->name);
}

void test1()
{
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    int sz = sizeof(arr) / sizeof(arr[0]);
    qsort(arr , sz , sizeof(arr[0]) , com_int );
    int j=0;
    for (j=0;j<10;j++)
    {
        printf("%d ",arr[j]);
    }
    printf("\n");
    //struct stu s1 = {{"zhangsan",20},{"lisi",32},{"wangwu",44}};
    //float aee[] = {1.2,3.3,3.6,3.9,4.5,7.5,4.9,5.8};
} 
void test2()
{
    float aee[] = {1.2,3.3,3.6,3.9,4.5,7.5,4.9,5.8};
    int sz = sizeof(aee) / sizeof(aee[0]);
    qsort(aee , sz , sizeof(aee[0]) , com_float );
    int j=0;
    for (j=0;j<8;j++)
    {
        printf("%f ",aee[j]);
    }
    printf("\n");
}
void test3()
{
    struct stu s1[] = {{"zhangsan",25},{"lisi",32},{"wangwu",14}};
    int sz = sizeof(s1) / sizeof(s1[0]);
    qsort(s1 , sz , sizeof(s1[0]) , com_stu_by_age );
}
void test4()
{
    struct stu s1[] = {{"zhangsan",55},{"lisi",32},{"wangwu",44}};
    int sz = sizeof(s1) / sizeof(s1[0]);
    qsort(s1 , sz , sizeof(s1[0]) , com_stu_by_name );
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}


//qsort(arr , sz , sizeof(arr[0]) , com_int );
//第一个参数，待排序数组的首元素地址
//第二个参数：待排序数组的元素个数
//第三个参数：待排序数组的每个元素的大小--单位是字节
//第四个参数：是函数指针，比较两个元素的所用函数的地址--这个函数是使用者自己实现    函数指针的两个参数是：待比较的两个元素的地址
