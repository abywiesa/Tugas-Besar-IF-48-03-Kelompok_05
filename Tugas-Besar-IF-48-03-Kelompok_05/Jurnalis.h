#ifndef JURNALIS_H_INCLUDED
#define JURNALIS_H_INCLUDED

#include <iostream>
using namespace std;

struct dataJurnalis {
    string id;
    string nama;
    int umur;
    string gender;
};

struct elemenJurnalis {
    dataJurnalis info;
    elemenJurnalis *next;
};

struct listJurnalis {
    elemenJurnalis *first;
};

void buatListJurnalis(listJurnalis &L);
elemenJurnalis* buatElemenJurnalis(dataJurnalis dataBaru);
bool listJurnalisKosong(listJurnalis L);
void tampilkanSemuaJurnalis(listJurnalis L);
void sisipJurnalisAwal(listJurnalis &L, elemenJurnalis *p);
void sisipJurnalisAkhir(listJurnalis &L, elemenJurnalis *p);
void sisipJurnalisSetelah(listJurnalis &L, string idPatokan, elemenJurnalis *p);
elemenJurnalis* cariJurnalis(listJurnalis L, string idDicari);
void hapusJurnalisAwal(listJurnalis &L);
void hapusJurnalisAkhir(listJurnalis &L);
void hapusJurnalisTertentu(listJurnalis &L, string idHapus);
int hitungJumlahJurnalis(listJurnalis L);
elemenJurnalis* cariJurnalisNama(listJurnalis L, string nama);
void updateDataJurnalis(listJurnalis &L, string idTarget);
void menuKelolaJurnalis(listJurnalis &L);

#endif
