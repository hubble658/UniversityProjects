#include <stdio.h>
#include<stdlib.h>
#include<string.h>



int main(){

    int dizi[]={1,2,3,4,5};
    int *ptr1;
    int *ptr2 = ptr1;
    ptr1=dizi;
    



    printf("%d,%d",&*(ptr1+2),&dizi[2]);


}