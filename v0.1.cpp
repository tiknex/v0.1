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
double mediana(int a, int b){

}
int main() {
    int stud_kiekis;
    cout<<"studentu skaicius"<<endl;
    cin>>stud_kiekis;
    Studentas A;
    vector<Studentas> studentai;
    for(int i = 0; i < stud_kiekis; i++){
        cout<<"iveskite studento varda"<<endl;
        cin>>A.vardas;
        cout<<"iveskite studento pavarde"<<endl;
        cin>>A.pavarde;
        cout<<"iveskite studento n.d. pazymi"<<endl;
        cin>>A.nd_rez;
        cout<<"iveskite studento egzamino pazymi"<<endl;
        cin>>A.egz_rez;
        studentai.push_back(A);
    }

    cout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutinis (vid.)"<<" / "<<"Galutinis (med.)"<<endl;    
    cout<<string(70, '-')<<endl;
    for(int i = 0; i < studentai.size(); i++){
        double rezultatas = vidurkis(studentai[i].nd_rez, studentai[i].egz_rez);
        //double mediana = 
        cout << left << setw(15) << studentai[i].pavarde
             << setw(15) << studentai[i].vardas
             << setw(15) << rezultatas 
             << endl;
    }
         
}