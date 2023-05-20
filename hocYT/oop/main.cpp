#include <bits/stdc++.h>

using namespace std;

/*
oop tập chung vào đối tượng
*/

/*
CLASS
    Bao gồm: Thuộc tính ( atttribute) và Phương thức (methoh)
    Object (Đối tượng) : Là thực thể của Class
    Constructor: Hàm khởi tạo. Có cùng tên với CLASS và KHÔNG có kiểu trả về 
    Destructor: Hàm huỷ. Có cùng tên với CLASS và KHÔNG có kiểu trả về. NHƯNG không thể ghi đè.
    This pointer : COn trỏ this.
    Setter and Getter
    Static trong CLASS (Kiểu tự động gán ID)
    Friend function, friend class
    Operator overloading
Tính chất
    1. Encapsulation (Đóng gói)

Access modifier : 
        Private: Thường là thuộc tính
        Public:  Thường là phương thức
        Protected: 
*/

class GiaoVien;
class SinhVien;


class SinhVien{
    //Friend CLASS
    friend class GiaoVien;
    //...
    private:
        string id, ten;
        double gpa;
        static int dem;
    public:
        SinhVien(); //constructor
        SinhVien(string, string,  double); //constructor
        void xinChao();
        void diHoc();

        void nhap();
        void in();

        //static trong CLASS

        void tangDem();
        int getDem();

        //Friend function
        friend void inthongTin(SinhVien);
        friend void chuanHoa(SinhVien&);
        //Friend CLASS

        //~SinhVien();
};
//Friend function
void inthongTin(SinhVien a){
    cout << a.ten << " " << a.gpa << endl;
}

void chuanHoa(SinhVien& a){
    string res = "";
    stringstream ss(a.ten);
    string token;
    while(ss >> token){
        res += toupper(token[0]);
        for (int i = 1; i < token.length(); i++)
        {
            res += tolower(token[i]);
        }
        res += " ";
    }
    res.erase(res.length() - 1);
    a.ten = res;
}
//static trong CLASS
int SinhVien::dem = 0;
void SinhVien::tangDem(){
    ++dem;
}
int SinhVien::getDem(){
    return dem;
}

//Implementation
// SinhVien::~SinhVien(){
//     cout << "Doi tuong da duoc huy!!!" << endl;
// }
SinhVien::SinhVien(){
    cout << "Ham khoi tao duoc goi !!!" << endl;
}
SinhVien::SinhVien(string id, string ten, double gpa){
    cout << "Ham khoi tao co tham so duoc goi" << endl;
    this->id = id;
    this->ten = ten;
    this->gpa = gpa;
}
void SinhVien::xinChao(){
    cout << "Hello"<<endl;
}

void SinhVien::diHoc(){
    cout << "Di hoc" << endl;
}

void SinhVien::nhap(){
    //static trong CLASS
    ++dem; //dem =1 ;
    /* Tự đông tăng ID của sinh viên lên mỗi khi nhập thông tin sinh viên*/
    this->id = "SV" + string(3 - to_string(dem).length(),'0') + to_string(dem);
    cout << "Nhap ten: ";
    getline(cin, this->ten);
    // cout << "Nhap id: ";
    // cin >> this->id;
    cout << "Nhap GPA: ";
    cin >> this->gpa;
    cin.ignore();
}
void SinhVien::in(){
    cout << "ID: " << this->id << " - " << "Ten: " << this->ten << " - " << "GPa: " << this->gpa << endl;
}

/* Friend CLASS*/
class GiaoVien{
    private:
        string khoa;
    public:
        void update(SinhVien&);
};
void GiaoVien::update(SinhVien& x){
    x.gpa = 5;
}
int main(int argc, char const *argv[])
{
    SinhVien sv;
    /* sv.diHoc();
    SinhVien x("111", "LAM", 9);
    sv.xinChao();
    sv.nhap();
    sv.in();
    
    int n; cin >> n;
    SinhVien a[100];
    for(int i =0 ; i< n; i++){
        a[i].nhap();
    }
    for(int i = 0; i<n; i++){
        a[i].in();
    }
    */


    /*static trong CLASS
    sv.tangDem(); //dem =1
    sv.tangDem(); // dem = 1
    SinhVien y;
    cout << y.getDem() << endl; //dem = 2

    SinhVien s[10];
    int n; cin >> n;
    for(int i =0 ; i< n; i++){
        s[i].nhap();
    }
    for(int i = 0; i<n; i++){
        s[i].in();
    }
    */

   /*Friend function, class*/
    sv.nhap();
    chuanHoa(sv);
    GiaoVien y;
    y.update(sv);
    inthongTin(sv);
    return 0;
}
