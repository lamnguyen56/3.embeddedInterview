/**
 * @author Lam Nguyen
 * @email nguyenthualam1@gmail.com
 * @modify date 2023-05-09
 * @desc [NHẬP NGÀY, THÁNG, NĂM. IN RA THỨ MẤY TRONG TUẦN]
 */

#include <stdio.h>


/*
* Function: laNamNhuan
* Description: Kiểm tra năm có phải là năm nhuận hay không.
* Example:
* Input:
*   int nam
* Output:
*   return: 1 la năm nhuận
*   return: 0 không phải là năm nhuận
*/
int laNamNhuan(int nam) {
    if (nam % 400 == 0)
        return 1;
    if (nam % 100 == 0)
        return 0;
    if (nam % 4 == 0)
        return 1;
    
    return 0;
}


/*
* Function: tinhThu
* Description: Tính thứ của một ngày trong năm.
* Example:
* Input:
*   int ngay, thang, nam
* Output:
*   return: thu
*/
int tinhThu(int ngay, int thang, int nam) {
    int ngayTrongThang[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//MẢNG LƯU SỐ NGÀY CỦA CÁC THÁNG CÓ NĂM KHÔNG NHUẬN
    int ngayTong = ngay;//KHỞI TẠO SỐ NGÀY TÍNH TỪ ĐẦU NĂM

    for (int i = 0; i < thang - 1; i++) {
        ngayTong += ngayTrongThang[i];//CỘNG DỒN SỐ NGÀY CỦA CÁC THÁNG TRƯỚC ĐÓ
    }

    if (thang > 2 && laNamNhuan(nam)) {//NẾU THÁNG HIỆN TẠI >2 VÀ LÀ NĂM NHUẬN THÌ THÊM 1 NGÀY CHO THÁNG 2
        ngayTong++;
    }

    /* TÍNH THỨ CỦA NGÀY ĐÓ  */
    int thu = (ngayTong + nam - 1) % 7;

    return thu;
}

int main() {
    int ngay, thang, nam;

    printf("Nhap ngay: ");
    scanf("%d", &ngay);

    printf("Nhap thang: ");
    scanf("%d", &thang);

    printf("Nhap nam: ");
    scanf("%d", &nam);

    /*KIỂM TRA NGÀY THÁNG NĂM CÓ HỢP LỆ KHÔNG*/
    if (thang < 1 || thang > 12 || ngay < 1 || ngay > 31 || nam < 1) {
        printf("Nhap ngay, thang, nam khong hop le.\n");
        return 0;
    }

    if (thang == 2) {
        if (laNamNhuan(nam)) {                          //NẾU LÀ NĂM NHUẬN THÌ CHỈ CÓ TỐI ĐA LÀ 29 NGÀY
            if (ngay > 29) {
                printf("Thang 2 nam nhuan chi co toi da 29 ngay.\n");
                return 0;
            }
        } else {                                        //NẾU KHGOONG PHẢI LÀ NĂM NHUẬN THÌ CÓ TỐI ĐA LÀ 28 NGÀY
            if (ngay > 28) {
                printf("Thang 2 chi co toi da 28 ngay.\n");
                return 0;
            }
        }
    } else {                                            //NẾU KHÔNG PHẢI THÁNG 2
        int ngayTrongThang[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (ngay > ngayTrongThang[thang - 1]) {         //KIỂM TRA SỐ NGÀY CỦA THÁNG ĐÓ
            printf("Ngay nhap vao khong hop le.\n");
            return 0;
        }
    }

    int thu = tinhThu(ngay, thang, nam);                //GỌI HÀM TÍNH THỨ

    switch (thu) {                                      //DÙNG switch ĐỂ IN RA THỨ CỦA NGÀY ĐÓ
        case 0:
            printf("Ngay %d/%d/%d la Chu Nhat\n", ngay, thang, nam);
            break;
        case 1:
            printf("Ngay %d/%d/%d la Thu Hai\n", ngay, thang, nam);
            break;
        case 2:
            printf("Ngay %d/%d/%d la Thu Ba\n", ngay, thang, nam);
            break;
        case 3:
            printf("Ngay %d/%d/%d la Thu Tu\n", ngay, thang, nam);
            break;
        case 4:
           printf("Ngay %d/%d/%d la Thu 5\n", ngay, thang, nam);
            break;
        case 5:
           printf("Ngay %d/%d/%d la Thu 6\n", ngay, thang, nam);
            break;
        case 6:
           printf("Ngay %d/%d/%d la Thu 7\n", ngay, thang, nam);
            break;
        default:
            printf("Nhap ngay, thang, nam khong hop le.\n");
            break;
           
    }
      return 0;
}   
