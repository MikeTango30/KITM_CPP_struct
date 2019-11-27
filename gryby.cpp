#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream in("grybai.txt");
ofstream out("rez_grybai.txt");


struct grybai {
    string diena;
    int tikriGrybai[3];
    int viso;
};

void skaitom(grybai Struktura[], int kiekis);
void rasom(grybai Struktura[], int kiekis, string txt);
void suma(grybai Struktura[], int kiekis);
void rasomSuma(grybai Struktura[], int kiekis, string txt);

int main ()
{
    int kiek;
    in >> kiek;
    grybai Savaite[kiek];

    skaitom(Savaite, kiek);
    rasom(Savaite, kiek, "Musu grybai:");
    suma(Savaite, kiek);
    rasomSuma(Savaite, kiek, "Is viso grybu:");

    in.close();
    out.close();

    return 0;
}

void skaitom(grybai Struktura[], int kiekis)
{
    for(int i = 0; i < kiekis; i++) {
        in >> Struktura[i].diena;
        for (int j = 0; j < 3; j++) {
            in >> Struktura[i].tikriGrybai[j];
        }
    }

}

void rasom(grybai Struktura[], int kiekis, string txt)
{
    out << txt << "\n";
    for(int i = 0; i < kiekis; i++) {
        out << setw(20) << left << Struktura[i].diena;
        for (int j = 0; j < 3; j++) {
            out << setw(8) << right << Struktura[i].tikriGrybai[j];
        }
        out << "\n";
    }
}

void suma(grybai Struktura[], int kiekis)
{
    for(int i = 0; i < kiekis; i++) {
            Struktura[i].viso = 0;
        for (int j = 0; j < 3; j++) {
             Struktura[i].viso += Struktura[i].tikriGrybai[j];
        }
    }
}

void rasomSuma(grybai Struktura[], int kiekis, string txt)
{
     out << txt << "\n";
     for(int i = 0; i < kiekis; i++) {
        out << setw(10) << left << Struktura[i].diena << setw(4) << right << Struktura[i].viso << "\n";
     }
}
