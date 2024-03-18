#include <stdio.h>

int main(){
    char metin[1000];
    char matrisDepo[500][26];
    char sonuc[26]; //alfabe

    int i,j,uzunluk,tmp,cumle,kelime,harfSay;
    int enFazlaHarf = 0;
    i=0;
    uzunluk=0;
    cumle=0;
    kelime=0;
    harfSay=0;


    
    printf("Metin giriniz :\n");
    gets(metin);
    printf("\n");

    while (metin[i] != '\0'){
        uzunluk=uzunluk+1;
        i++;
    }
    
    //lowercase func
    for(i = 0 ; i<uzunluk ; i++){ 

        if(metin[i]<='Z' && metin[i]>='A'){

            metin[i] = metin[i] + (+'a'-'A');

        }
    }

    //Bütün elemanları sıfırla
    for (i = 0; i < 26; i++)
    {
        sonuc[i]=0;   
    }
    

    //harfler kac kez geçitor

    for (i = 0; i < uzunluk ; i++)
    {
        if(metin[i] != '.'){
            if(metin[i]>='a' && metin[i]<='z'){

                tmp = metin[i]-'a'; //hangi indisi arttıracağını bul
                sonuc[tmp] = sonuc[tmp] +1;
                harfSay++;

            }else if(metin[i]==' ' && metin[i-1]!=' '){
                kelime++;
            }

        }else{
            cumle = cumle+1;
            if(metin[i+1]=='\0'){
                kelime++;
            }
        }
    }


    for (i = 0; i < 26; i++) //en fazla geçen harf
    {
        if (sonuc[i]>enFazlaHarf)
        {
            enFazlaHarf=sonuc[i];
        }
        
    }
    

    //çıktılar
    printf("Cumle Sayisi %d\n",cumle);
    printf("Kelime Sayisi %d\n",kelime);
    printf("Harf Sayisi %d\n\n",harfSay);

    for (i = 0; i < enFazlaHarf; i++)
    {
        for (j = 0; j<26; j++)
        {
            if (0<(sonuc[j]-enFazlaHarf+i+1)){
                matrisDepo[i][j]='|';
            }else{
                matrisDepo[i][j]=' ';
            }
            
        }
        
    }

    for (i = 0; i < enFazlaHarf; i++)
    {
        for (j = 0; j<26; j++)
        {
            printf(" %c ",matrisDepo[i][j]);
            
        }
        printf("\n");
        
    }
    printf("\n");

    for (j = 0; j<26; j++)
    {
        printf("|%c|",j+'a');
            
    }
    
    //harfleri yaz
    /*
    for(i=0;i<26;i++){
        printf("%c  %d",('a'+i),sonuc[i]); 
        for (j = 0; j < sonuc[i]; j++)
        {
            printf("*");
        }
        printf("\n");
        
    }*/


    return 0;
}   