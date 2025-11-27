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

#endif
