#include <iostream>
#include <fstream>

using namespace std;

struct studentai {
    char vardas[15];
    char pavarde[15];
    float vidurkis;
};

int main()
{
    studentai Sarasas[100];
    studentai TieGeresni[100];

    ifstream in("duom.txt");
    ofstream out("rez.txt");

    int kiek;
    in >> kiek;

    for (int i = 0; i < kiek; i++) {
        in >> Sarasas[i].vardas >> Sarasas[i].pavarde >> Sarasas[i].vidurkis;
    }

    /*
    for (int i = 0; i < kiek; i++) {
        out << Sarasas[i].vardas << "  "
            << Sarasas[i].pavarde << "  "
            << Sarasas[i].vidurkis << "  "
            << "\n";
    }
    */
//-------------------------------------------------------------------------
    float blogoVidurkis = Sarasas[0].vidurkis;
    int blogoNr = 0, blogiausiujuKiekis = 0, tieGeresniKiek = 0;
    int blogiausiuNr[kiek];
    out << "----------------------------------\n";
    out << "Blogiausieji:\n";
    out << "----------------------------------\n";
    for (int i = 1; i < kiek; i++) {
        if(blogoVidurkis >= Sarasas[i].vidurkis) {
            blogoVidurkis = Sarasas[i].vidurkis;
            blogoNr = i;
        }
    }
    for (int i = 0; i < kiek; i++) {
        if(blogoVidurkis == Sarasas[i].vidurkis) {
            blogoVidurkis = Sarasas[i].vidurkis;
            blogiausiuNr[blogiausiujuKiekis] = i;
            blogiausiujuKiekis++;
        }
    }
    for (int i = 0; i < blogiausiujuKiekis; i++) {
        out << Sarasas[blogiausiuNr[i]].vardas << " " << Sarasas[blogiausiuNr[i]].pavarde << "\n";
    }

//-------------------------------------------------------------------------
    out << "\n----------------------------------\n";
    out << "Pazangus studentai: \n";
    out << "----------------------------------\n";
    for (int i = 0; i < kiek; i++) {
        if(blogoVidurkis != Sarasas[i].vidurkis) {
            for(int j = 0; j < 15; j++) {
                TieGeresni[tieGeresniKiek].vardas[j] = Sarasas[i].vardas[j];
                TieGeresni[tieGeresniKiek].pavarde[j] = Sarasas[i].pavarde[j];
            }
            tieGeresniKiek++;
        }
    }

    for (int i = 0; i < tieGeresniKiek; i++) {
        out << TieGeresni[i].vardas << " " << TieGeresni[i].pavarde << "\n";
    }

    in.close();
    out.close();

    return 0;
}
