#include "header.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int getValidMenuChoice(int minChoice, int maxChoice) {
    string input;
    int choice;

    while (true) {
        cout << "Pilihan: ";
        getline(cin, input);

        if (input.empty()) {
            cout << "Input tidak boleh kosong. Masukkan angka "
                 << minChoice << "-" << maxChoice << ": ";
            continue;
        }

        bool isNumber = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }

        if (!isNumber) {
            cout << "Input harus ANGKA. Masukkan angka "
                 << minChoice << "-" << maxChoice << ": ";
            continue;
        }

        choice = stoi(input);

        if (choice >= minChoice && choice <= maxChoice) {
            return choice;
        } else {
            cout << "Pilihan harus antara " << minChoice << " dan "
                 << maxChoice << ". Coba lagi: ";
        }
    }
}

int getValidUmur() {
    string input;
    int umur;

    while (true) {
        cout << "Umur: ";
        getline(cin, input);

        if (input.empty()) {
            cout << "Umur tidak boleh kosong: ";
            continue;
        }

        bool isNumber = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }

        if (!isNumber) {
            cout << "Umur harus ANGKA: ";
            continue;
        }

        umur = stoi(input);

        if (umur > 0 && umur <= 120) {
            return umur;
        } else {
            cout << "Umur harus 1-120 tahun: ";
        }
    }
}

void loadDummyData(listBerita &LB, listJurnalis &LJ) {
    cout << "\n+========================================+\n";
    cout << "|          MEMUAT DATA DUMMY             |\n";
    cout << "+========================================+\n";

    dataBerita b1 = {"B001", "Pemilu 2024 Digelar Sukses", "Politik", "2024-02-14"};
    dataBerita b2 = {"B002", "Gempa Bumi Guncang Jawa Barat", "Bencana", "2024-03-10"};
    dataBerita b3 = {"B003", "Timnas Indonesia Menang Telak", "Olahraga", "2024-04-05"};
    dataBerita b4 = {"B004", "Harga BBM Naik 10 Persen", "Ekonomi", "2024-05-20"};
    dataBerita b5 = {"B005", "Festival Budaya Nusantara 2024", "Budaya", "2024-06-12"};

    insertNewsLast(LB, createNewsElement(b1));
    insertNewsLast(LB, createNewsElement(b2));
    insertNewsLast(LB, createNewsElement(b3));
    insertNewsLast(LB, createNewsElement(b4));
    insertNewsLast(LB, createNewsElement(b5));

    dataJurnalis j1 = {"J001", "Ahmad Fauzi", 28, "L"};
    dataJurnalis j2 = {"J002", "Siti Nurhaliza", 32, "P"};
    dataJurnalis j3 = {"J003", "Budi Santoso", 25, "L"};
    dataJurnalis j4 = {"J004", "Dewi Lestari", 30, "P"};
    dataJurnalis j5 = {"J005", "Eko Prasetyo", 27, "L"};

    insertJournalistLast(LJ, createJournalistElement(j1));
    insertJournalistLast(LJ, createJournalistElement(j2));
    insertJournalistLast(LJ, createJournalistElement(j3));
    insertJournalistLast(LJ, createJournalistElement(j4));
    insertJournalistLast(LJ, createJournalistElement(j5));

    cout << "✓ 5 Berita dan 5 Jurnalis berhasil dimuat!\n";
}

bool isNewsIDDuplicate(listBerita L, string id) {
    return (findNewsByID(L, id) != nullptr);
}

bool isJournalistIDDuplicate(listJurnalis L, string id) {
    return (findJournalistByID(L, id) != nullptr);
}

void insertNewsWithValidation(listBerita &LB) {
    dataBerita d;

    cout << "\n--- TAMBAH BERITA BARU ---\n";

    cout << "ID Berita: ";
    getline(cin, d.id);

    if (isNewsIDDuplicate(LB, d.id)) {
        cout << "✗ Gagal! ID '" << d.id << "' sudah digunakan.\n";
        cout << "Tekan Enter untuk melanjutkan...";
        cin.get();
        return;
    }

    cout << "Judul Berita: ";
    getline(cin, d.judul);

    cout << "Kategori: ";
    getline(cin, d.kategori);

    cout << "Tanggal (YYYY-MM-DD): ";
    getline(cin, d.tanggal);

    insertNewsLast(LB, createNewsElement(d));
    cout << "✓ Berita berhasil ditambahkan!\n";
}

void insertJournalistWithValidation(listJurnalis &LJ) {
    dataJurnalis d;

    cout << "\n--- TAMBAH JURNALIS BARU ---\n";

    cout << "ID Jurnalis: ";
    getline(cin, d.id);

    if (isJournalistIDDuplicate(LJ, d.id)) {
        cout << "✗ Gagal! ID '" << d.id << "' sudah digunakan.\n";
        cout << "Tekan Enter untuk melanjutkan...";
        cin.get();
        return;
    }

    cout << "Nama Jurnalis: ";
    getline(cin, d.nama);

    d.umur = getValidUmur();

    cout << "Gender (L/P): ";
    getline(cin, d.gender);

    insertJournalistLast(LJ, createJournalistElement(d));
    cout << "✓ Jurnalis berhasil ditambahkan!\n";
}

