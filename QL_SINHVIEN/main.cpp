/**
 * @author Lam Nguyen
 * @email nguyenthualam1@gmail.com
 * @create date 2023-05-25
 * @desc [QUAN LY SINH VIEN]
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

typedef enum {
    GIOI,
    KHA,
    TRUNGBINH,
    YEU
} TypeHocLuc;


/*Class SinhVien*/
class SinhVien {
private:
    int id;
    string ten;
    string gioiTinh;
    int tuoi;
    float diemToan;
    float diemLy;
    float diemHoa;
    float trungBinh;
    TypeHocLuc hocLuc;

    void capNhatDiemTrungBinh();

public:
    // Constructor
    SinhVien(int id, const string& ten, const string& gioiTinh, int tuoi,
             float diemToan, float diemLy, float diemHoa);

    // Getter methods
    int getId() const;
    const string& getTen() const;
    const string& getGioiTinh() const;
    int getTuoi() const;
    float getDiemToan() const;
    float getDiemLy() const;
    float getDiemHoa() const;
    float getTrungBinh() const;
    TypeHocLuc getHocLuc() const;

    // Setter methods
    void setTen(const string& ten);
    void setGioiTinh(const string& gioiTinh);
    void setTuoi(int tuoi);
    void setDiemToan(float diemToan);
    void setDiemLy(float diemLy);
    void setDiemHoa(float diemHoa);

    // Other methods
    void hienThiThongTin() const;
};


/*
* Class: SinhVien
* Description: The constructor implementation for the SinhVien class 
*/
SinhVien::SinhVien(int id, const string& ten, const string& gioiTinh, int tuoi,
                   float diemToan, float diemLy, float diemHoa)
    : id(id), ten(ten), gioiTinh(gioiTinh), tuoi(tuoi),
      diemToan(diemToan), diemLy(diemLy), diemHoa(diemHoa) {
    capNhatDiemTrungBinh();
}

/*
* Class: SinhVien
* Function: getId
* Description: This function use for get ID of student
* Input:
*   Dont have input parameters
* Output:
*   return: ID of Student
*/
int SinhVien::getId() const {
    return id;
}

/*
* Class: SinhVien
* Function: getTen
* Description: This function use for get Name of student
* Input:
*   Dont have input parameters
* Output:
*   return: Name of Student
*/
const string& SinhVien::getTen() const {
    return ten;
}

/*
* Class: SinhVien
* Function: getGioiTinh
* Description: This function use for get Sex of student
* Input:
*   Dont have input parameters
* Output:
*   return: Sex of Student
*/
const string& SinhVien::getGioiTinh() const {
    return gioiTinh;
}

/*
* Class: SinhVien
* Function: getTuoi
* Description: This function use for get Age of student
* Input:
*   Dont have input parameters
* Output:
*   return: Age of Student
*/
int SinhVien::getTuoi() const {
    return tuoi;
}

/*
* Class: SinhVien
* Function: getDiemToan
* Description: This function use for get Math scores  of student
* Input:
*   Dont have input parameters
* Output:
*   return: Math scores of Student
*/
float SinhVien::getDiemToan() const {
    return diemToan;
}

/*
* Class: SinhVien
* Function: getDiemLy
* Description: This function use for get Physics scores  of student
* Input:
*   Dont have input parameters
* Output:
*   return: Physics scores of Student
*/
float SinhVien::getDiemLy() const {
    return diemLy;
}

/*
* Class: SinhVien
* Function: getDiemHoa
* Description: This function use for get Chemistry Score  of student
* Input:
*   Dont have input parameters
* Output:
*   return: Chemistry Score of Student
*/
float SinhVien::getDiemHoa() const {
    return diemHoa;
}

/*
* Class: SinhVien
* Function: getTrungBinh
* Description: This function use for get AVG  of student
* Input:
*   Dont have input parameters
* Output:
*   return: AVG of Student
*/
float SinhVien::getTrungBinh() const {
    return trungBinh;
}

/*
* Class: SinhVien
* Function: getHocLuc
* Description: This function use for get type Education  of student
* Input:
*   Dont have input parameters
* Output:
*   return: type Education of Student
*/
TypeHocLuc SinhVien::getHocLuc() const {
    return hocLuc;
}

/*
* Class: SinhVien
* Function: setTen
* Description: This function use for set name of a Student
* Input:
*   string& ten
* Output:
*   return: None
*/
void SinhVien::setTen(const string& ten) {
    this->ten = ten;
}

/*
* Class: SinhVien
* Function: setGioiTinh
* Description: This function use for set sex of a Student
* Input:
*   string& gioiTinh
* Output:
*   return: None
*/
void SinhVien::setGioiTinh(const string& gioiTinh) {
    this->gioiTinh = gioiTinh;
}

/*
* Class: SinhVien
* Function: setTuoi
* Description: This function use for set age of a Student
* Input:
*   int tuoih
* Output:
*   return: None
*/
void SinhVien::setTuoi(int tuoi) {
    this->tuoi = tuoi;
}

