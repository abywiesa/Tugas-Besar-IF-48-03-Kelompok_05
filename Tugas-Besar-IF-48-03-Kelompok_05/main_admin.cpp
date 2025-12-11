#include "header.h"
#include <iostream>

using namespace std;

int main() {
    listJurnalis LJ;
    listBerita LB;

    createJournalistList(LJ);
    createNewsList(LB);

    int pilihan = -1;
    while (pilihan != 0) {
        cout << "\n================================" << endl;
        cout << "   APLIKASI MANAJEMEN BERITA" << endl;
        cout << "================================" << endl;
        cout << "1. Masuk Menu Jurnalis" << endl;
        cout << "2. Masuk Menu Berita" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            menuJournalistAdmin(LJ); 
            break;
        case 2:
            menuNewsAdmin(LB); 
            break;
        case 0:
            cout << "Terima kasih." << endl;
            break;
        default:
            cout << "Pilihan salah." << endl;
        }
    }
    return 0;
}