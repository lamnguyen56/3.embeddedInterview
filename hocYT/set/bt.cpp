#include <bits/stdc++.h>
#include <set>

using namespace std;

/*Nhập vào mảng. Đếm số lượng phần tử khác nhau trong mảng*/

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    set <int> s;
    for(int i = 0; i < n; i ++){
        int x; cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;
    /*
    input: 
        5
        1 1 3 4 2
    output
        4
    */
    return 0;
}
