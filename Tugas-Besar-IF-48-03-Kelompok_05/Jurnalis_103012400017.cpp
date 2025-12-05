#include "jurnalis.h"

// 1
void createListJurnalis(ListJurnalis &L) {
    L.first = NULL;
}

// 2
addressJ createElmJurnalis(string id, string nama, int umur, string gender) {
    addressJ P = new elmJurnalis;
    P->id = id;
    P->nama = nama;
    P->umur = umur;
    P->gender = gender;
    P->next = NULL;
    return P;
}

// 3
void insertJurnalisAwal(ListJurnalis &L, addressJ P) {
    P->next = L.first;
    L.first = P;
}

// 4
void insertJurnalisAkhir(ListJurnalis &L, addressJ P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        addressJ Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

// 5
void insertJurnalisSetelah(ListJurnalis &L, string idPatokan, addressJ P) {
    addressJ Q = searchJurnalisByID(L, idPatokan);
    if (Q != NULL) {
        P->next = Q->next;
        Q->next = P;
    } else {
        cout << "ID tidak ditemukan.\n";
    }
}

// 6
void deleteJurnalisAwal(ListJurnalis &L) {
    if (L.first != NULL) {
        addressJ P = L.first;
        L.first = P->next;
        delete P;
    }
}

// 7
void deleteJurnalisAkhir(ListJurnalis &L) {
    if (L.first == NULL) return;
    if (L.first->next == NULL) {
        delete L.first;
        L.first = NULL;
        return;
    }
    addressJ P = L.first;
    addressJ Q = NULL;
    while (P->next != NULL) {
        Q = P;
        P = P->next;
    }
    Q->next = NULL;
    delete P;
}

// 8
void deleteJurnalisTertentu(ListJurnalis &L, string idHapus) {
    if (L.first == NULL) return;
    if (L.first->id == idHapus) {
        deleteJurnalisAwal(L);
        return;
    }
    addressJ P = L.first;
    addressJ Q = NULL;
    while (P != NULL && P->id != idHapus) {
        Q = P;
        P = P->next;
    }
    if (P != NULL) {
        Q->next = P->next;
        delete P;
    }
}

// 9
addressJ searchJurnalisByID(ListJurnalis L, string idDicari) {
    addressJ P = L.first;
    while (P != NULL) {
        if (P->id == idDicari) return P;
        P = P->next;
    }
    return NULL;
}

// 10
addressJ searchJurnalisByNama(ListJurnalis L, string namaDicari) {
    addressJ P = L.first;
    while (P != NULL) {
        if (P->nama == namaDicari) return P;
        P = P->next;
    }
    return NULL;
}

// 11
int hitungJumlahJurnalis(ListJurnalis L) {
    int count = 0;
    addressJ P = L.first;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

// 12
void updateDataJurnalis(ListJurnalis &L, string idTarget) {
    addressJ P = searchJurnalisByID(L, idTarget);
    if (P != NULL) {
        cout << "Nama baru   : "; cin >> P->nama;
        cout << "Umur baru   : "; cin >> P->umur;
        cout << "Gender baru : "; cin >> P->gender;
    } else {
        cout << "ID tidak ditemukan.\n";
    }
}

// 13
void showSemuaJurnalis(ListJurnalis L) {
    addressJ P = L.first;
    cout << "\n=== DATA JURNALIS ===\n";
    if (P == NULL) {
        cout << "Kosong.\n";
        return;
    }
    while (P != NULL) {
        cout << "\nID     : " << P->id;
        cout << "\nNama   : " << P->nama;
        cout << "\nUmur   : " << P->umur;
        cout << "\nGender : " << P->gender << "\n";
        P = P->next;
    }
}

// 14
void menuKelolaJurnalis(ListJurnalis &L) {
    int pil;
    do {
        cout << "\n=== MENU JURNALIS ===";
        cout << "\n1. Tampilkan Semua";
        cout << "\n2. Tambah Jurnalis";
        cout << "\n3. Hapus Jurnalis";
        cout << "\n4. Update Jurnalis";
        cout << "\n0. Kembali";
        cout << "\nPilih: ";
        cin >> pil;

        if (pil == 1) showSemuaJurnalis(L);
        else if (pil == 2) {
            string id, nama, gender; int umur;
            cout << "\nID     : "; cin >> id;
            cout << "Nama   : "; cin >> nama;
            cout << "Umur   : "; cin >> umur;
            cout << "Gender : "; cin >> gender;
            insertJurnalisAkhir(L, createElmJurnalis(id, nama, umur, gender));
        }
        else if (pil == 3) {
            string x;
            cout << "ID dihapus: "; cin >> x;
            deleteJurnalisTertentu(L, x);
        }
        else if (pil == 4) {
            string x;
            cout << "ID update: "; cin >> x;
            updateDataJurnalis(L, x);
        }

    } while (pil != 0);
}
