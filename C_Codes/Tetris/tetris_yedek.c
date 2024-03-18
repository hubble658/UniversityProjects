#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#define SYMBOLSIZE 3
#define CURSOR_TO(X,Y) printf("\033[%d;%dH",Y,X)


void rotateLeft(int arr[SYMBOLSIZE][SYMBOLSIZE]){
    int i = 0;
    int j = 0;
    int rotatedArr[SYMBOLSIZE][SYMBOLSIZE];

    for(i=0;i<SYMBOLSIZE;i++){
        for(j=0;j<SYMBOLSIZE;j++){
            rotatedArr[2-j][i]=arr[i][j];
        }
    }
    memcpy(arr,rotatedArr,sizeof(int)*SYMBOLSIZE*SYMBOLSIZE);
}

void rotateRight(int arr[SYMBOLSIZE][SYMBOLSIZE]){
    int i = 0;
    int j = 0;
    int rotatedArr[SYMBOLSIZE][SYMBOLSIZE];

    for(i=0;i<SYMBOLSIZE;i++){
        for(j=0;j<SYMBOLSIZE;j++){
            rotatedArr[j][2-i]=arr[i][j];
        }
    }
    memcpy(arr,rotatedArr,sizeof(int)*SYMBOLSIZE*SYMBOLSIZE);
}



void placeSymbol(int symbol[3][3], int x_cord,int** array, int fRows, int fColumns){
    int enSol;
    int enUst;
    int devam=1;
    int xUzunluk=0;
    int yUzunluk=0;
    int dus=1;
    int kontrol;

    int i,j,k;
    int k_satir;
    int k_sutun;
    i=0;
    while((i<3)&&(devam==1))
    {
        for (j = 0; j < 3; j++)
        {
            if(symbol[j][i]==2){
                enSol=i;
                devam=0;
            }
        }
        i++;
    }
    i=0;
    devam=1;
    while((i<3)&&(devam==1))
    {
        for (j = 0; j < 3; j++)
        {
            if(symbol[i][j]==2){
                enUst=i;
                devam=0;
            }
        }
        i++;
    }
    //uzunluk bulma
    for (i = 0; i < 3; i++)
    {   
        k=0;
        for (j = 0; j < 3; j++)
        {
            if (symbol[j][i]==2)
            {
                k=1;
            }
            
        }
        if(k==1){
            xUzunluk++;
        }
    }
    printf("\nx uzunluk%d\n",xUzunluk);

    for (i = 0; i < 3; i++)
    {   
        k=0;
        for (j = 0; j < 3; j++)
        {
            if (symbol[i][j]==2)
            {
                k=1;
            }
            
        }
        if(k==1){
            yUzunluk++;
        }
    }
    //printf("\ny uzun %d\n",yUzunluk);

    while ((x_cord+xUzunluk-1)>fColumns)
    {
        x_cord--;
        //printf("\n x cord %d",x_cord);
    }
    

    k_satir=0;
    k_sutun=0;
    //printf("\n1\nust%d,+yU%d,ensol%d\n",enUst,yUzunluk,enSol);

    for (i = enUst; i < enUst+yUzunluk; i++)
    {
        k_sutun=0;
        for (j = enSol; j < enSol+xUzunluk; j++)
        {
            array[k_satir][x_cord-1+k_sutun]=symbol[i][j];
            //printf("2");
            k_sutun++;
            
        }
        k_satir++;
        
    }
    

    
}

void drawTable(int** array, int fRows, int fColumns,int array2[SYMBOLSIZE][SYMBOLSIZE]){

    int i = 0;
    int j = 0;
    
    system("cls");   
        
     //üstte yazdır
    printf("\033[1;32m");
    for (i = 0; i < SYMBOLSIZE; i++)
    {
        for (j = 0; j < SYMBOLSIZE; j++)
        {
            CURSOR_TO(fColumns+j,i+2);
            if(array2[i][j]==2){
                printf("*");
            }else{
                printf(" ");
            }
        }
    }
        printf("\033[1;0m");

        printf("\n\n");
    
    
    for (i=0; i<fRows; i++){
        printf("|");
        for (j=0; j<fColumns; j++){
            if (array[i][j]==0)
            {
                //printf("%d|",array[i][j]); // Burayı boşluk ve yıldızlar olarak değiştir
                printf(" |");            
            }else{
                //printf("%d|",array[i][j]);
                printf("\033[1;32m");
                printf("*");
                printf("\033[1;0m");
                printf("|");
            }

            }
        printf("\n");
    }
    for (i = 0; i < fColumns; i++)
    {
        printf("--");
    }

    printf("\n"); 
    printf("|");
    if (fColumns<10)
    {
        for (j=0; j<fColumns; j++){
    
            printf("%d|",(j+1));
        }
    }else{
        for (j=0; j<fColumns; j++){
    
            printf("%d|",(j+1)/10);
        }
        printf("\n"); 
        printf("|");
        for (j=0; j<fColumns; j++){
    
            printf("%d|",(j+1)%10);
        }
    }
    
    
}

void moveDown(int** array, int fRows, int fColumns){
    int i,j;
    int control=1;

    for(i=(fRows-1);i>-1;i--){
        for (j = 0; j < fColumns; j++)
        {  
            if(array[i][j]==2)
            {
                array[i][j]=0;
                array[i-1][j]=2;
            }
                
        }
            
    }
}

