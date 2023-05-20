#include <bits/stdc++.h>

using namespace std;
/*
    Các phần tử trong MAP sẽ lưu các cặp key value.
    map<dâttype1, dâttype2> mp;
*/

//1. Đếm số lần xuất hiện các phần tử trong mảng
//2. Đếm số lần xuất hiện nhiều nhất ở trong xâu

int main(int argc, char const *argv[])
{
    map<int, int> mp; //(key, value)
    
    int n; cin >> n;
    int a[100];
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
        mp[a[i]]++ ;
    }
    cout << "1" << endl;
    for(int i = 0 ; i < n ; i++){
        if(mp[a[i]] != 0){
            cout << a[i] << " " << mp[a[i]] << endl;
            mp[a[i]] = 0;
        }
    }

    cout << "2" << endl;

    map<string, int> mp2;
    int n2; cin >> n2;
    for(int i = 0; i < n2; i++){
        string s; cin >> s;
        mp2[s]++;
    }

    for(auto it2 : mp2){
        cout << it2.first << it2.second << endl;
    }

    int max_fre = 0;
    string res;
    for(auto it3 : mp2){
        if(it3.second > max_fre){
            max_fre = it3.second;
            res = it3.first;
        }
    }
    cout << res << " " << max_fre << endl;


    return 0;
}
