#include<bits/stdc++.h>

using namespace std;

/* thư viện string*/
#include <string>
/* Vector */
#include <vector>

int main(int argc, char const *argv[])
{
    int arr[10];

    vector<int> array;

    array.push_back(8);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);

    for(int i = 0; i < array.size() ; i++){
        cout << array[i] << " " ;
    }
    return 0;
}
