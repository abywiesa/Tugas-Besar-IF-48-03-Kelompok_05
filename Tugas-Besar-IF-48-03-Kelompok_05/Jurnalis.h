#ifndef JURNALIS_H_INCLUDED
#define JURNALIS_H_INCLUDED
#ifndef JURNALIS_H_INCLUDED
#define JURNALIS_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct elemenJurnalis *adrJurnalis;

struct dataJurnalis {
    string id;
    string nama;
    int umur;
    string gender;
    int umur;
    string gender;
};

struct elemenJurnalis {
    dataJurnalis info;
    adrJurnalis next;
};

struct listJurnalis {
    adrJurnalis first;
};

void createJournalistList(listJurnalis &L);
adrJurnalis createJournalistElement(dataJurnalis newData);
bool isJournalistListEmpty(listJurnalis L);
void showAllJournalists(listJurnalis L);
void insertJournalistFirst(listJurnalis &L, adrJurnalis p);
void insertJournalistLast(listJurnalis &L, adrJurnalis p);
void insertJournalistAfter(listJurnalis &L, string idKey, adrJurnalis p);
adrJurnalis findJournalistByID(listJurnalis L, string idKey);
adrJurnalis findJournalistByName(listJurnalis L, string nameKey);
void deleteJournalistFirst(listJurnalis &L);
void deleteJournalistLast(listJurnalis &L);
void deleteJournalistByID(listJurnalis &L, string idDelete);
void updateJournalist(listJurnalis &L, string idTarget);
int countJournalists(listJurnalis L);
void showMaleJournalists(listJurnalis L);
void showFemaleJournalists(listJurnalis L);
void menuJournalistAdmin(listJurnalis &L);

#endif