/*
* Class: SinhVien
* Function: setDiemToan
* Description: This function use for math score of a Student
* Input:
*   float diemToan
* Output:
*   return: None
*/
void SinhVien::setDiemToan(float diemToan) {
    this->diemToan = diemToan;
    capNhatDiemTrungBinh();
}

/*
* Class: SinhVien
* Function: setDiemLy
* Description: This function use for Physics score of a Student
* Input:
*   float diemLy
* Output:
*   return: None
*/
void SinhVien::setDiemLy(float diemLy) {
    this->diemLy = diemLy;
    capNhatDiemTrungBinh();
}

/*
* Class: SinhVien
* Function: setDiemLy
* Description: This function use for Chemictry score of a Student
* Input:
*   float diemHoa
* Output:
*   return: None
*/
void SinhVien::setDiemHoa(float diemHoa) {
    this->diemHoa = diemHoa;
    capNhatDiemTrungBinh();
}

/*
* Class: SinhVien
* Function: capNhatDiemTrungBinh
* Description: This function use for upate scores of a Student
* Input:
*   None
* Output:
*   return: None
*/
void SinhVien::capNhatDiemTrungBinh() {
    trungBinh = (diemHoa + diemToan + diemLy) / 3;

    if (trungBinh >= 8) {
        hocLuc = GIOI;
    } else if (trungBinh >= 6.5) {
        hocLuc = KHA;
    } else if (trungBinh >= 5) {
        hocLuc = TRUNGBINH;
    } else {
        hocLuc = YEU;
    }
}

/*
* Class: SinhVien
* Function: hienThiThongTin
* Description: This function use for display information of a Student
* Input:
*   None
* Output:
*   return: None
*/
void SinhVien::hienThiThongTin() const {
    cout << setw(5) << left << id;
    cout << setw(20) << left << ten;
    cout << setw(10) << left << gioiTinh;
    cout << setw(5) << left << tuoi;
    cout << setw(10) << left << fixed << setprecision(2) << diemToan;
    cout << setw(10) << left << fixed << setprecision(2) << diemLy;
    cout << setw(10) << left << fixed << setprecision(2) << diemHoa;
    cout << setw(10) << left << fixed << setprecision(2) << trungBinh;

    string hocLucStr;
    switch (hocLuc) {
        case GIOI:
            hocLucStr = "Gioi";
            break;
        case KHA:
            hocLucStr = "Kha";
            break;
        case TRUNGBINH:
            hocLucStr = "Trung binh";
            break;
        case YEU:
            hocLucStr = "Yeu";
            break;
    }

    cout << hocLucStr << endl;
}


/*Class Menu*/
class Menu {
private:
    vector<SinhVien*> database;

public:
    ~Menu();

    void themSinhVien();
    void capNhatSinhVien();
    void xoaSinhVien();
    void timKiemSinhVien();
    void sapXepTheoDiemTrungBinh();
    void sapXepTheoTen();
    void hienThiSV() const;
};

/*Deconsstructor*/
Menu::~Menu() {
    // Giải phóng bộ nhớ của các đối tượng SinhVien trong vector database
    for (SinhVien* sv : database) {
        delete sv;
    }
}

/*
* Class: Menu
* Function: themSinhVien
* Description: This function use for adding a Student
*/
void Menu::themSinhVien() {
    string ten, gioiTinh;
    int tuoi;
    float diemToan, diemLy, diemHoa;

    cin.ignore();
    cout << "Nhap ten sinh vien: ";
    getline(cin, ten);
    cout << "Nhap gioi tinh: ";
    getline(cin, gioiTinh);
    cout << "Nhap tuoi: ";
    cin >> tuoi;
    cout << "Nhap diem Toan: ";
    cin >> diemToan;
    cout << "Nhap diem Ly: ";
    cin >> diemLy;
    cout << "Nhap diem Hoa: ";
    cin >> diemHoa;

    SinhVien* sv = new SinhVien(database.size() + 1, ten, gioiTinh, tuoi,
                                diemToan, diemLy, diemHoa);
    database.push_back(sv);

    cout << "Them sinh vien thanh cong!" << endl;
}

