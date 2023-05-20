/*
multiset : Có thê lưu các phần tử giống nhau
*/

#include <bits/stdc++.h>
#include <set>

using namespace std;

/*
Cho mảng có n phần tử và số nguyên k, đối với mỗi dãy con liên tiếp có chiều k
In ra được phần tử lớn nhất trong dãy con đó
input n = 10, k =3;
1 2 3 1 4 5 1 8 9 10
output
vi du:  1 2 3 -> 3
        2 3 1 -> 3
        ....
    3 3 4 5 5 8 9 10
*/
int main(int argc, char const *argv[])
{
    int n = 10; int k = 3;
    
    int a[10] = {1, 2, 3, 1, 4, 5, 1, 8, 9, 10};
   //for( int &x : a) cin >> x;
    multiset<int> ms;

    //them k phần tử vào trong multiset
    for(int i = 0 ; i < k; i++){
        ms.insert(a[i]);
    }
    // for(auto x : ms){
    //     cout << x << " ";
    // } cout << endl;

    for(int i = k; i <n; i++){
        cout << *ms.rbegin() << " ";
        ms.erase(ms.find(a[i-k]));
        ms.insert(a[i]);
    }
    cout << *ms.rbegin() << endl;
    return 0;
}