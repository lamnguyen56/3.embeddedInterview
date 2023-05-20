
#include <bits/stdc++.h>

using namespace std;
/*
    Kế thừa:
        base class: class cha ->Định nghĩa khai báo các thuộc tính, phương thức chung
        drived class: class con 

    Access Modes:
        Public: Nếu lớp con kết thừa là PUBLIC, thì các members của lớp cha được kế thừa ở lớp con
        và giữ nguyên access modifier ()
        Private: Trong trường hợp này thì tất cả các thành phần của lớp cha thì trở thành thành phần PRIVATE
        trong lớp con.
        Protected: Thành phần PUBLIC của lớp cha thì sẽ thành thành phần PROTECED của lớp con.
    Function overiding
.
*/

class Person{
    private:
        string name;
        string address;
    public:

        Person(string name, string address){
            this->name = name;
            this->address = address;
        }

        string getName(){
            return name;
        }
        string getAddress(){
            return address;
        }
        void setName(string name){
            this->name = name;
        }
        void setAddress(string address){
            this->address = address;
        }


        /*function overriding*/
        void nhap(){
            getline(cin, name);
            getline(cin, address);
        }
        void in(){
            cout << name << " " << address << " " ;
        }
};

class Student : public Person{
    private:
        float gpa;
    public:

        /*cóntructor*/
    
        Student(string name, string address, float gpa) : Person(name, address){
            this->gpa = gpa;
        }

        float getGpa(){
            return gpa;
        }
        void setGpa(float gpa){
            this->gpa = gpa;
        }

        //function overriding-ghi đè
        void nhap(){
            Person::nhap();
            cin >> gpa;
        }
        void in(){
            Person::in();
            cout << fixed << setprecision(3) << gpa << endl;
        }
};

int main(int argc, char const *argv[])
{
    // Student s;
    // // s.setName("LAM");
    // // s.setAddress("HCM");
    // // s.setGpa(9.7);
    // s.nhap();
    // cout << s.getName() << " " << s.getAddress() << " " << s.getGpa() << endl;
    // s.in();
    cout << endl;
    Student st("LAM", "HCMM", 10);
    st.in();
    return 0;
}
