#ifndef BERITA_H_INCLUDED
#define BERITA_H_INCLUDED

#include <iostream>
using namespace std;

struct dataBerita {
    string id;
    string judul;
    string kategori;
    string tanggal;
};

struct elemenBerita {
    dataBerita info;
    elemenBerita *next;
    elemenBerita *prev;
};

struct listBerita {
    elemenBerita *first;
    elemenBerita *last;
};

void buatListBerita(listBerita &L);
elemenBerita* buatElemenBerita(dataBerita dataBaru);
bool listBeritaKosong(listBerita L);
void tampilkanSemuaBerita(listBerita L);
void sisipBeritaAwal(listBerita &L, elemenBerita *p);
void sisipBeritaAkhir(listBerita &L, elemenBerita *p);
void sisipBeritaSetelah(listBerita &L, string idPatokan, elemenBerita *p);
elemenBerita* cariBerita(listBerita L, string idDicari);
void hapusBeritaAwal(listBerita &L);
void hapusBeritaAkhir(listBerita &L);
void hapusBeritaTertentu(listBerita &L, string idHapus);
int hitungJumlahBerita(listBerita L);
elemenBerita* cariBeritaKategori(listBerita L, string kategori);
void updateDataBerita(listBerita &L, string idTarget);
void menuKelolaBerita(listBerita &L);

#endif