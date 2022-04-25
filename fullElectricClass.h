#ifndef FULLELECTRICCLASS_H_INCLUDED
#define FULLELECTRICCLASS_H_INCLUDED
#include <fstream>

class BEV:public Auto{

private:
    int zasieg;
    int bateria_poj;
    string bateria_rodz;
    double czas_lad;
    string spos_lad;

public:

    int getZasieg(){
        return zasieg;
    }
    int getBateria_poj(){
        return bateria_poj;
    }
    string getBateria_rodz(){
        return bateria_rodz;
    }
    double getCzas_lad(){
        return czas_lad;
    }
    string getSpos_lad(){
        return spos_lad;
    }

    BEV (string typ, string marka, string model, string rodzaj, string miejsce_pro, int drzwi, int miejsca, int KM, double do_100, int cena, int zasieg, string bateria_rodz,int bateria_poj, double czas_lad, string spos_lad){

        setTyp(typ);
        setMarka(marka);
        setModel(model);
        setMiejscePro(miejsce_pro);
        setRodzaj(rodzaj);

        this->bateria_rodz = bateria_rodz;
        this->spos_lad = spos_lad;

        setDrzwi(drzwi);
        setMiejsca(miejsca);
        setKM(KM);
        setDo_100(do_100);
        setCena(cena);

        if (zasieg>0)
            this->zasieg = zasieg;
        else throw "ujemny zasieg";

        if (bateria_poj>0)
            this->bateria_poj = bateria_poj;
        else throw "ujemna pojemnosc bateri";

        if (czas_lad>0)
            this->czas_lad = czas_lad;
        else throw "ujemny czas ladowania";

    }

    BEV (){
    }

    void zapisz (fstream& plik)override{

        int t1 = getDrzwi();
        int t2 = getMiejsca();
        int t3 = getKM();
        double t4 = getDo_100();
        int t5 = getCena();
        plik.write(getTyp().c_str(), getTyp().size()+1);
        plik.write(getMarka().c_str(), getMarka().size()+1);
        plik.write(getModel().c_str(), getModel().size()+1);
        plik.write(getRodzaj().c_str(), getRodzaj().size()+1);
        plik.write(getMiejscePro().c_str(), getMiejscePro().size()+1);
        plik.write((const char*)&t1, sizeof getDrzwi());
        plik.write((const char*)&t2, sizeof getMiejsca());
        plik.write((const char*)&t3, sizeof getKM());
        plik.write((const char*)&t4, sizeof getDo_100());
        plik.write((const char*)&t5, sizeof getCena());
        plik.write((const char*)&zasieg, sizeof zasieg);
        plik.write((const char*)&bateria_poj, sizeof bateria_poj);
        plik.write(bateria_rodz.c_str(), bateria_rodz.size()+1);
        plik.write((const char*)&czas_lad, sizeof czas_lad);
        plik.write(spos_lad.c_str(), spos_lad.size()+1);
    }

    BEV(fstream& plik){
        int tInt;
        double tDob;
        string tStr;
        setTyp("BEV");
        getline (plik, tStr, '\0');
        setMarka(tStr);
        getline (plik, tStr, '\0');
        setModel(tStr);
        getline (plik, tStr, '\0');
        setRodzaj(tStr);
        getline (plik, tStr, '\0');
        setMiejscePro(tStr);
        plik.read ((char*)&tInt, sizeof(int));
        setDrzwi(tInt);
        plik.read ((char*)&tInt, sizeof(int));
        setMiejsca(tInt);
        plik.read ((char*)&tInt, sizeof(int));
        setKM(tInt);
        plik.read ((char*)&tDob, sizeof(double));
        setDo_100(tDob);
        plik.read ((char*)&tInt, sizeof(int));
        setCena(tInt);
        plik.read ((char*)&zasieg, sizeof(int));
        plik.read ((char*)&bateria_poj, sizeof(int));
        getline (plik, bateria_rodz, '\0');
        plik.read ((char*)&czas_lad, sizeof(double));
        getline (plik, spos_lad, '\0');


    }

    void wypisz ()override{

        cout << "typ: " << getTyp() << endl;
        cout << "marka: " << getMarka() << endl;
        cout << "model: " << getModel() << endl;
        cout << "rodzaj: " << getRodzaj() << endl;
        cout << "miejsce produkcji: " << getMiejscePro() << endl;
        cout << "ilosc drzwi: " << getDrzwi() << endl;
        cout << "ilosc miejsc: " << getMiejsca() << endl;
        cout << "ilosc koni mechanicznych: " << getKM() << endl;
        cout << "czas po którym osiaga predkosc 100 km/h: " << getDo_100() << " s" << endl;
        cout << "cena: " << getCena() << " zl" << endl;
        cout << "zasieg: " << zasieg << endl;
        cout << "pojemnosc bateri: " << bateria_poj<<endl;
        cout << "rodzaj bateri: " << bateria_rodz<<endl;
        cout << "czas ladowania: " << czas_lad<<endl;
        cout << "sposob ladowania: " << spos_lad<<endl;

    }

};

#endif // FULLELECTRICCLASS_H_INCLUDED
