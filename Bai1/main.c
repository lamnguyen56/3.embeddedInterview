#include <stdio.h>
#include "stdlib.h"

#define SIZE 10
int temp[SIZE];

void  insertionSort(int arr[],int size){
    int temp,j ;
    for(int i = 1; i<SIZE; i++)
    {
        j = i;
        while(j>0 && arr[j]<=arr[j-1])
        {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                j--;
        }
    }
    
}

void countElement(int arr[], int size){
    int temp[SIZE]; //dung mang tam de danh dau cac phan tu duoc xet hay chua duoc xet

    for(int i = 0; i<size ; i++){
        int count = 1;
        if(temp[i]) //true khi temp[i] != 0 
        {
            temp[i]=0;
            for(int j = i + 1; j<size; j++)
            {
                if(arr[j] == arr[i])
                {
                    count ++;
                    temp[j]=0; //nhung phan tu nao trung thi gan gia tri do vo mang temp = 0 
                }
            }
            printf("So %d xuat hien %d lan\n", arr[i], count);
        }
    }
    
}

void input(int *arr, int size){
    for(int i=0; i<SIZE;i++)
    {
        arr[i] = rand() % 10;
    }
}

void output(int *arr, int size){
    for(int i =0; i<SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    int arr[SIZE];
    

    input(arr, SIZE);
    output(arr, SIZE);

    insertionSort(arr, SIZE);
    output(arr, SIZE);

    countElement(arr, SIZE);

    return 0;
}