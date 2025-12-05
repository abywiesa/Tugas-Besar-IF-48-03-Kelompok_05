#include "jurnalis.h"
#include <iostream>
using namespace std;

adrJurnalis createJournalistElement(dataJurnalis newData) {
    adrJurnalis p = new elemenJurnalis;
    p->info = newData;
    p->next = nullptr;
    return p;
}

void showAllJournalists(listJurnalis L) {
    adrJurnalis p = L.first;
    if (p == nullptr) {
        cout << "Tidak ada data jurnalis.\n";
        return;
    }
    cout << "\n=== DAFTAR JURNALIS ===\n";
    while (p != nullptr) {
        cout << "ID     : " << p->info.id << endl;
        cout << "Nama   : " << p->info.nama << endl;
        cout << "Umur   : " << p->info.umur << endl;
        cout << "Gender : " << p->info.gender << endl;
        cout << "-----------------------\n";
        p = p->next;
    }
}

void insertJournalistLast(listJurnalis &L, adrJurnalis p) {
    if (L.first == nullptr) {
        L.first = p;
    } else {
        adrJurnalis q = L.first;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = p;
    }
}

adrJurnalis findJournalistByID(listJurnalis L, string idKey) {
    adrJurnalis p = L.first;
    while (p != nullptr && p->info.id != idKey) {
        p = p->next;
    }
    return p;
}

void deleteJournalistFirst(listJurnalis &L) {
    if (L.first != nullptr) {
        adrJurnalis p = L.first;
        L.first = p->next;
        delete p;
    }
}

void deleteJournalistByID(listJurnalis &L, string idDelete) {
    adrJurnalis p = L.first;
    adrJurnalis q = nullptr;

    while (p != nullptr && p->info.id != idDelete) {
        q = p;
        p = p->next;
    }

    if (p == nullptr) {
        cout << "ID tidak ditemukan.\n";
        return;
    }

    if (p == L.first) {
        L.first = p->next;
    } else {
        q->next = p->next;
    }

    delete p;
    cout << "Data berhasil dihapus.\n";
}

int countJournalists(listJurnalis L) {
    int count = 0;
    adrJurnalis p = L.first;
    while (p != nullptr) {
        count++;
        p = p->next;
    }
    return count;
}

void showFemaleJournalists(listJurnalis L) {
    adrJurnalis p = L.first;
    while (p != nullptr) {
        if (p->info.gender == "P") {
            cout << p->info.nama << endl;
        }
        p = p->next;
    }
}
