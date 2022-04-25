#ifndef HYBRIDCLASS_H_INCLUDED
#define HYBRIDCLASS_H_INCLUDED

class HEV:public Auto{

private:
    double spalnie;
    string paliwo;
    int procent_ele;

public:
     double getSpalanie(){
        return spalnie;
    }
    int getProcent_ele(){
        return procent_ele;
    }
    string getPaliwo(){
        return paliwo;
    }

    HEV (string typ, string marka, string model, string rodzaj, string miejsce_pro, int drzwi, int miejsca, int KM, double do_100, int cena, double spalanie, string paliwo, int procent_ele){

        setTyp(typ);
        setMarka(marka);
        setModel(model);
        setMiejscePro(miejsce_pro);
        setRodzaj(rodzaj);

        this->paliwo = paliwo;

        setDrzwi(drzwi);
        setMiejsca(miejsca);
        setKM(KM);
        setDo_100(do_100);
        setCena(cena);

        if (spalanie>0)
            this->spalnie = spalanie;
        else throw "ujemne spalanie";

        if (procent_ele>0 && procent_ele<100)
            this->procent_ele = procent_ele;
        else throw "zly przedzial wykorzystania elektry";
    }

    HEV(){
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
        plik.write((const char*)&t4, sizeof(double));
        plik.write((const char*)&t5, sizeof getCena());
        plik.write((const char*)&spalnie, sizeof(double));
        plik.write(paliwo.c_str(), paliwo.size()+1);
        plik.write((const char*)&procent_ele, sizeof getCena());

     }

      HEV (fstream& plik){
        int tInt;
        double tDob;
        string tStr;
        setTyp("HEV");
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

        plik.read ((char*)&spalnie, sizeof(double));
        getline (plik, paliwo, '\0');
        plik.read ((char*)&procent_ele, sizeof(int));
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
        cout << "spalanie: " << spalnie << " l/100km" << endl;
        cout << "rodzaje paliwa: " << paliwo << endl;
        cout << "srednie wykorzystywanie pradu podczas przejazu: " << procent_ele << "%" << endl;
    }

};


#endif // HYBRIDCLASS_H_INCLUDED
