#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
using std::cin;
using std::cout;
using std::left;
using std::right;
using std::setw;

struct Studentas{
    string vardas;
    string pavarde;
    vector<int> nd_rezultatai;
    int egz_rez;
};
double vidurkis(vector<int> nd, int egz) {
    double suma = egz; 
    for(int i=0; i < nd.size(); i++){
        suma += nd[i];
    }
    return suma / (nd.size()+1);
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
        cout<<"iveskite studento n.d. pazymius, kai baigsite iveskite -1"<<endl;
        while(true){
            int reiksme;
            cin>>reiksme;
            if (reiksme == -1){
                break;
            }
        }
        cout<<"iveskite studento egzamino pazymi"<<endl;
        cin>>A.egz_rez;
        studentai.push_back(A);
    }

    cout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutinis(vid.)"<<"/"<<"Galutinis(med.)"<<endl;    
    cout<<string(70, '-')<<endl;
    for(int i = 0; i < studentai.size(); i++){
        double rezultatas1 = vidurkis(studentai[i].nd_rezultatai, studentai[i].egz_rez);
        double rezultatas2 = vidurkis(studentai[i].nd_rezultatai, studentai[i].egz_rez);
        cout <<left<<setw(15)<<studentai[i].pavarde
             <<setw(15)<<studentai[i].vardas
             <<setw(15)<<rezultatas1
             <<rezultatas2
             <<endl;
    }
         
}