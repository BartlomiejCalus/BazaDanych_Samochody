#ifndef MAINCLASS_H_INCLUDED
#define MAINCLASS_H_INCLUDED
#include <string>

using namespace std;

class Auto{

private:
    string typ;
    string marka;
    string model;
    string miejsce_pro;
    string rodzaj;
    int drzwi;
    int miejsca;
    int KM;
    double do_100;
    int cena;

public:

    string getTyp(){
        return typ;
    }
    string getMarka(){
        return marka;
    }
    string getModel(){
        return model;
    }
    string getMiejscePro(){
        return miejsce_pro;
    }
    string getRodzaj(){
        return rodzaj;
    }
    int getDrzwi(){
        return drzwi;
    }
    int getMiejsca(){
        return miejsca;
    }
    int getKM(){
        return KM;
    }
    double getDo_100(){
        return do_100;
    }
    int getCena(){
        return cena;
    }

    void setTyp (string typ){
        if (typ=="BEV"||typ=="HEV")
            this->typ = typ;
        else throw "zly typ samochodu";
    }
    void setMarka (string marka){
        this->marka = marka;
    }
    void setModel (string model){
        this->model = model;
    }
    void setMiejscePro (string miejsce_pro){
        this->miejsce_pro = miejsce_pro;
    }
    void setRodzaj (string rodzaj){
        this->rodzaj = rodzaj;
    }
    void setDrzwi (int drzwi){
        if (drzwi>1 && drzwi<5)
            this->drzwi = drzwi;
        else throw "zla ilosc drzwi";
    }

    void setMiejsca (int miejsca){
        if (miejsca>1 && miejsca<8)
            this->miejsca = miejsca;
        else throw "zla ilosc miejsc";
    }

    void setKM (int KM){
        if (KM>0)
            this->KM = KM;
        else throw "zla ilosc KM";
    }

    void setDo_100 (double do_100){
        if (do_100>0)
            this->do_100 = do_100;
        else throw "bledne przyspieszenie do 100";
    }

     void setCena (int cena){
         if (cena>0)
            this->cena = cena;
        else throw "ujemna cena";
    }



     virtual void zapisz (fstream& plik){
        throw "Problem z zapisem";
    }


    virtual void wypisz (){
        throw "Problem z wypisaniem";
    }

};

#endif // MAINCLASS_H_INCLUDED
