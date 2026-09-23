#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <ctime>
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
    vector<int> egz_rezultatai;
};
double vidurkis(vector<int> nd, vector<int> egz) {
    double suma = 0; 
    for(int i=0; i < nd.size(); i++){
        suma += nd[i];
    }
    for (int i = 0; i < egz.size(); i++) {
        suma += egz[i];
    }
    return suma / (nd.size()+egz.size());
}
double mediana(vector<int> nd, vector<int> egz) {
    vector<int> visos_reiksmes;

    for (int i = 0; i < nd.size(); i++) {
        visos_reiksmes.push_back(nd[i]);
    }
    for (int i = 0; i < egz.size(); i++) {
        visos_reiksmes.push_back(egz[i]);
    }

    sort(visos_reiksmes.begin(), visos_reiksmes.end());

    int n = visos_reiksmes.size();

    if (n % 2 == 1) {
        return visos_reiksmes[n / 2];
    } else {
        return (visos_reiksmes[n/2 - 1] + visos_reiksmes[n/2]) / 2.0;
    }
}

int main() {
    srand(time(0));
    vector<Studentas> studentai;
    int pasirinkimas;

    while(true){
    cout<<endl;
    cout<<"1 - Pridet studenta"<<endl;
    cout<<"2 - Rodyti studentu lentele"<<endl;
    cout<<"3 - Baigti programa"<<endl;
    cout<<"Pasirinkite veiksma: ";
    cin>>pasirinkimas;

    if(pasirinkimas == 1){
        Studentas A;
        string atsakymas;
        cout<<"iveskite studento varda"<<endl;
        cin>>A.vardas;
        cout<<"iveskite studento pavarde"<<endl;
        cin>>A.pavarde;
        cout<<"ar norite sugeneruoti nd ir egazmino pazymius atsitiktinai taip/ne?"<<endl;
        cin>>atsakymas;
    if (atsakymas == "taip") {
        int kiekis_nd;
        cout << "kiek nd pazymiu norite sugeneruoti?" << endl;
        cin >> kiekis_nd;

    for (int j = 0; j < kiekis_nd; j++) {
        int atsitiktinis_skaicius_nd = rand() % 10 + 1;
        A.nd_rezultatai.push_back(atsitiktinis_skaicius_nd);
    }
        int atsitiktinis_skaicius_egz = rand() % 10 + 1;
        A.egz_rezultatai.push_back(atsitiktinis_skaicius_egz);   
    } else {
    cout << "iveskite studento nd pazymius, kai baigsite iveskite -1" << endl;
    while (true) {
        int reiksme;
        cin >> reiksme;
        if (reiksme == -1) {
            break;
        }
        A.nd_rezultatai.push_back(reiksme);
    }
    cout<<"iveskite studento egzamino pazymi"<<endl;
    int egz_reiksme;
    cin>>egz_reiksme;
    A.egz_rezultatai.push_back(egz_reiksme);
    }
    studentai.push_back(A);
    cout<<"studentas pridetas"<<endl;

    } else if(pasirinkimas == 2){
    cout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutinis(vid.)"<<"/"<<"Galutinis(med.)"<<endl;    
    cout<<string(70, '-')<<endl;
    cout<<fixed<<setprecision(2);
    for(int i = 0; i < studentai.size(); i++){
        double rezultatas1 = vidurkis(studentai[i].nd_rezultatai, studentai[i].egz_rezultatai);
        double rezultatas2 = mediana(studentai[i].nd_rezultatai, studentai[i].egz_rezultatai);
        cout <<left<<setw(15)<<studentai[i].pavarde
             <<setw(15)<<studentai[i].vardas
             <<setw(15)<<rezultatas1
             <<rezultatas2
             <<endl;
    }

    } else if(pasirinkimas == 3){
        break;
    } else {
        cout<<"neteisingas pasirinkimas, bandykite dar karta."<<endl;
    }
    }

}