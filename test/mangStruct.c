#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct HocSinh{
    char ten[100];
    float diem;
};

typedef struct HocSinh HS;


void nhap(HS *a){
    getchar();
    gets(a->ten);
    scanf("%f",&a->diem);
}

void in(HS a){
    printf("%s, %.f\n", a.ten, a.diem);
}

int main(){
    HS a[1000];
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n;i++) nhap(&a[i]);
    for(int j=0; j<n;j++) in(a[j]);
}