#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "studentas.h"
using namespace std;

double vidurkis(vector<int>& nd, vector<int>& egz) {  //& nedaro kopijos
    double suma = 0; 
    for(int i=0; i < (int)nd.size(); i++){
        suma += nd[i];
    }
    for (int i = 0; i < (int)egz.size(); i++) {
        suma += egz[i];
    }
    return suma / (nd.size()+egz.size());
}
double mediana(vector<int>& nd, vector<int>& egz) {
    vector<int> visos_reiksmes;

    for (int i = 0; i < (int)nd.size(); i++) {
        visos_reiksmes.push_back(nd[i]);
    }
    for (int i = 0; i < (int)egz.size(); i++) {
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
template <typename Konteineris>
void nuskaityti_is_failo(Konteineris& studentai, string failo_pavadinimas){
    studentai.clear();
    ifstream failas(failo_pavadinimas);
    if(!failas){
        cout<<"Nepavyko atidaryti failo"<<endl;
        return;
    }

    string eilute;
    getline(failas, eilute);

    while(getline(failas, eilute)){
        stringstream ss(eilute);
        vector<string> zodziai;
        string t;
        while(ss >> t){
            zodziai.push_back(t);
        }

        if(zodziai.size() < 3) continue;   

        Studentas A;
        A.vardas = zodziai[0];
        A.pavarde = zodziai[1];

        for(int i = 2; i < (int)zodziai.size() - 1; i++){
            A.nd_rezultatai.push_back(stoi(zodziai[i]));
        }
        A.egz_rezultatai.push_back(stoi(zodziai[zodziai.size() - 1]));

        studentai.push_back(A);
    }

    failas.close();
}
template <typename Konteineris>
void rasyti_i_faila_pagal_pavarde(Konteineris& studentai, string isvesties_failas){
    ofstream failas(isvesties_failas);
    if(!failas){
        cout<<"Nepavyko sukurti failo"<<endl;
        return;
    }
    failas<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutinis(vid.)"<<"/"<<"Galutinis(med.)"<<endl;
    failas<<string(70, '-')<<endl;
    failas<<fixed<<setprecision(2);

        for(auto& s : studentai){
        double rezultatas1 = vidurkis(s.nd_rezultatai, s.egz_rezultatai);
        double rezultatas2 = mediana(s.nd_rezultatai, s.egz_rezultatai);
        failas <<left<<setw(15)<<s.pavarde
               <<setw(15)<<s.vardas
               <<setw(15)<<rezultatas1
               <<rezultatas2
               <<endl;
    }

    failas.close();
    cout<<"Rezultatai issaugoti i faila: "<<isvesties_failas<<endl;
}

void generuoti_faila(int studentu_kiekis, string failo_pavadinimas){
    ofstream failas(failo_pavadinimas);
    if(!failas){
        cout<<"Nepavyko sukurti failo"<<endl;
        return;
    }
    failas<<left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde";
    for(int j = 1; j <= 15; j++){
        failas<<setw(6)<<"ND" + to_string(j);
    }
    failas<<"Egz."<<"\n";
    
    failas<<string(70, '-')<<endl;
    for(int i = 1; i<=studentu_kiekis; i++){
        failas <<left<<setw(15)<<"Vardas" + to_string(i)<<setw(15)<<"Pavarde" + to_string(i);
        for(int j = 0; j < 15; j++){
            failas<<setw(6)<<rand() % 10 + 1;
        }
        failas<<rand() % 10 + 1<<endl;
    }
    failas.close();
}
template <typename Konteineris>
void padalinti(Konteineris& studentai, Konteineris& vargsiukai, Konteineris& kietiakiai){
    vargsiukai.clear();
    kietiakiai.clear();
        for(auto& s : studentai){
        double galutinis = vidurkis(s.nd_rezultatai, s.egz_rezultatai);
        if(galutinis < 5.0){
            vargsiukai.push_back(s);
        } else {
            kietiakiai.push_back(s);
        }
    }
}
template <typename Konteineris>
void rasyti_i_faila_pagal_pazymi(Konteineris& studentai, string isvesties_failas){
    ofstream failas(isvesties_failas);
    if(!failas){
        cout<<"Nepavyko sukurti failo"<<endl;
        return;
    }
    failas<<left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<"Galutinis"<<"\n";
    failas<<string(40, '-')<<"\n";
    failas<<fixed<<setprecision(2);

        for(auto& s : studentai){
        double galutinis = vidurkis(s.nd_rezultatai, s.egz_rezultatai);
        failas<<left<<setw(20)<<s.vardas<<setw(20)<<s.pavarde<<galutinis<<"\n";
    }
    failas.close();
}


bool pagal_pazymi(Studentas& a, Studentas& b){
    return vidurkis(a.nd_rezultatai, a.egz_rezultatai) < vidurkis(b.nd_rezultatai, b.egz_rezultatai);
}
bool pagal_varda(Studentas& a, Studentas& b){
    return a.vardas < b.vardas;
}
bool pagal_pavarde(Studentas& a, Studentas& b){
    return a.pavarde < b.pavarde;
}

// budas: 1 - pagal pazymi, 2 - pagal varda, 3 - pagal pavarde
void rusiuoti(vector<Studentas>& studentai, int budas){
    if(budas == 1)      sort(studentai.begin(), studentai.end(), pagal_pazymi);
    else if(budas == 2) sort(studentai.begin(), studentai.end(), pagal_varda);
    else                sort(studentai.begin(), studentai.end(), pagal_pavarde);
}

void rusiuoti(list<Studentas>& studentai, int budas){
    if(budas == 1)      studentai.sort(pagal_pazymi);
    else if(budas == 2) studentai.sort(pagal_varda);
    else                studentai.sort(pagal_pavarde);
}
