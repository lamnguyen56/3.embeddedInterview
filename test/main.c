#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct date{
    int ngay, thang, nam;
};

struct hour{
    int gio, phut, giay;
};

struct ticket{
    char tenPhim[100];
    double giaVe;
    struct date NgayXem;
    struct hour GioXem;
};
struct SinhVien{
    char ma[20];
    char ten[50];
    double gpa;
    char lop[20];
};

struct HocSinh{
    char ten[20];
    double diem;

};

typedef struct HocSinh HS;

//nhap thong tin tra ve struct

HS nhap(){
    HS x;
    gets(x.ten);
    scanf("%lf", &x.diem);
    return x;
}

void nhap2(HS *a){
    gets(a->ten);
    scanf("%lf", &a->diem);
}
void in(HS a){
    printf("%s, %.2lf\n", a.ten,a.diem);
}

typedef struct SinhVien SV;
typedef struct ticket VE;

int main()
{



    // SV sv;
    // //dot operator
    // scanf("%s", sv.ma);
    // getchar();
    // gets(sv.ten);
    // scanf("%lf%s", &sv.gpa, sv.lop);
    // printf("%s %s %.2f %s\n",sv.ma, sv.ten, sv.gpa, sv.lop);

    // VE ve;
    // ve.giaVe;
    // ve.tenPhim;
    // ve.NgayXem.thang;
    // ve.NgayXem.ngay;
    // ve.NgayXem.nam;

    HS a = nhap();
    in(a);
    nhap2(&a);
    in(a);
    return 0;
}