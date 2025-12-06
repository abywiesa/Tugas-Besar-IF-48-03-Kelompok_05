#include "Berita.h"
#include <iostream>
using namespace std;

void createJournalistList(listJurnalis &L){
    L.first = nullptr;
};

bool isJournalistListEmpty(listJurnalis L){
    return (L.first == nullptr);
};

void insertJournalistFirst(listJurnalis &L, adrJurnalis p){
    if (isJournalistListEmpty(L)){
        L.first = p;
    } else {
        p->next = L.first;
        L.first = p;
    }
};

void insertJournalistAfter(listJurnalis &L, string idKey, adrJurnalis p){
    adrJurnalis prec = findJournalistByID(L, idKey);

    if (prec == nullptr) {
        cout << "ID jurnalis sebelumnya tidak ditemukan. Gagal insert after.\n";
    } else {
        p->next = prec->next;
        prec->next = p;
    }
};

adrJurnalis findJournalistByName(listJurnalis L, string nameKey){
    adrJurnalis p = L.first;
    while (p != nullptr) {
        if (p->info.nama == nameKey) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
};
void deleteJournalistLast(listJurnalis &L) {
    if (isJournalistListEmpty(L)) {
        cout << "List kosong, tidak ada yang dihapus.\n";
        return;
    }

    adrJurnalis p = L.first;

    if (p->next == nullptr) {
        L.first = nullptr;
        delete p;
    } 
    else {
        adrJurnalis prev = nullptr;
        
        while (p->next != nullptr) {
            prev = p;
            p = p->next;
        }
        prev->next = nullptr;
        delete p;
    }
}

void updateJournalist(listJurnalis &L, string idTarget){
    adrJurnalis p = findJournalistByID(L, idTarget);

    if (p == nullptr) {
        cout << "ID jurnalis tidak ditemukan.\n";
        return;
    }

    cout << "Masukkan data jurnalis baru:\n";
    cout << "ID: ";
    cin >> p->info.id;
    cout << "Nama: ";
    cin >> p->info.nama;
    cout << "Umur: ";
    cin >> p->info.umur
};

void showMaleJournalists(listJurnalis L) {
    if (isJournalistListEmpty(L)) {
        cout << "Data jurnalis kosong.\n";
        return;
    }

    adrJurnalis p = L.first;
    int count = 0;

    cout << "\n=== DAFTAR JURNALIS LAKI-LAKI ===\n";
    while (p != nullptr) {
        if (p->info.gender == "L" || p->info.gender == "Laki-laki" || p->info.gender == "Male") {
            cout << "- " << p->info.nama << " (ID: " << p->info.id << ", Umur: " << p->info.umur << ")\n";
            count++;
        }
        p = p->next;
    }

    if (count == 0) {
        cout << "Tidak ditemukan jurnalis laki-laki.\n";
    }
}

void menuJournalistAdmin(listJurnalis &L) {
    int choice = -1;
    dataJurnalis d;
    string key;

    while (choice != 0) {
        cout << "\n================================\n";
        cout << "  MENU ADMIN JURNALIS \n";
        cout << "================================\n";
        cout << "--- INSERT ---\n";
        cout << "1. Tambah Jurnalis Awal\n";
        cout << "2. Tambah Jurnalis Akhir\n";
        cout << "3. Tambah Jurnalis Setelah ID\n";
        cout << "--- DELETE ---\n";
        cout << "4. Hapus Jurnalis Awal\n";
        cout << "5. Hapus Jurnalis Akhir\n";
        cout << "6. Hapus Jurnalis Berdasarkan ID\n";
        cout << "--- SEARCH & UPDATE ---\n";
        cout << "7. Cari Jurnalis Berdasarkan Nama\n";
        cout << "8. Update Data Jurnalis (by ID)\n";
        cout << "--- DISPLAY & COUNT ---\n";
        cout << "9. Tampilkan Semua Jurnalis\n";
        cout << "10. Tampilkan Jurnalis Laki-laki\n";
        cout << "11. Tampilkan Jurnalis Perempuan\n";
        cout << "12. Hitung Total Jurnalis\n";
        cout << "0. Keluar\n";
        cout << "--------------------------------\n";
        cout << "Pilihan: ";
        cin >> choice;

        cout << endl;

        if (choice >= 1 && choice <= 3) {
            cout << "Masukkan Data Jurnalis Baru:\n";
            cout << "ID: "; cin >> d.id;
            cout << "Nama: "; cin >> d.nama;
            cout << "Umur: "; cin >> d.umur;
            cout << "Gender (L/P): "; cin >> d.gender;
        }

        switch (choice) {
        case 1:
            insertJournalistFirst(L, createJournalistElement(d));
            cout << "Jurnalis ditambahkan di awal.\n";
            break;
        case 2:
            insertJournalistLast(L, createJournalistElement(d));
            cout << "Jurnalis ditambahkan di akhir.\n";
            break;
        case 3:
            cout << "Masukkan ID Patokan: "; cin >> key;
            insertJournalistAfter(L, key, createJournalistElement(d));
            break;
        case 4:
            deleteJournalistFirst(L);
            break;
        case 5:
            deleteJournalistLast(L);
            break;
        case 6:
            cout << "Masukkan ID yang ingin dihapus: "; cin >> key;
            deleteJournalistByID(L, key);
            break;
        case 7:
            cout << "Masukkan Nama yang dicari: "; cin >> key;
            adrJurnalis result = findJournalistByName(L, key);
            if (result != nullptr) {
                cout << "Ditemukan! ID: " << result->info.id << ", Umur: " << result->info.umur << endl;
            } else {
                cout << "Jurnalis dengan nama " << key << " tidak ditemukan.\n";
            }
            break;
        case 8:
            cout << "Masukkan ID yang akan diupdate: "; cin >> key;
            updateJournalist(L, key);
            break;
        case 9:
            showAllJournalists(L);
            break;
        case 10:
            showMaleJournalists(L);
            break;
        case 11:
            showFemaleJournalists(L);
            break;
        case 12:
            cout << "Total Jurnalis saat ini: " << countJournalists(L) << " orang.\n";
            break;
        case 0:
            cout << "Terima kasih. Program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
            break;
        }
    }
}