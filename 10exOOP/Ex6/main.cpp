/**
 * @author Lam Nguyen
 * @email nguyenthualam1@gmail.com
 * @create date 2023-05-21
 * @desc [description]
 */

#include <iostream>
using namespace std;

class Praction {
private:
    int numerator;
    int denominator;
public:
    Praction(int num = 0, int deno = 1);
    void setNumerator(int num);
    void setDenominator(int deno);
    int getNumerator();
    int getDenominator();
};

class Calculate : public Praction {
public:
    Praction add(Praction p1, Praction p2);
    Praction sub(Praction p1, Praction p2);
    Praction multiplied(Praction p1, Praction p2);
    Praction div(Praction p1, Praction p2);
};

Praction :: Praction(int num, int deno){
    this->numerator = num;
    this->denominator = deno;
}
void Praction :: setNumerator(int num){
    this->numerator = num;
}
void Praction :: setDenominator(int deno){
    this->denominator = deno;
}
int Praction :: getNumerator(){
    return this->numerator;
}
int Praction :: getDenominator(){
    return this->denominator;
}

Praction Calculate :: add(Praction p1, Praction p2) {
    Praction result;
    result.setNumerator(p1.getNumerator() * p2.getDenominator() + p2.getNumerator() * p1.getDenominator());
    result.setDenominator(p1.getDenominator() * p2.getDenominator());
    return result;
}

Praction Calculate :: sub(Praction p1, Praction p2) {
    Praction result;
    result.setNumerator(p1.getNumerator() * p2.getDenominator() - p2.getNumerator() * p1.getDenominator());
    result.setDenominator(p1.getDenominator() * p2.getDenominator());
    return result;
}

Praction Calculate :: multiplied(Praction p1, Praction p2) {
    Praction result;
    result.setNumerator(p1.getNumerator() * p2.getNumerator());
    result.setDenominator(p1.getDenominator() * p2.getDenominator());
    return result;
}

Praction Calculate :: div(Praction p1, Praction p2) {
    Praction result;
    result.setNumerator(p1.getNumerator() * p2.getDenominator());
    result.setDenominator(p1.getDenominator() * p2.getNumerator());
    return result;
}

int main() {
    Calculate cal;

    Praction a(1, 2);
    Praction b(3, 4);
    Praction c;

    c = cal.add(a, b); // cộng
    cout    << a.getNumerator() << "/" << a.getDenominator()
            << " + " << b.getNumerator() << "/" << b.getDenominator() << " = "
            << c.getNumerator() << "/" << c.getDenominator() << endl;

    c = cal.sub(a, b); // trừ
    cout    << a.getNumerator() << "/" << a.getDenominator()
            << " - " << b.getNumerator() << "/" << b.getDenominator() << " = "
            << c.getNumerator() << "/" << c.getDenominator() << endl;

    c = cal.multiplied(a, b); // nhân
    cout    << a.getNumerator() << "/" << a.getDenominator()
            << " x " << b.getNumerator() << "/" << b.getDenominator() << " = "
            << c.getNumerator() << "/" << c.getDenominator() << endl;

    c = cal.div(a, b); // chia
    cout    << a.getNumerator() << "/" << a.getDenominator()
            << " / " << b.getNumerator() << "/" << b.getDenominator() << " = "
            << c.getNumerator() << "/" << c.getDenominator() << endl;

    return 0;
}
