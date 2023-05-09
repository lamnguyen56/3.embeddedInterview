/**
 * @author Lam Nguyen
 * @email nguyenthualam1@gmail.com
 * @create date 2023-04-26 22:15:41
 * @modify date 2023-04-26
 * @desc [Nhập vào một số kiểm trả xem trong arr có số vừa nhập hay không]
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000


/*
* Function: input
* Description: Tạo ra mảng ngẫu nhiên từ 000 - 999
* Input:
*   int arr[]
*   int size
* Output:
*   arr[SIZE]
*/
void input(int *arr[], int size){
    for(int i=0; i<SIZE;i++)
    {
        arr[i] = rand() % 1000;//NHẬP GIÁ TRỊ NGẪU NHIÊN TỪ 000-999 VÀO MẢNG arr[]
    }
}

/*
* Function: output
* Description: In ra các phần tử của mảng
* Input:
*   int arr[]
*   int size
* Output:
*   arr[SIZE]
*/
void output(int *arr, int size){
    for(int i =0; i<SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
* Function: insertionSort
* Description: Sắp xếp mảng theo thứ tự tăng dần bằng thuật toán sắp xếp chèn.
* Idea:
* Input:
*   int arr[]
*   int size
* Output:
*   arr[] đã được sắp xếp
*/
void insertionSort(int arr[], int size){
    int temp, j;
    for(int i = 1; i< size ; i++){
        j = i;
        while(j>0 && arr[j] <= arr[j - 1]){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

/*
* Function: binarySearch
* Description: Thuật toán tìm kiếm nhị phân
* Input:
*   int arr[]
*   int size
*   int k
* Output:
*   return mid
*/
int binarySearch(int arr[], int size, int k)
{
    int left = 1;
    int right = size;
    int mid;
    while (left <= right)
    {
        mid = (left+right)/2;
        if(arr[mid]==k)
        {
            return mid+1;
        }else if(arr[mid]<k)
        {
            left = mid+1;
        }else right = mid -1;

    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[SIZE];
    int k;

    input(arr, SIZE);
    int sz = sizeof(arr)/sizeof(arr[0]);
    output(arr, SIZE);
    printf("Nhap so can tim: ");
    scanf("%d", &k);
   
    insertionSort(arr, SIZE);

    output(arr, SIZE);
    printf("%d o vi tri %d", k,binarySearch(arr, sz, k));
    return 0;
}

