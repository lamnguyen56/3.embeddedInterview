#include <bits/stdc++.h>

using namespace std;
/* name space 
    tạo ra cho mình 1 vùng nhớ riêng mà trong đó mà mình có thể định nghĩa biến, chức năng riêng
*/

namespace A{
    int TEO = 10;

    class SihVien{
        public:
            int tuoi;
    };

}

namespace B{
    int TEO = 20;
}

namespace Truong{
    namespace Lop10{
        int hocSinh;
    }
}

int main(int argc, char const *argv[])
{
    cout << "TEO A: " << A::TEO << endl;
    cout << "TEO B: " << B::TEO << endl;
    
    A::SihVien sv;
    sv.tuoi = 20; 

    Truong::Lop10::hocSinh = 10;
    cout << "HS: " << Truong::Lop10::hocSinh << endl;

    return 0;
}