int isCollison(int** array, int fRows, int fColumns){
    int i,j;

    for(i=(fRows-1);i>-1;i--){
        for (j = 0; j < fColumns; j++)
        {  
            if(array[i][j]==2&&array[i-1][j])
            {   
                return 1;
            }
                
        }
            
    }
    return 0;
}

void newShape(int arr[SYMBOLSIZE][SYMBOLSIZE]){

    int i;

    int shape1[SYMBOLSIZE][SYMBOLSIZE]={
        {0,2,0},
        {2,2,2},
        {0,0,0}
                   };                
    int shape2[SYMBOLSIZE][SYMBOLSIZE]={
        {2,0,0},
        {2,0,0},
        {2,2,0}
                   };
    int shape3[SYMBOLSIZE][SYMBOLSIZE]={
        {0,0,0},
        {2,2,2},
        {0,0,0}
                   };
    int shape4[SYMBOLSIZE][SYMBOLSIZE]={
        {0,0,0},
        {0,2,2},
        {2,2,0}
                   };
    int shape5[SYMBOLSIZE][SYMBOLSIZE]={
        {0,0,0},
        {0,2,2},
        {0,0,0}
                   };
    int shape6[SYMBOLSIZE][SYMBOLSIZE]={
        {0,0,0},
        {0,2,0},
        {0,0,0}
                   };
    int shape7[SYMBOLSIZE][SYMBOLSIZE]={
        {2,2,0},
        {2,2,0},
        {0,0,0}
                    };               

    i = rand()%7;

    switch (i)
    {
    case 0:
        memcpy(arr,shape1,sizeof(int)*SYMBOLSIZE*SYMBOLSIZE);
        break;
    case 1:
        memcpy(arr,shape2,sizeof(int)*SYMBOLSIZE*SYMBOLSIZE);
        break;
    case 2:
        memcpy(arr,shape3,sizeof(int)*SYMBOLSIZE*SYMBOLSIZE);
        break;
    case 3:
        memcpy(arr,shape4,sizeof(int)*SYMBOLSIZE*SYMBOLSIZE);
        break;
    case 4:
        memcpy(arr,shape5,sizeof(int)*SYMBOLSIZE*SYMBOLSIZE);
        break;
    case 5:
        memcpy(arr,shape6,sizeof(int)*SYMBOLSIZE*SYMBOLSIZE);
        break;
    case 6:
        memcpy(arr,shape7,sizeof(int)*SYMBOLSIZE*SYMBOLSIZE);
        break;

    default:
        break;
    }


}

int main(){

    int i,j;
    int rows;
    int columns;
    int isAlive=1;

    int userRotate=0;
    int userPlace;

    int **gameTable;
    int currentShape[SYMBOLSIZE][SYMBOLSIZE];
    int nextShape[SYMBOLSIZE][SYMBOLSIZE];
    
    
    time_t t1;
    srand((unsigned)time(&t1));
    


    printf("-----Tetris-----\n");
    do{
        printf("Tablonun satir sayisini girin:");
        scanf("%d",&rows);
        printf("Tablonun sutun sayisini girin:");
        scanf("%d",&columns);
        printf("\n\n");

        if((rows<SYMBOLSIZE)||(columns<SYMBOLSIZE)){
            printf("\nSatir veya sutun sayisi 3 den kucuk olamaz tekrar girin\n\n");
        }
    }while((rows<SYMBOLSIZE)||(columns<SYMBOLSIZE));
    



    //Oyun tablosunu olu�tur
    
    gameTable = malloc(sizeof(int *) * rows);
    
    for (i=0;i<rows;i++){
        
        gameTable[i]= malloc(sizeof(int) * columns);    
    }
    for (i=0;i<rows;i++){
        for(j=0;j<columns;j++){
        gameTable[i][j]=0;
        }
    }

    newShape(nextShape);
    newShape(currentShape);
    
    
    while (isAlive==1){

        drawTable(gameTable,rows,columns,currentShape);
        printf("\n");


        // Sekli dönder
        while (((userRotate!='S')&&(userRotate!='s')))
        {

            printf("\nSekili dondermek icin A-D tuslarini kullanin.\nYerlestirmek icin S ye basin.\n");
            
            userRotate=getchar();

            if ((userRotate=='A')||(userRotate=='a'))
            {
                rotateLeft(currentShape);
                drawTable(gameTable,rows,columns,currentShape);
            }else if((userRotate=='D')||(userRotate=='d')){
                rotateRight(currentShape);
                drawTable(gameTable,rows,columns,currentShape);
          }
          
        }


        printf("Yerlestirmek istediginiz sutunu girin:");
        do
        {   
            printf("1-%d arasinda olmali.\n",columns);
            scanf("%d",&userPlace);
        } while (userPlace>columns);



        /*
        placeSymbol(currentShape,userPlace,gameTable,rows,columns);
        
        drawTable(gameTable,rows,columns,currentShape);
        newShape(currentShape);
        Sleep(10);*/
    }
    
    for(int i = 0; i < rows; i++){
        free(gameTable[i]);
    }
        
    free(gameTable);

    return 0;
}
    