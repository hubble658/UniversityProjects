#include <stdio.h>

int main(){

    int temp1,temp2,katsayi,derece;
    int ter1,ter2,i,j;
    int *ptr1;
    int *ptr2;

    //İlk Polinomu al
    printf("Ilk polinomun terim sayisi:");
    scanf("%d",&ter1);
    int pol1[2][ter1];

    for(i=0;i<ter1;i++){
        printf("1. Polinomun %d. terimini girin. (Ust ve katsayi)\n",i+1);
        scanf("%d",&pol1[0][i]);
        scanf("%d",&pol1[1][i]);
    }

    //İkinci Polinomu al
    printf("Ikinci polinomun terim sayisi:");
    scanf("%d",&ter2);
    int pol2[2][ter2];

    for(i=0;i<ter2;i++){
        printf("2. Polinomun %d. terimini girin. (Ust ve katsayi)\n",i+1);
        scanf("%d",&pol2[0][i]);
        scanf("%d",&pol2[1][i]);
    }


    //Sonuc polinomu kac terim olacak
    temp1 = pol1[0][0]+pol2[0][0]+1;
    int sonuc[temp1];


    //Diziyi sıfırla
    for (i = 0; i < temp1; i++)
    {
        sonuc[i]=0;
    }
    
    //Pointer diziyi gösteriyor
    ptr1 = sonuc;


    for (i = 0; i < ter1; i++)
    {
        for (j = 0; j < ter2; j++)
        {
            
            derece  = pol1[0][i] + pol2[0][j];
            katsayi = pol1[1][i] * pol2[1][j];
            
            ptr2 = (ptr1+derece);
            
            *ptr2 = *ptr2 + katsayi;    
        }      
    }

    for (i = 0; i < temp1; i++)
    {
        if (*(ptr1+temp1-1-i)>0)
        {
            printf("%dx^%d  ",*(ptr1+temp1-1-i),temp1-1-i);
        }
        
        
    }
    
    






    
    
    
    return 0;
}
