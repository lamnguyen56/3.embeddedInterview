#include <bits/stdc++.h>

using namespace std;

/* 
    Virtual function: Hàm ảo
        

*/

class DoiTuong{
    public:
        virtual char *arr(){
            return (char*)"Hello";
        };
        void hienThi(){
            printf("Test: %s\n", arr());
        };
};

class SinhVien : public DoiTuong{
    public:
        char *arr(){
            return (char*)"World!";
        };
};

int main(int argc, char const *argv[])
{
    
    SinhVien sv;
    sv.hienThi();
    return 0;
}
