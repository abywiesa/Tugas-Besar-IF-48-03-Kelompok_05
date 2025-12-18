#include "header.h"
#include <iostream>

using namespace std;

void menuAdminSederhana(listJurnalis &LJ, listBerita &LB) {
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
            menuJournalistAdmin(LJ, LB);
            break;
        case 2:
            menuNewsAdmin(LB, LJ);
            break;
        case 0:
            cout << "Terima kasih." << endl;
            break;
        default:
            cout << "Pilihan salah." << endl;
        }
    }
}
