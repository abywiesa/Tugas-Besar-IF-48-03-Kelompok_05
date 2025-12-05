#ifndef BERITA_H_INCLUDED
#define BERITA_H_INCLUDED

#include <iostream>
using namespace std;

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

#endif
