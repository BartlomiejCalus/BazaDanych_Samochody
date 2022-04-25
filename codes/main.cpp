#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

#include "mainClass.h"
#include "fullElectricClass.h"
#include "hybridClass.h"
#include "funkcje.hpp"


int main()
{
    setlocale(LC_ALL,"");
    vector<Auto*> cars;

    fstream plik_out;
    fstream plik_in;

    try{

        //do szybkiego uzupelnienia danych
        /*cars.push_back( new BEV("BEV","Tesla", "s", "sport", "usa", 2, 2, 1000, 3.6, 200000, 300, "litowo-jonowa", 300, 30, "OC"));
        cars.push_back( new HEV("HEV","Toyota","Yaris Hybrid", "SUV", "japonia", 4, 4, 360, 6.2, 56000, 4.3, "LPG+benzyna", 69));
        zapis(cars,plik_out);
        */

        int odp;
        cout << "WCZYTUJE DANE";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        import(cars,plik_in);
        system( "cls" );
        while (1){
            odp=0;
            cout <<"DOSTEPNE CZYNNOSCI"<<endl;
            cout <<"1. WYPISZ WSZYSTKIE DANE"<<endl;
            cout <<"2. USUN POZYCJE"<<endl;
            cout <<"3. DODAJ POZYCJE"<<endl;
            cout <<"4. FORMATUJ BAZE DANYCH"<<endl;
            cout <<"5. WYJSCIE"<<endl;
            cout <<"WYBOR OPERACJI: ";
            cin >> odp;
            system( "cls" );

            if(odp==5)
                exit(0);

            string w;

            switch(odp){

                case 1:
                    wyp(cars);
                    system("pause");
                    system( "cls" );
                    break;

                case 2:
                    int x;

                    if (cars.empty()){
                        cout << "!!! USUWANIE JEST NIEDOSTEPNE - BAZA DANYCH JEST PUSTA !!!"<<endl;
                        system("pause");
                        system( "cls" );
                        break;
                    }

                    cout << "KTORY ELEMNET CHCESZ USUNAC?"<<endl;
                    cout <<"Wybor: ";
                    cin >> x;

                    if(x>cars.size()||x<1){
                        cout << "!!! USUWANIE JEST NIEDOSTEPNE - PROBA USUWANIA NIEISTNIEJACEGO ELEMENTU !!!"<<endl;
                        system("pause");
                        system( "cls" );
                        break;
                    }

                    cout << "ELEMENT ZOSTANIE TRWALE USUNIETY. CZY NA PEWNO CHCESZ GO USUNAC? (TAK/NIE): ";

                    cin >> w;

                    if(w=="tak"||w=="Tak"||w=="TAK"){
                        cout << "TRWA USUWANIE ELEMENTU "<<x;
                        Sleep(500);
                        cout << ".";
                        Sleep(500);
                        cout << ".";
                        Sleep(500);
                        cout << ".";
                        Sleep(500);
                        cout << "." <<endl;
                        usun(cars,x-1);
                        zapis(cars,plik_out);
                        system( "cls" );
                        break;
                    } else {
                        system( "cls" );
                        break;}

                case 3:
                   dodaj(cars);
                   zapis(cars,plik_out);
                   system( "cls" );
                   break;

                case 4:
                    string e;
                    cout << "CZY NA PEWNO CHCESZ SFORMATOWAC CALA BAZE DANYCH? (TAK/NIE): ";
                    cin >> e;

                    if(e=="tak"||e=="Tak"||e=="TAK"){
                        cout << "TRWA FORMATOWANIE";
                        Sleep(500);
                        cout << ".";
                        Sleep(500);
                        cout << ".";
                        Sleep(500);
                        cout << ".";
                        Sleep(500);
                        cout << "."<<endl;
                        cars.clear();
                        zapis(cars,plik_out);
                        system( "cls" );
                        break;
                    } else {
                        system( "cls" );
                        break;}
            }

        }

        //zapis(cars,plik_out);
        //import(cars,plik_in);
        //usun(cars,0);
        //dodaj(cars);
        //wyp(cars);


    }catch(const char* msg){
        cout << msg;

    }


    return 0;
}
