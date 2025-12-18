#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
using namespace std;

typedef struct elemenBerita *adrBerita;
typedef struct elemenJurnalis *adrJurnalis;

struct dataBerita {
    string id;
    string judul;
    string kategori;
    string tanggal;
    string idJurnalis;
};

struct elemenBerita {
    dataBerita info;
    adrBerita next;
    adrBerita prev;
};

struct listBerita {
    adrBerita first;
    adrBerita last;
};

struct dataJurnalis {
    string id;
    string nama;
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

void createNewsList(listBerita &L);
adrBerita createNewsElement(dataBerita newData);
bool isNewsListEmpty(listBerita L);
void showAllNews(listBerita L);
void showAllNewsWithJournalist(listBerita LB, listJurnalis LJ);
void insertNewsFirst(listBerita &L, adrBerita p);
void insertNewsLast(listBerita &L, adrBerita p);
void insertNewsAfter(listBerita &L, string idKey, adrBerita p);
adrBerita findNewsByID(listBerita L, string idKey);
adrBerita findNewsByCategory(listBerita L, string categoryKey);
void deleteNewsFirst(listBerita &L);
void deleteNewsLast(listBerita &L);
void deleteNewsByID(listBerita &L, string idDelete);
void updateNews(listBerita &L, string idTarget);
int countNews(listBerita L);
int countNewsByCategory(listBerita L, string categoryKey);
adrBerita getNewestNews(listBerita L);
adrBerita getOldestNews(listBerita L);
void menuNewsAdmin(listBerita &L, listJurnalis &LJ);

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
void menuJournalistAdmin(listJurnalis &L, listBerita &LB);

void showNewsByJournalist(listBerita LB, listJurnalis LJ, string idJurnalis);
int countNewsByJournalist(listBerita LB, string idJurnalis);
void insertNewsFromJournalist(listBerita &LB, listJurnalis &LJ, string idJurnalis);


int getValidInteger(const string& prompt);
int getValidUmur();
char getValidGender();
string getValidString(const string& prompt);

#endif
