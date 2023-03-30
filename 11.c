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


void swap (char*buf1 , char*buf2 , int width)
{
    int i=0;
    for (i=0 ; i<width ; i++)
    {
        char tep = *buf1;
        *buf1 = *buf2;
        *buf2 = tep;
        buf1++;
        buf2++;
    }
}

void my_qsort(void*base , int sz , int width , int(*cmp)(void*e1 , void*e2))
{
    int i=0;
    for (i=0 ; i<sz-1 ; i++)
    {
        int j=0;
        for (j=0 ; j<sz-1-i ; j++)
        {
            if (cmp((char*)base+j*width , (char*)base+(j+1)*width)>0)
            {
                swap( (char*)base+j*width , (char*)base+(j+1)*width , width);
            }
        }
    }
}


void test1()
{
    int arr[10]={0,3,8,4,6,7,2,9,1,5};
    int sz = sizeof(arr) / sizeof(arr[0]);
    my_qsort(arr , sz , sizeof(arr[0]) , com_int );
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
    float aee[] = {1.2,9.3,6.6,3.9,4.5,7.5,4.9,5.8};
    int sz = sizeof(aee) / sizeof(aee[0]);
    my_qsort(aee , sz , sizeof(aee[0]) , com_float );
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
    my_qsort(s1 , sz , sizeof(s1[0]) , com_stu_by_age );
}
void test4()
{
    struct stu s1[] = {{"zhangsan",55},{"lisi",32},{"wangwu",44}};
    int sz = sizeof(s1) / sizeof(s1[0]);
    my_qsort(s1 , sz , sizeof(s1[0]) , com_stu_by_name );
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}