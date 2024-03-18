#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define ADET 10

void printList(int list[]){
      int i,j;
      for (i = 0; i < ADET; i++)
      {
            for (j = 0; j < ADET; j++)
            {
                  if (list[j]-(ADET-i)>=0)
                  {
                        printf("* ");
                  }else{
                        printf("  ");
                  }
                  
            }
            printf("\n");
            
      }
      

}

void selectionSort(int list[])
{
      int i,j,temp;
      int min;

      for ( i = 0; i < ADET-1; i++)
      {
            min=i;
            for (j = i+1; j < ADET; j++)
            {
                  if (list[j]<list[min])
                  {
                        min=j;

                  }
                  
            }
            //swap
            temp=list[i];
            list[i]=list[min];
            list[min]=temp;

            system("cls");
            printf("\n");
            printList(list);
            printf("\n");
            Sleep(50);
      }
}

void bubbleSort(int list[])
{
      int i,j,temp;
      int min;
      int swapped=1;

      i=0;
      while (swapped==1 && (i<ADET))
      {
            j=0;
            swapped=0;
            while (j<ADET-i)
            {
                  if(list[j]>list[j+1]){
                        temp=list[j];
                        list[j]=list[j+1];
                        list[j+1]=temp;
                        swapped=1;
                  }
                  j++;
                  system("cls");
                  printf("\n");
                  printList(list);
                  printf("\n");
                  Sleep(50);
            }
            i++;
      }
}

void insertionSort(int list[])
{
      int i,j,k,temp;

      for (i = 1; i <= ADET; i++)
      {
            if (list[i]<list[i-1])
            {
                  j=i-1;

                  while (j>-1 && list[i]<list[j])
                  {

                        j--;
                  }
                  j++;

                  temp=list[i];
                  for (k = i; k > j; k--)
                  {
                        list[k]=list[k-1];
                  }
                  list[j]=temp;
            }
            system("cls");
            printf("\n");
            printList(list);
            printf("\n");
            Sleep(50);
      }
}


int main(){

      int i,j;
      int number;

      int randomList[ADET];
      time_t t1;
      srand((unsigned)time(&t1));

      for (i = 0; i < ADET; i++)
      {
            randomList[i]=rand()%10+1;

      }
      
      insertionSort(randomList);

      //bubbleSort(randomList);

      //selectionSort(randomList);

      for (i = 0; i < ADET; i++)
      {
            printf("%d ",randomList[i]);
            
      }

}
