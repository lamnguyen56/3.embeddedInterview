/*OOP*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

class DoiTuong{
    public:
        char TEN[20];
        uint8_t TUOI;
        void setData(char ten[], uint8_t tuoi);
        void getData();
};

void DoiTuong::setData(char ten[], uint8_t tuoi){
    strcpy(DoiTuong::TEN, ten);
    DoiTuong::TUOI = tuoi;
}
void DoiTuong::getData(){
    printf("Day la class Doi Tuong\n");
    printf("Ten: %s\n", TEN);
    printf("Ten: %d\n", TUOI);
}
class SinhVien : public DoiTuong{
    public:
        uint8_t SINH_VIEN_NAM;
};

int main(int argc, char const *argv[])
{
    
    DoiTuong dt;

    dt.setData((char*)"Lam", 22);
    dt.getData();



    return 0;
}