/*
* Class: Menu
* Function: capNhatSinhVien
* Description: This function use for update a Student
*/
void Menu::capNhatSinhVien() {
    int id;
    cout << "Nhap ID sinh vien can cap nhat: ";
    cin >> id;

    bool found = false;
    for (SinhVien* sv : database) {
        if (sv->getId() == id) {
            string ten, gioiTinh;
            int tuoi;
            float diemToan, diemLy, diemHoa;

            cin.ignore();
            cout << "Nhap ten sinh vien: ";
            getline(cin, ten);
            cout << "Nhap gioi tinh: ";
            getline(cin, gioiTinh);
            cout << "Nhap tuoi: ";
            cin >> tuoi;
            cout << "Nhap diem Toan: ";
            cin >> diemToan;
            cout << "Nhap diem Ly: ";
            cin >> diemLy;
            cout << "Nhap diem Hoa: ";
            cin >> diemHoa;

            sv->setTen(ten);
            sv->setGioiTinh(gioiTinh);
            sv->setTuoi(tuoi);
            sv->setDiemToan(diemToan);
            sv->setDiemLy(diemLy);
            sv->setDiemHoa(diemHoa);

            cout << "Cap nhat sinh vien thanh cong!" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay sinh vien co ID " << id << endl;
    }
}

/*
* Class: Menu
* Function: xoaSinhVien
* Description: This function use for delete a Student
*/
void Menu::xoaSinhVien() {
    int id;
    cout << "Nhap ID sinh vien can xoa: ";
    cin >> id;

    auto it = find_if(database.begin(), database.end(), [id](SinhVien* sv) {
        return sv->getId() == id;
    });

    if (it != database.end()) {
        delete *it;
        database.erase(it);
        cout << "Xoa sinh vien thanh cong!" << endl;
    } else {
        cout << "Khong tim thay sinh vien co ID " << id << endl;
    }
}

/*
* Class: Menu
* Function: timKiemSinhVien
* Description: This function use for find a Student
*/
void Menu::timKiemSinhVien() {
    string ten;
    cout << "Nhap ten sinh vien can tim kiem: ";
    cin.ignore();
    getline(cin, ten);

    bool found = false;
    for (SinhVien* sv : database) {
        if (sv->getTen() == ten) {
            sv->hienThiThongTin();
            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay sinh vien co ten " << ten << endl;
    }
}

/*
* Class: Menu
* Function: sapXepTheoDiemTrungBinh
* Description: This function use for soft AVG
*/
void Menu::sapXepTheoDiemTrungBinh() {
    // sort(database.begin(), database.end(), compareDiemTrungBinh);
    // cout << "Da sap xep danh sach sinh vien theo diem trung binh giam dan!" << endl;
    for (size_t i = 0; i < database.size() - 1; ++i) {
        for (size_t j = i + 1; j < database.size(); ++j) {
            if (database[i]->getTrungBinh() > database[j]->getTrungBinh()) {
                swap(database[i], database[j]);
            }
        }
    }

    cout << "Danh sach sinh vien sau khi sap xep theo diem trung binh:" << endl;
    hienThiSV();
}

/*
* Class: Menu
* Function: sapXepTheoTen
* Description: This function use for soft Name
*/
void Menu::sapXepTheoTen() {
    // sort(database.begin(), database.end(), compareTen);
    // cout << "Da sap xep danh sach sinh vien theo ten!" << endl;

    for (size_t i = 0; i < database.size() - 1; ++i) {
        for (size_t j = i + 1; j < database.size(); ++j) {
            if (database[i]->getTen() > database[j]->getTen()) {
                swap(database[i], database[j]);
            }
        }
    }

    cout << "Danh sach sinh vien sau khi sap xep theo ten:" << endl;
    hienThiSV();
}

/*
* Class: Menu
* Function: hienThiSV
* Description: This function use for display  Students
*/
void Menu::hienThiSV() const {
    if (database.empty()) {
        cout << "Danh sach sinh vien trong!" << endl;
        return;
    }

    cout << setw(5) << left << "ID";
    cout << setw(20) << left << "Ten";
    cout << setw(10) << left << "Gioi tinh";
    cout << setw(5) << left << "Tuoi";
    cout << setw(10) << left << "Diem Toan";
    cout << setw(10) << left << "Diem Ly";
    cout << setw(10) << left << "Diem Hoa";
    cout << setw(10) << left << "Diem TB";
    cout << "Hoc luc" << endl;

    for (const SinhVien* sv : database) {
        sv->hienThiThongTin();
    }
}

int main() {
    Menu menu;

    int choice;
    while (true) {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Them sinh vien" << endl;
        cout << "2. Cap nhat sinh vien" << endl;
        cout << "3. Xoa sinh vien" << endl;
        cout << "4. Tim kiem sinh vien" << endl;
        cout << "5. Sap xep danh sach theo diem trung binh" << endl;
        cout << "6. Sap xep danh sach theo ten" << endl;
        cout << "7. Hien thi danh sach sinh vien" << endl;
        cout << "8. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                menu.themSinhVien();
                break;
            case 2:
                menu.capNhatSinhVien();
                break;
            case 3:
                menu.xoaSinhVien();
                break;
            case 4:
                menu.timKiemSinhVien();
                break;
            case 5:
                menu.sapXepTheoDiemTrungBinh();
                break;
            case 6:
                menu.sapXepTheoTen();
                break;
            case 7:
                menu.hienThiSV();
                break;
            case 8:
                cout << "Ket thuc chuong trinh!" << endl;
                return 0;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }
    }

    return 0;
}
