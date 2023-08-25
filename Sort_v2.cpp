#include <iostream>
#include<cmath>
#include<fstream>
#include<ctime>

using namespace std;

void qsort(double *tab, double *tab2, int lewy, int prawy, int wymiar) {
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
            if (wymiar==2) swap(tab2[i], tab2[j]);
            // w przeciwnym wypadku zaprzestaję podział
        }else{break;}
    }

    // ORAZ zwyciężam!
    if (j>lewy) {qsort(tab,tab2, lewy, j, wymiar);}
    if (i<prawy) {qsort(tab,tab2, i, prawy,wymiar);}
}

int main() {

    double *TAB, *TAB2;
    int n;
    int wymiar;
        // Zczytywanie jak dużą pamięć potrzebuję
    cout << "Liczba elementów" << endl;
    cin >> n;
        // sprawdzam wymiar listy
    cout << "Wymiar listy:" << endl;
    cin >> wymiar;

    cout << "Podaj listę " << n*wymiar << " elementów:" << endl;
        // Przydzielanie pamięci i wyczytywanie danych
    TAB = new double [n];
    TAB2 = new double [n];
    for (int i=0; i<n;i++) {
        cin >> TAB[i];
        if (wymiar==2) {
            cin >> TAB2[i];
        }else{TAB2[i]=0;}
    }
        // quick - sort :)
    qsort(TAB, TAB2, 0, n-1,wymiar);

        // jeśli wymiar wynosi 2, posortuj też po drugich elementach

    if (wymiar==2) {
        int i=0, j=0;
        do {
            while(TAB[j++]==TAB[i] || j<n);
            qsort(TAB2, TAB2, i, j, 1);
            i=j;
        } while (j<n);
    }

        //wypisanie
    for (int i=0; i<n;i++) {
        cout << i << ":  " << TAB[i];
        if (wymiar==2) cout << " " << TAB2[i];
        cout << endl;
    }
    return 0;
}
