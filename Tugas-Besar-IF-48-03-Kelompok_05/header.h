#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
using namespace std;

// STRUKTUR DATA BERITA 
typedef struct elemenBerita *adrBerita;

struct dataBerita {
    string id;
    string judul;
    string kategori;
    string tanggal;
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

// fungsi berita
void createNewsList(listBerita &L);
adrBerita createNewsElement(dataBerita newData);
bool isNewsListEmpty(listBerita L);
void showAllNews(listBerita L);
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
void menuNewsAdmin(listBerita &L);

// STRUKTUR DATA JURNALIS
typedef struct elemenJurnalis *adrJurnalis;

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

//fungsi jurnalis
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