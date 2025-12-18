#include "header.h"
#include <iostream>
using namespace std;

void createNewsList(listBerita &L) {
    L.first = nullptr;
    L.last = nullptr;
}

bool isNewsListEmpty(listBerita L) {
    return (L.first == nullptr);
}

void insertNewsFirst(listBerita &L, adrBerita p) {
    if (isNewsListEmpty(L)) {
        L.first = p;
        L.last = p;
    } else {
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}

void insertNewsAfter(listBerita &L, string idKey, adrBerita p) {
    adrBerita prec = findNewsByID(L, idKey);

    if (prec == nullptr) {
        cout << "ID berita sebelumnya tidak ditemukan. Gagal insert after.\n";
    } else if (prec == L.last) {
        insertNewsLast(L, p);
    } else {
        p->next = prec->next;
        p->prev = prec;
        prec->next->prev = p;
        prec->next = p;
    }
}

adrBerita findNewsByCategory(listBerita L, string categoryKey) {
    adrBerita p = L.first;
    while (p != nullptr) {
        if (p->info.kategori == categoryKey) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void deleteNewsLast(listBerita &L) {
    if (isNewsListEmpty(L)) {
        cout << "List kosong, tidak ada yang dihapus.\n";
        return;
    }

    adrBerita p = L.last;

    if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.last = p->prev;
        L.last->next = nullptr;
        p->prev = nullptr;
    }
    delete p;
}

void updateNews(listBerita &L, string idTarget) {
    adrBerita p = findNewsByID(L, idTarget);

    if (p == nullptr) {
        cout << "Berita dengan ID " << idTarget << " tidak ditemukan.\n";
    } else {
        cout << "Data Ditemukan. Masukkan data baru:\n";
        p->info.id = getValidString("ID Baru: ");
        p->info.judul = getValidString("Judul Baru: ");
        p->info.kategori = getValidString("Kategori Baru: ");
        p->info.tanggal = getValidString("Tanggal Baru: ");

        cout << "ID Baru      : "; cin >> p->info.id;
        cin.ignore();
        cout << "Judul Baru   : "; getline(cin, p->info.judul);
        cout << "Kategori Baru: "; getline(cin, p->info.kategori);
        cout << "Tanggal Baru : "; getline(cin, p->info.tanggal);
        cout << "ID Jurnalis  : "; getline(cin, p->info.idJurnalis);
        cout << "Update berhasil.\n";
    }
}

int countNewsByCategory(listBerita L, string categoryKey) {
    adrBerita p = L.first;
    int count = 0;

    while (p != nullptr) {
        if (p->info.kategori == categoryKey) {
            count++;
        }
        p = p->next;
    }
    return count;
}

adrBerita getOldestNews(listBerita L) {
    return L.first;
}
