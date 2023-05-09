/**
 * @author Lam Nguyen
 * @email nguyenthualam1@gmail.com
 * @create date 2023-04-27
 * @modify date 2023-04-27
 * @desc [description]
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
* Function: printNum
* Description: in từ tương ứng với một số (từ 0 đến 9).
*/
void printNum(int num, uint8_t soLuong){
    switch (num)
    {
    case 0:
        if(soLuong == 5 || soLuong == 2){

        }else printf(" KHONG ");
        break;
    case 1:
        printf(" MOT ");
        break;
    case 2:
        printf(" HAI ");
        break;
    case 3:
        printf(" BA ");
        break;
    case 4:
        printf(" BON ");
        break;
    case 5:
        printf(" NAM ");
        break;
    case 6:
        printf(" SAU ");
        break;
    case 7:
        printf(" BAY ");
        break;
    case 8:
        printf(" TAM ");
        break;
    case 9:
        printf(" CHIN ");
        break;
    
    default:
        break;
    }
}

/*
* Function: tachSo
* Description: Tách số
*/
void tachSo(uint32_t n){

    uint8_t size = 1;
    uint8_t *ptr = (uint8_t *)malloc(size*sizeof(uint8_t));

    while(1){
        *(ptr + size - 1) = n%10;
        n = n/10;
        if(n == 0) break;
        ++size;
        realloc(ptr, size*sizeof(uint8_t));
    }

    uint8_t soLuong = size;
    for(int i = size - 1  ; i >= 0 ; i--){
        
        printNum(*(ptr + i ), soLuong);
        
        if(soLuong == 7)
        {
            printf(" TRIEU ");
        }
        if(soLuong == 6 || soLuong == 3)
        {
            printf(" TRAM ");
        }
        if(soLuong == 5 || soLuong == 2 )
        {
            if(*(ptr+ i) == 0){
                printf(" LE ");
            }else printf(" MUOI ");
        }
        if(soLuong == 4)
        {
            printf(" NGAN ");
        }
        soLuong--;
    }

}

int main(int argc, char const *argv[])
{
    uint32_t n;
    printf("Nhap: ");
    scanf("%d", &n);
    
    tachSo(n);
    return 0;
}
