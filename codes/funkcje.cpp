#include <string>


void zapis (vector<Auto*>cars, fstream& plik){

    plik.open("baza.bin", ios::out | ios::binary);

    for (unsigned i=0; i<cars.size();++i)
        cars[i]->zapisz(plik);

    plik.close();
}

void usun (vector<Auto*>&cars, int x){

    cars.erase (cars.begin()+ x);
}

void import (vector<Auto*>&cars, fstream& plik){

    plik.open("baza.bin", ios::in | ios::binary);


    string a;
    while (!plik.eof()){
    getline (plik, a, '\0');
        if (a=="BEV"){
            cars.push_back(new BEV(plik));
        }else if(a=="HEV"){
            cars.push_back(new HEV(plik));
        }
   }
    plik.close();
}

void dodaj(vector<Auto*>&cars){

    string typ;
    string marka;
    string model;
    string rodzaj;
    string mProd;
    int drzwi;
    int miejsca;
    int KM;
    double czas;
    int cena;

    cout << "typ (BEV/HEV): ";
    cin >> typ;


    if(typ=="BEV"){
        int zasieg;
        string bateria;
        int pojm;
        int lad;
        string spos;

        cout << "marka: ";
        cin >> marka;
        cout << "model: ";
        cin >> model;
        cout << "rodzaj: ";
        cin >> rodzaj;
        cout << "miejsce produkcji: ";
        cin >> mProd;
        cout << "ilosc drzwi: ";
        cin >> drzwi;
        cout << "ilosc miejsc: ";
        cin >> miejsca;
        cout << "ilosc koni mechanicznych: ";
        cin >> KM;
        cout << "czas po którym osiaga predkosc 100 km/h: ";
        cin >> czas;
        cout << "cena: ";
        cin >> cena;
        cout << "zasieg: ";
        cin >> zasieg;
        cout << "pojemnosc bateri: ";
        cin >> pojm;
        cout << "rodzaj bateri: ";
        cin >> bateria;
        cout << "czas ladowania: ";
        cin >> lad;
        cout << "sposob ladowania: ";
        cin >> spos;
        cout << endl;

        cars.push_back(new BEV(typ, marka, model, rodzaj, mProd, drzwi, miejsca, KM, czas, cena, zasieg, bateria, pojm, lad, spos));

    }else if(typ=="HEV"){
        double spal;
        string rodz;
        int proct;

          cout << "marka: ";
        cin >> marka;
        cout << "model: ";
        cin >> model;
        cout << "rodzaj: ";
        cin >> rodzaj;
        cout << "miejsce produkcji: ";
        cin >> mProd;
        cout << "ilosc drzwi: ";
        cin >> drzwi;
        cout << "ilosc miejsc: ";
        cin >> miejsca;
        cout << "ilosc koni mechanicznych: ";
        cin >> KM;
        cout << "czas po którym osiaga predkosc 100 km/h: ";
        cin >> czas;
        cout << "cena: ";
        cin >> cena;
        cout << "spalanie: ";
        cin >> spal;
        cout << "rodzaje paliwa: ";
        cin >> rodz;
        cout << "srednie wykorzystywanie pradu podczas przejazu: ";
        cin >> proct;
        cout << endl;

        cars.push_back(new HEV(typ, marka, model, rodzaj, mProd, drzwi, miejsca, KM, czas, cena, spal, rodz, proct));

    }else cout << "zly typ, spróbuj jeszcze raz";

}

void wyp (vector<Auto*>&cars){
    cout <<endl<<"**********************"<<endl;
    for (unsigned i=0; i<cars.size();++i){
        cout <<i+1<<"."<<endl;
        cars[i]->wypisz();
        cout <<endl<<"**********************"<<endl;
    }
}


