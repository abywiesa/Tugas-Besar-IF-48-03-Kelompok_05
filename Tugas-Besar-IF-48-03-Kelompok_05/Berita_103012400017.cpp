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

void menuNewsAdmin(listBerita &L) {
    int choice = -1;

    while (choice != 0) {
        cout << "\n=== MENU ADMIN BERITA ===\n";
        cout << "1. Tambah Berita\n";
        cout << "2. Hapus Berita\n";
        cout << "3. Tampilkan Semua\n";
        cout << "4. Update Data\n";
        cout << "0. Kembali\n";
        cout << "Pilihan: ";
        cin >> choice;
        cin.ignore(); // PENTING: Clear buffer setelah cin >>

        if (choice == 1) {
            dataBerita d;
            cout << "Masukkan Data Berita:\n";
            d.id = getValidString("ID: ");
            d.judul = getValidString("Judul: ");
            d.kategori = getValidString("Kategori: ");
            d.tanggal = getValidString("Tanggal: ");

            insertNewsLast(L, createNewsElement(d));
            cout << "Berita berhasil ditambahkan!\n";
        }
        else if (choice == 2) {
            string x = getValidString("Masukkan ID: ");
            deleteNewsByID(L, x);
        }
        else if (choice == 3) {
            showAllNews(L);
        }
        else if (choice == 4) {
            string id = getValidString("ID yang akan diperbarui: ");
            updateNews(L, id);
        }
    }
}