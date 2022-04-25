#ifndef FUNKCJE_HPP_INCLUDED
#define FUNKCJE_HPP_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>

#include "funkcje.cpp"

void zapis (vector<Auto*>cars, fstream& plik);

void usun (vector<Auto*>&cars, int x);

void import (vector<Auto*>&cars, string name);

void dodaj(vector<Auto*>&cars);

void wyp (vector<Auto*>&cars);
void import (vector<Auto*>&cars, string name);

#endif // FUNKCJE_HPP_INCLUDED
