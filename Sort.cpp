#include <iostream>
#include<cmath>
#include<fstream>
#include<ctime>

using namespace std;

void qsort(double *tab, int lewy, int prawy) {
        // sprawdzam czy lista nie jest jednoelementowa
    if (prawy<=lewy) return;

        // wybieram punkt środkowy
    double k = tab[(lewy+prawy)/2];

        // ustawiam znaczniki
    int i=lewy-1, j=prawy+1;

    // dzielę
    while(true) {
        // znajduję pierwszy element z lewej niemniejszy
        // oraz pierwszy element z prawej niewiększy
        while(tab[++i]<k);
        while(tab[--j]>k);
        // jeśli znaczniki się nie minęły, zamieniam elementy miejscami
        if (i<=j) {
            swap(tab[i],tab[j]);
            // w przeciwnym wypadku zaprzestaję podział
        }else{break;}
    }

    // ORAZ zwyciężam!
    if (j>lewy) {qsort(tab, lewy, j);}
    if (i<prawy) {qsort(tab, i, prawy);}
}

int main() {

    double *TAB;
    int n;

        // Zczytywanie jak dużą pamięć potrzebuję
    cout << "Liczba elementów" << endl;
    cin >> n;
    cout << "Podaj listę " << n << " elementów:" << endl;
        // Przydzielanie pamięci
    TAB = new double [n];

        // wczytywanie danych
    for (int i=0; i<n;i++) cin >> TAB[i];

        // quick - sort :)
    qsort(TAB,0,n-1);

        //wypisanie
    for (int i=0; i<n;i++) cout << i << ":  " << TAB[i] << endl;

    return 0;
}
