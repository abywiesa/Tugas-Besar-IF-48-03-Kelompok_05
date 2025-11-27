#ifndef BERITA_H
#define BERITA_H

#include <iostream>
#include <string>
using namespace std;

struct Berita {
    string id_berita;
    string judul;
    string kategori;
    string tanggal_terbit;
    int jumlah_kata;