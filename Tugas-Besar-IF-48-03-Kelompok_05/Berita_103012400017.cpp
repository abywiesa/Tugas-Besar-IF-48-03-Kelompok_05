#include "header.h"
#include <iostream>
using namespace std;

adrBerita createNewsElement(dataBerita newData) {
    adrBerita p = new elemenBerita;
    p->info = newData;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

void showAllNews(listBerita L) {
    adrBerita p = L.first;

    if (p == nullptr) {
        cout << "Tidak ada data berita.\n";
        return;
    }

    cout << "\n=== DAFTAR BERITA ===\n";
    while (p != nullptr) {
        cout << "ID       : " << p->info.id << endl;
        cout << "Judul    : " << p->info.judul << endl;
        cout << "Kategori : " << p->info.kategori << endl;
        cout << "Tanggal  : " << p->info.tanggal << endl;
        cout << "ID Jurnalis: " << p->info.idJurnalis << endl;
        cout << "--------------------------\n";
        p = p->next;
    }
}

void showAllNewsWithJournalist(listBerita LB, listJurnalis LJ) {
    adrBerita p = LB.first;

    if (p == nullptr) {
        cout << "Tidak ada data berita.\n";
        return;
    }

    cout << "\n=== DAFTAR BERITA (Dengan Info Jurnalis) ===\n";
    while (p != nullptr) {
        cout << "ID Berita  : " << p->info.id << endl;
        cout << "Judul      : " << p->info.judul << endl;
        cout << "Kategori   : " << p->info.kategori << endl;
        cout << "Tanggal    : " << p->info.tanggal << endl;

        adrJurnalis j = findJournalistByID(LJ, p->info.idJurnalis);
        if (j != nullptr) {
            cout << "Ditulis oleh: " << j->info.nama << " (ID: " << j->info.id << ")" << endl;
        } else {
            cout << "Ditulis oleh: Jurnalis tidak ditemukan" << endl;
        }
        cout << "--------------------------\n";
        p = p->next;
    }
}

void insertNewsLast(listBerita &L, adrBerita p) {
    if (L.first == nullptr) {
        L.first = p;
        L.last = p;
    } else {
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}

adrBerita findNewsByID(listBerita L, string idKey) {
    adrBerita p = L.first;
    while (p != nullptr && p->info.id != idKey) {
        p = p->next;
    }
    return p;
}

void deleteNewsFirst(listBerita &L) {
    if (L.first == nullptr) return;

    adrBerita p = L.first;

    if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.first = p->next;
        L.first->prev = nullptr;
    }

    delete p;
}

void deleteNewsByID(listBerita &L, string idDelete) {
    adrBerita p = findNewsByID(L, idDelete);

    if (p == nullptr) {
        cout << "ID tidak ditemukan.\n";
        return;
    }

    if (p == L.first)
        deleteNewsFirst(L);

    else if (p == L.last)
        deleteNewsLast(L);

    else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }

    cout << "Data berita berhasil dihapus.\n";
}

int countNews(listBerita L) {
    adrBerita p = L.first;
    int count = 0;

    while (p != nullptr) {
        count++;
        p = p->next;
    }
    return count;
}

adrBerita getNewestNews(listBerita L) {
    return L.last;
}

void showNewsByJournalist(listBerita LB, listJurnalis LJ, string idJurnalis) {
    adrBerita p = LB.first;
    bool found = false;

    adrJurnalis j = findJournalistByID(LJ, idJurnalis);
    if (j == nullptr) {
        cout << "Jurnalis dengan ID " << idJurnalis << " tidak ditemukan.\n";
        return;
    }

    cout << "\n=== BERITA YANG DITULIS OLEH: " << j->info.nama << " ===\n";

    while (p != nullptr) {
        if (p->info.idJurnalis == idJurnalis) {
            cout << "ID       : " << p->info.id << endl;
            cout << "Judul    : " << p->info.judul << endl;
            cout << "Kategori : " << p->info.kategori << endl;
            cout << "Tanggal  : " << p->info.tanggal << endl;
            cout << "--------------------------\n";
            found = true;
        }
        p = p->next;
    }

    if (!found) {
        cout << "Tidak ada berita yang ditulis oleh jurnalis ini.\n";
    }
}

int countNewsByJournalist(listBerita LB, string idJurnalis) {
    adrBerita p = LB.first;
    int count = 0;

    while (p != nullptr) {
        if (p->info.idJurnalis == idJurnalis) {
            count++;
        }
        p = p->next;
    }
    return count;
}

void menuNewsAdmin(listBerita &L, listJurnalis &LJ) {
    int choice = -1;

    while (choice != 0) {
        cout << "\n=== MENU ADMIN BERITA ===\n";
        cout << "1. Tambah Berita\n";
        cout << "2. Hapus Berita\n";
        cout << "3. Tampilkan Semua Berita\n";
        cout << "4. Tampilkan Berita + Info Jurnalis\n";
        cout << "5. Update Data\n";
        cout << "6. Lihat Berita Berdasarkan Jurnalis\n";
        cout << "0. Kembali\n";
        cout << "Pilihan: ";
        cin >> choice;

        if (choice == 1) {
            dataBerita d;
            cin.ignore();

            cout << "\n--- TAMBAH BERITA BARU ---\n";

            bool validID = false;
            while (!validID) {
                cout << "ID Berita    : ";
                getline(cin, d.id);

                if (d.id.empty()) {
                    cout << "[X] ID tidak boleh kosong!\n";
                } else if (findNewsByID(L, d.id) != nullptr) {
                    cout << "[X] ID '" << d.id << "' sudah digunakan! Gunakan ID lain.\n";
                } else {
                    validID = true;
                }
            }

            cout << "Judul        : ";
            getline(cin, d.judul);

            cout << "Kategori     : ";
            getline(cin, d.kategori);

            cout << "Tanggal      : ";
            getline(cin, d.tanggal);

            cout << "\n--- Daftar Jurnalis Tersedia ---\n";
            showAllJournalists(LJ);

            bool validJurnalis = false;
            while (!validJurnalis) {
                cout << "\nID Jurnalis (contoh: J001): ";
                getline(cin, d.idJurnalis);

                if (d.idJurnalis.empty()) {
                    cout << "[X] ID tidak boleh kosong!\n";
                } else if (findJournalistByID(LJ, d.idJurnalis) == nullptr) {
                    cout << "[X] ID Jurnalis '" << d.idJurnalis << "' tidak ditemukan!\n";
                    cout << "    Gunakan ID dari daftar di atas.\n";
                } else {
                    validJurnalis = true;
                }
            }

            insertNewsLast(L, createNewsElement(d));
            cout << "\n[OK] Berita berhasil ditambahkan!\n";
        }
        else if (choice == 2) {
            string x;
            cin.ignore();
            cout << "Masukkan ID: ";
            getline(cin, x);
            deleteNewsByID(L, x);
        }
        else if (choice == 3) {
            showAllNews(L);
        }
        else if (choice == 4) {
            showAllNewsWithJournalist(L, LJ);
        }
        else if (choice == 5) {
            string id;
            cin.ignore();
            cout << "ID yang akan diperbarui: ";
            getline(cin, id);
            updateNews(L, id);
        }
        else if (choice == 6) {
            string idJ;
            cin.ignore();
            cout << "Masukkan ID Jurnalis: ";
            getline(cin, idJ);
            showNewsByJournalist(L, LJ, idJ);
        }
    }
}
