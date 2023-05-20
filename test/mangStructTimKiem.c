#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct SV{
    char ma[10];
    char ten[20];
    float gpa;
};

typedef struct SV SV;

void nhap(SV *a){
    scanf("%s", a->ma);
    getchar();
    gets(a->ten);
    scanf("%f", &a->gpa);
}

void in(SV a){
    printf("Ma: %s - Ten: %s - GPA: %f\n",a.ma, a.ten, a.gpa);
}

void timKiem(SV a[],int n, char s[100]){
    for(int i=0; i<n; i++){
        if(strcmp(s ,a[i].ma) == 0){
            in(a[i]); return;
        }
    }
}

int main(){
    
    int n ;
    scanf("%d", &n);
    SV a[n];
    for(int i = 0; i<n; i++) nhap(&a[i]);
    for(int i = 0; i<n; i++) in(a[i]);

    printf("Nhap ma sv can tim kiem");
    char s[100];
    scanf("%s", &s);
    timKiem(a, n, s);
    
    return 0;
}