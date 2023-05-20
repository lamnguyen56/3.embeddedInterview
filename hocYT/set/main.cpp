/*SETS*/
/*

LƯU ĐƯỢC CÁC TẬP HỢP. MÀ CÁC TẠP HỢP ĐÁY KHÔNG CHO PHÉP CÓ HAI PHẦN TỬ GIỐNG NHAU

*/

#include <bits/stdc++.h>
#include <set>

using namespace std;

/*
    Độ phức tạp thuật toán O(logn)

    1. Insert
        Thêm phần tử trong SETS
    2. Size
        Trả về số lượng phần tử trong SET
    3. Find - Count
        s.count(x): return 1 : Nếu s chứa x 
                    return 0 : Nếu không chứa.
        s.find(x): 
    4. Erase 
    5. Begin
        s.begin() : Truy cập phần tử đầu tiên của SET(Tức phần tử cuối cùng)
    6. rBegin
        s.rbegin() : Phần tử cuối cùng trong SET
    7. 

    

*/
int main(int argc, char const *argv[])
{
    set<int> s;

    /* 1
    s.insert(100);
    s.insert(100);
    s.insert(200);
    s.insert(300);

    cout << s.size() << endl;
    */

    /*2
    for(int i = 0; i < 10; i++){
        s.insert(i);
    }
    cout << s.size() << endl;
    //count
    if(s.count(2) != 0){
        cout << "Found !" << endl;
    }else {
        cout << " Not Found " << endl;
    }
    //find
    if(s.find(5) != s.end()){
       cout << "Found !" << endl;
    }else {
        cout << " Not Found " << endl;
    }
    */

    /*3 Erase
    for(int i = 0; i < 10; i++){
        s.insert(i);
    }
    s.erase(5);
    cout << s.size() << endl;
    */

    /*Duyệt qua các phần tử của SET*/
    for(int i = 0; i < 10; i++){
        s.insert(i);
    }
    //duyệt
    for(int x : s){
        cout << x << " ";
    } cout << endl;
    //hoặc
    for(auto x : s){
        cout << x << " ";
    } cout << endl;
    return 0;
}
