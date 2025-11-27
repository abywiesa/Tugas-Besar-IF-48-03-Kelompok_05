#ifndef JURNALIS_H
#define JURNALIS_H

#include <iostream>
#include <string>
using namespace std;

struct Jurnalis {
    string id_jurnalis;
    string nama;
    string email;
    string bidang;
    int tahun_bergabung;
};

typedef struct elemenJurnalis *addressJurnalis;

struct elemenJurnalis {
    Jurnalis info;
    addressJurnalis next;
};

struct ListJurnalis {
    addressJurnalis first;
};

void buatListJurnalis(ListJurnalis &L);
addressJurnalis alokasiJurnalis(Jurnalis data);
void dealokasiJurnalis(addressJurnalis P);
void sisipJurnalisAwalBerdasarkanTahun(ListJurnalis &L, addressJurnalis P);
void sisipJurnalisAkhirBerdasarkanBidang(ListJurnalis &L, addressJurnalis P);
void sisipJurnalisSetelahBerdasarkanEmail(ListJurnalis &L, addressJurnalis Prec, addressJurnalis P);
void hapusJurnalisAwalBerdasarkanTahun(ListJurnalis &L, addressJurnalis &P);
void hapusJurnalisAkhirBerdasarkanBidang(ListJurnalis &L, addressJurnalis &P);
void hapusJurnalisSetelahBerdasarkanNama(ListJurnalis &L, addressJurnalis Prec, addressJurnalis &P);
addressJurnalis cariJurnalisByID(ListJurnalis L, string id);
addressJurnalis cariJurnalisByNama(ListJurnalis L, string nama);
int hitungTotalJurnalis(ListJurnalis L);
float hitungRataRataTahunBergabung(ListJurnalis L);
void tampilkanSemuaJurnalis(ListJurnalis L);
void tampilkanJurnalisPalingSenior(ListJurnalis L);

#endif
