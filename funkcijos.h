#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
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
void nuskaityti_is_failo(vector<Studentas>& studentai, string failo_pavadinimas){
    studentai.clear();
    ifstream failas(failo_pavadinimas);
    if(!failas){
        cout<<"Nepavyko atidaryti failo"<<endl;
        return;
    }

    studentai.reserve(studentai.size() + 1000000);

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
void rasyti_i_faila_pagal_pavarde(vector<Studentas>& studentai, string isvesties_failas){
    ofstream failas(isvesties_failas);
    if(!failas){
        cout<<"Nepavyko sukurti failo"<<endl;
        return;
    }
    failas<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutinis(vid.)"<<"/"<<"Galutinis(med.)"<<endl;
    failas<<string(70, '-')<<endl;
    failas<<fixed<<setprecision(2);

    for(int i = 0; i < (int)studentai.size(); i++){
        double rezultatas1 = vidurkis(studentai[i].nd_rezultatai, studentai[i].egz_rezultatai);
        double rezultatas2 = mediana(studentai[i].nd_rezultatai, studentai[i].egz_rezultatai);
        failas <<left<<setw(15)<<studentai[i].pavarde
               <<setw(15)<<studentai[i].vardas
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
    failas<<left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<"Galutinis"<<"\n";
    failas<<string(70, '-')<<endl;
    for(int i = 1; i<=studentu_kiekis; i++){
        failas <<left<<setw(15)<<"Vardas" + to_string(i)<<setw(15)<<"Pavarde" + to_string(i)<<rand() % 10 + 1<<endl;
    }
    failas.close();
}

void padalinti(vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakiai){
    vargsiukai.clear();
    kietiakiai.clear();
    for(int i = 0; i < (int)studentai.size(); i++){
        double galutinis = vidurkis(studentai[i].nd_rezultatai, studentai[i].egz_rezultatai);
        if(galutinis < 5.0){
            vargsiukai.push_back(studentai[i]);
        } else {
            kietiakiai.push_back(studentai[i]);
        }
    }
}

void rasyti_i_faila_pagal_pazymi(vector<Studentas>& studentai, string isvesties_failas){
    ofstream failas(isvesties_failas);
    if(!failas){
        cout<<"Nepavyko sukurti failo"<<endl;
        return;
    }
    failas<<left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<"Galutinis"<<"\n";
    failas<<string(40, '-')<<"\n";
    failas<<fixed<<setprecision(2);

    for(int i = 0; i < (int)studentai.size(); i++){
        double galutinis = vidurkis(studentai[i].nd_rezultatai, studentai[i].egz_rezultatai);
        failas<<left<<setw(15)<<studentai[i].vardas
              <<setw(15)<<studentai[i].pavarde
              <<galutinis<<"\n";
    }
    failas.close();
}