void displayNewsDetail(adrBerita p) {
    if (p != nullptr) {
        cout << "\n=== DETAIL BERITA ===\n";
        cout << "ID       : " << p->info.id << endl;
        cout << "Judul    : " << p->info.judul << endl;
        cout << "Kategori : " << p->info.kategori << endl;
        cout << "Tanggal  : " << p->info.tanggal << endl;
    }
}

void displayJournalistDetail(adrJurnalis p) {
    if (p != nullptr) {
        cout << "\n=== DETAIL JURNALIS ===\n";
        cout << "ID     : " << p->info.id << endl;
        cout << "Nama   : " << p->info.nama << endl;
        cout << "Umur   : " << p->info.umur << endl;
        cout << "Gender : " << p->info.gender << endl;
    }
}

void showStatistics(listBerita LB, listJurnalis LJ) {
    cout << "\n=== STATISTIK SISTEM ===\n";
    cout << "Total Berita   : " << countNews(LB) << " berita\n";
    cout << "Total Jurnalis : " << countJournalists(LJ) << " orang\n";

    cout << "\n=== BERITA PER KATEGORI ===\n";
    adrBerita p = LB.first;
    string categories[100];
    int catCount[100] = {0};
    int totalCats = 0;

    while (p != nullptr) {
        bool found = false;
        for (int i = 0; i < totalCats; i++) {
            if (categories[i] == p->info.kategori) {
                catCount[i]++;
                found = true;
                break;
            }
        }
        if (!found) {
            categories[totalCats] = p->info.kategori;
            catCount[totalCats] = 1;
            totalCats++;
        }
        p = p->next;
    }

    for (int i = 0; i < totalCats; i++) {
        cout << "- " << categories[i] << ": " << catCount[i] << " berita\n";
    }

    cout << "\n=== JURNALIS PER GENDER ===\n";
    int maleCount = 0, femaleCount = 0;
    adrJurnalis j = LJ.first;
    while (j != nullptr) {
        if (j->info.gender == "L" || j->info.gender == "l") {
            maleCount++;
        } else if (j->info.gender == "P" || j->info.gender == "p") {
            femaleCount++;
        }
        j = j->next;
    }
    cout << "- Laki-laki : " << maleCount << " orang\n";
    cout << "- Perempuan : " << femaleCount << " orang\n";
}

