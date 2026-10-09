#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdlib>
#include <ctime>
#include "studentas.h"
#include "funkcijos.h"
using namespace std;

int main() {
    srand(time(0));
    vector<Studentas> studentai;
    int pasirinkimas;

    while(true){
    cout<<endl;
    cout<<"1 - Pridet studenta"<<endl;
    cout<<"2 - Rodyti studentu lentele"<<endl;
    cout<<"3 - Baigti programa"<<endl;
    cout<<"4 - Sugeneruoti faila"<<endl;
    cout<<"5 - Nuskaityti duomenis is failo"<<endl;
    cout<<"6 - Padalinti faila i vargsiukus ir kietiakius"<<endl;
    cout<<"Pasirinkite veiksma: ";
    cin>>pasirinkimas;

    if(cin.fail()){                         //apsaugo nuo netinkamos ivesties
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Netinkama ivestis, iveskite skaiciu."<<endl;
        continue;
    }

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
        sort(studentai.begin(), studentai.end(), [](Studentas a, Studentas b){
            return a.pavarde < b.pavarde;
        });
    if((int)studentai.size() > 100){
        cout<<"Per daug duomenu rodyti ekrane ("<<studentai.size()<<" studentu)."<<endl;
        cout<<"Rezultatai bus issaugoti i faila."<<endl;
        rasyti_i_faila_pagal_pavarde(studentai, "rezultatai.txt");
    } else {
    cout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutinis(vid.)"<<"/"<<"Galutinis(med.)"<<endl;    
    cout<<string(70, '-')<<endl;
    cout<<fixed<<setprecision(2);
    for(int i = 0; i < (int)studentai.size(); i++){
        double rezultatas1 = vidurkis(studentai[i].nd_rezultatai, studentai[i].egz_rezultatai);
        double rezultatas2 = mediana(studentai[i].nd_rezultatai, studentai[i].egz_rezultatai);
        cout <<left<<setw(15)<<studentai[i].pavarde
             <<setw(15)<<studentai[i].vardas
             <<setw(15)<<rezultatas1
             <<rezultatas2
             <<endl;
    }
    }

    } else if(pasirinkimas == 3){
        break;
    } else if(pasirinkimas == 4){
        int failu_kiekis;
        cout<<"kiek failu norite sukurti?"<<endl;  
        cin>>failu_kiekis;
        for(int i = 0; i<failu_kiekis; i++){
            int studentu_kiekis;
            string failo_pavadinimas;
            cout<<"kiek studentu norite, kad butu "<<i+1<<" faile"<<endl;
            cin>>studentu_kiekis;
            cout<<"iveskite failo pavadinima (su .txt)"<<endl;
            cin>>failo_pavadinimas;
            generuoti_faila(studentu_kiekis, failo_pavadinimas);
            cout<<"failas "<<failo_pavadinimas<<" sukurtas"<<endl;
        }

    }
    
    else if(pasirinkimas == 5){
        string failo_pavadinimas;
        cout<<"iveskite failo pavadinima (pvz. kursiokai.txt): "<<endl;
        cin>>failo_pavadinimas;
        nuskaityti_is_failo(studentai, failo_pavadinimas);
        cout<<"Duomenys nuskaityti is failo, ivesta studentu: "<<studentai.size()<<endl;
    } else if(pasirinkimas == 6){
    string failo_pavadinimas;
    cout<<"iveskite sugeneruoto failo pavadinima (pvz. studentai1000.txt): "<<endl;
    cin>>failo_pavadinimas;

    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakiai;

    nuskaityti_is_failo(studentai, failo_pavadinimas);
    if(studentai.empty()){
        cout<<"Faile nera studentu."<<endl;
        continue;
    }

    padalinti(studentai, vargsiukai, kietiakiai);
    rasyti_i_faila_pagal_pazymi(vargsiukai, "vargsiukai.txt");
    rasyti_i_faila_pagal_pazymi(kietiakiai, "kietiakiai.txt");

    cout<<"Studentu: "<<studentai.size()
        <<" (vargsiukai: "<<vargsiukai.size()
        <<", kietiakiai: "<<kietiakiai.size()<<")"<<endl;
    cout<<"Rezultatai: vargsiukai.txt ir kietiakiai.txt"<<endl;
    } else {
        cout<<"neteisingas pasirinkimas, bandykite dar karta."<<endl;
    }
    
    }

}