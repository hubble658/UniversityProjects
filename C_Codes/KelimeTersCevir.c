#include <stdio.h>

int main(){

    char kelime[1000];
    int aranan[100];
    char tmp;
    int i;
    int j;
    int *p1;

    gets(kelime);
    
    i = 0;
    int len=0;
    while (kelime[i] != '\0')
    {
        i++;
        
    }
    len=i-1;
    
    for (i=0;i<=len/2;i++){
        tmp=kelime[len-i];
        kelime[len-i]=kelime[i];
        kelime[i]=tmp;
    }
    puts(kelime);
    
    return 0;
}
