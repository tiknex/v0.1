#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
using std::cin;
using std::cout;
using std::left;
using std::right;
using std::setw;

struct Studentas{
    string vardas;
    string pavarde;
    int nd_rez;
    int egz_rez;
};
double vidurkis(int a, int b) {
    double v = (a + b) / 2.0;  
    return v;
}
int main() {
    Studentas A;
    cout<<"iveskite studento varda"<<endl;
    cin>>A.vardas;
    cout<<"iveskite studento pavarde"<<endl;
    cin>>A.pavarde;
    cout<<"iveskite studento n.d. pazymi"<<endl;
    cin>>A.nd_rez;
    cout<<"iveskite studento egzamino pazymi"<<endl;
    cin>>A.egz_rez;

    double rezultatas = vidurkis(A.nd_rez, A.egz_rez);
    //cout << fixed << setprecision(2);
    cout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutins (vid.)"<<endl;    
    cout<<string(45, '-')<<endl;
    cout<<left<<setw(15)<<A.pavarde<<setw(15)<<A.vardas<<setw(15)<<rezultatas; 
}