void menuUser(listBerita &LB, listJurnalis &LJ) {
    static bool dummyLoaded = false;

    if (!dummyLoaded) {
        loadDummyData(LB, LJ);
        dummyLoaded = true;
        cout << "\nTekan Enter untuk melanjutkan...";
        cin.get();
    }

    int pilihan = 0;

    while (pilihan != 21) {
        system("cls");
        cout << "\n+========================================+\n";
        cout << "|           MENU USER - STUDY CASE       |\n";
        cout << "+========================================+\n";
        cout << "| [1]  Tampilkan Semua Berita           |\n";
        cout << "| [2]  Tampilkan Semua Jurnalis         |\n";
        cout << "| [3]  Cari Berita (by ID)              |\n";
        cout << "| [4]  Cari Berita (by Kategori)        |\n";
        cout << "| [5]  Cari Jurnalis (by ID)            |\n";
        cout << "| [6]  Cari Jurnalis (by Nama)          |\n";
        cout << "| [7]  Tampilkan Statistik Sistem       |\n";
        cout << "| [8]  Hitung Total Berita              |\n";
        cout << "| [9]  Hitung Berita per Kategori       |\n";
        cout << "| [10] Hitung Total Jurnalis            |\n";
        cout << "| [11] Tampilkan Jurnalis Laki-laki     |\n";
        cout << "| [12] Tampilkan Jurnalis Perempuan     |\n";
        cout << "| [13] Tampilkan Berita Terbaru         |\n";
        cout << "| [14] Tampilkan Berita Terlama         |\n";
        cout << "| [15] Cek Ketersediaan Berita          |\n";
        cout << "| [16] Cek Ketersediaan Jurnalis        |\n";
        cout << "| [17] Tambah Berita Baru               |\n";
        cout << "| [18] Tambah Jurnalis Baru             |\n";
        cout << "| [19] Update Data Berita               |\n";
        cout << "| [20] Update Data Jurnalis             |\n";
        cout << "| [21] Kembali ke Menu Utama            |\n";
        cout << "+========================================+\n";

        pilihan = getValidMenuChoice(1, 21);

        cin.ignore();

        switch (pilihan) {
            case 1:
                system("cls");
                cout << "\n=== DAFTAR SEMUA BERITA ===\n";
                showAllNews(LB);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 2:
                system("cls");
                cout << "\n=== DAFTAR SEMUA JURNALIS ===\n";
                showAllJournalists(LJ);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 3: {
                system("cls");
                string id;
                cout << "\n=== CARI BERITA BERDASARKAN ID ===\n";
                cout << "Masukkan ID Berita: ";
                getline(cin, id);
                adrBerita result = findNewsByID(LB, id);
                if (result != nullptr) {
                    displayNewsDetail(result);
                } else {
                    cout << "Berita dengan ID '" << id << "' tidak ditemukan.\n";
                }
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;
            }

            case 4: {
                system("cls");
                string kategori;
                cout << "\n=== CARI BERITA BERDASARKAN KATEGORI ===\n";
                cout << "Masukkan Kategori: ";
                getline(cin, kategori);
                adrBerita result = findNewsByCategory(LB, kategori);
                if (result != nullptr) {
                    displayNewsDetail(result);
                    cout << "\nCatatan: Menampilkan berita pertama yang ditemukan\n";
                    cout << "Total berita dengan kategori ini: "
                         << countNewsByCategory(LB, kategori) << " berita\n";
                } else {
                    cout << "Tidak ada berita dengan kategori '" << kategori << "'\n";
                }
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;
            }

            case 5: {
                system("cls");
                string id;
                cout << "\n=== CARI JURNALIS BERDASARKAN ID ===\n";
                cout << "Masukkan ID Jurnalis: ";
                getline(cin, id);
                adrJurnalis result = findJournalistByID(LJ, id);
                if (result != nullptr) {
                    displayJournalistDetail(result);
                } else {
                    cout << "Jurnalis dengan ID '" << id << "' tidak ditemukan.\n";
                }
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;
            }

            case 6: {
                system("cls");
                string nama;
                cout << "\n=== CARI JURNALIS BERDASARKAN NAMA ===\n";
                cout << "Masukkan Nama Jurnalis: ";
                getline(cin, nama);
                adrJurnalis result = findJournalistByName(LJ, nama);
                if (result != nullptr) {
                    displayJournalistDetail(result);
                } else {
                    cout << "Jurnalis dengan nama '" << nama << "' tidak ditemukan.\n";
                }
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;
            }

            case 7:
                system("cls");
                showStatistics(LB, LJ);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 8:
                system("cls");
                cout << "\n=== TOTAL BERITA ===\n";
                cout << "Total Berita: " << countNews(LB) << " berita\n";
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 9: {
                system("cls");
                string kategori;
                cout << "\n=== HITUNG BERITA PER KATEGORI ===\n";
                cout << "Masukkan Kategori: ";
                getline(cin, kategori);
                int jumlah = countNewsByCategory(LB, kategori);
                cout << "Jumlah berita kategori '" << kategori << "': "
                     << jumlah << " berita\n";
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;
            }

            case 10:
                system("cls");
                cout << "\n=== TOTAL JURNALIS ===\n";
                cout << "Total Jurnalis: " << countJournalists(LJ) << " orang\n";
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 11:
                system("cls");
                showMaleJournalists(LJ);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 12:
                system("cls");
                showFemaleJournalists(LJ);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 13: {
                system("cls");
                adrBerita newest = getNewestNews(LB);
                cout << "\n=== BERITA TERBARU ===\n";
                if (newest != nullptr) {
                    displayNewsDetail(newest);
                } else {
                    cout << "Tidak ada berita\n";
                }
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;
            }

            case 14: {
                system("cls");
                adrBerita oldest = getOldestNews(LB);
                cout << "\n=== BERITA TERLAMA ===\n";
                if (oldest != nullptr) {
                    displayNewsDetail(oldest);
                } else {
                    cout << "Tidak ada berita\n";
                }
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;
            }

            case 15:
                system("cls");
                cout << "\n=== KETERSEDIAAN DATA BERITA ===\n";
                if (isNewsListEmpty(LB)) {
                    cout << "Data berita KOSONG\n";
                } else {
                    cout << "Data berita TERSEDIA (" << countNews(LB) << " berita)\n";
                }
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 16:
                system("cls");
                cout << "\n=== KETERSEDIAAN DATA JURNALIS ===\n";
                if (isJournalistListEmpty(LJ)) {
                    cout << "Data jurnalis KOSONG\n";
                } else {
                    cout << "Data jurnalis TERSEDIA (" << countJournalists(LJ) << " orang)\n";
                }
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 17:
                system("cls");
                insertNewsWithValidation(LB);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 18:
                system("cls");
                insertJournalistWithValidation(LJ);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 19: {
                system("cls");
                string id;
                cout << "\n=== UPDATE DATA BERITA ===\n";
                cout << "Masukkan ID Berita yang akan diupdate: ";
                getline(cin, id);
                updateNews(LB, id);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;
            }

            case 20: {
                system("cls");
                string id;
                cout << "\n=== UPDATE DATA JURNALIS ===\n";
                cout << "Masukkan ID Jurnalis yang akan diupdate: ";
                getline(cin, id);
                updateJournalist(LJ, id);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;
            }

            case 21:
                cout << "\nKembali ke menu utama...\n";
                break;
        }
    }
}
