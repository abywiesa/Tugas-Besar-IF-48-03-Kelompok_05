#include "header.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int getValidMenuChoice(int minChoice, int maxChoice) {
    string input;

    while (true) {
        cout << "Pilihan: ";
        getline(cin, input);

        bool isNumber = !input.empty();
        for (char c : input) {
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }

        if (!isNumber) {
            cout << "Input harus berupa ANGKA!\n";
            continue;
        }

        int choice = stoi(input);
        if (choice < minChoice || choice > maxChoice) {
            cout << "Pilihan harus antara " << minChoice
                 << " - " << maxChoice << "!\n";
            continue;
        }

        return choice;
    }
}



void loadDummyData(listBerita &LB, listJurnalis &LJ) {
    cout << "\n+========================================+\n";
    cout << "|          MEMUAT DATA DUMMY             |\n";
    cout << "+========================================+\n";

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

<<<<<<< HEAD
    cout << " 5 Berita dan 5 Jurnalis berhasil dimuat!\n";
=======
    dataBerita b1 = {"B001", "Pemilu 2024 Digelar Sukses", "Politik", "2024-02-14", "J001"};
    dataBerita b2 = {"B002", "Gempa Bumi Guncang Jawa Barat", "Bencana", "2024-03-10", "J002"};
    dataBerita b3 = {"B003", "Timnas Indonesia Menang Telak", "Olahraga", "2024-04-05", "J003"};
    dataBerita b4 = {"B004", "Harga BBM Naik 10 Persen", "Ekonomi", "2024-05-20", "J001"};
    dataBerita b5 = {"B005", "Festival Budaya Nusantara 2024", "Budaya", "2024-06-12", "J004"};

    insertNewsLast(LB, createNewsElement(b1));
    insertNewsLast(LB, createNewsElement(b2));
    insertNewsLast(LB, createNewsElement(b3));
    insertNewsLast(LB, createNewsElement(b4));
    insertNewsLast(LB, createNewsElement(b5));

    cout << "[OK] 5 Berita dan 5 Jurnalis berhasil dimuat!\n";
    cout << "[INFO] Setiap berita sudah terhubung dengan jurnalis.\n";
>>>>>>> 8d4acfae3ae6bfd3468c93ae86af217a498da2fe
}

bool isNewsIDDuplicate(listBerita L, string id) {
    return (findNewsByID(L, id) != nullptr);
}

bool isJournalistIDDuplicate(listJurnalis L, string id) {
    return (findJournalistByID(L, id) != nullptr);
}

void insertNewsWithValidation(listBerita &LB, listJurnalis &LJ) {
    dataBerita d;

    cout << "\n--- TAMBAH BERITA BARU ---\n";

    cout << "ID Berita: ";
    getline(cin, d.id);

    if (isNewsIDDuplicate(LB, d.id)) {
        cout << "[X] Gagal! ID '" << d.id << "' sudah digunakan.\n";
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

    cout << "\n--- Daftar Jurnalis ---\n";
    showAllJournalists(LJ);

    cout << "\nID Jurnalis Penulis: ";
    getline(cin, d.idJurnalis);

    if (findJournalistByID(LJ, d.idJurnalis) == nullptr) {
        cout << "[X] ID Jurnalis tidak valid!\n";
        cout << "Tekan Enter untuk melanjutkan...";
        cin.get();
        return;
    }

    insertNewsLast(LB, createNewsElement(d));
    cout << "[OK] Berita berhasil ditambahkan!\n";
}

void insertJournalistWithValidation(listJurnalis &LJ) {
    dataJurnalis d;

    cout << "\n--- TAMBAH JURNALIS BARU ---\n";

    cout << "ID Jurnalis: ";
    getline(cin, d.id);

    if (isJournalistIDDuplicate(LJ, d.id)) {
        cout << "[X] Gagal! ID '" << d.id << "' sudah digunakan.\n";
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
    cout << "[OK] Jurnalis berhasil ditambahkan!\n";
}

void displayNewsDetail(adrBerita p, listJurnalis LJ) {
    if (p != nullptr) {
        cout << "\n=== DETAIL BERITA ===\n";
        cout << "ID       : " << p->info.id << endl;
        cout << "Judul    : " << p->info.judul << endl;
        cout << "Kategori : " << p->info.kategori << endl;
        cout << "Tanggal  : " << p->info.tanggal << endl;

        adrJurnalis j = findJournalistByID(LJ, p->info.idJurnalis);
        if (j != nullptr) {
            cout << "Penulis  : " << j->info.nama << " (ID: " << j->info.id << ")" << endl;
        } else {
            cout << "Penulis  : Tidak ditemukan" << endl;
        }
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

    cout << "\n=== PRODUKTIVITAS JURNALIS ===\n";
    j = LJ.first;
    while (j != nullptr) {
        int newsCount = countNewsByJournalist(LB, j->info.id);
        cout << "- " << j->info.nama << ": " << newsCount << " berita\n";
        j = j->next;
    }
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

    while (pilihan != 23) {
        system("cls");
        cout << "\n+========================================+\n";
        cout << "|           MENU USER - STUDY CASE       |\n";
        cout << "+========================================+\n";
        cout << "| [1]  Tampilkan Semua Berita           |\n";
        cout << "| [2]  Tampilkan Berita + Jurnalis      |\n";
        cout << "| [3]  Tampilkan Semua Jurnalis         |\n";
        cout << "| [4]  Cari Berita (by ID)              |\n";
        cout << "| [5]  Cari Berita (by Kategori)        |\n";
        cout << "| [6]  Cari Jurnalis (by ID)            |\n";
        cout << "| [7]  Cari Jurnalis (by Nama)          |\n";
        cout << "| [8]  Tampilkan Statistik Sistem       |\n";
        cout << "| [9]  Hitung Total Berita              |\n";
        cout << "| [10] Hitung Berita per Kategori       |\n";
        cout << "| [11] Hitung Total Jurnalis            |\n";
        cout << "| [12] Tampilkan Jurnalis Laki-laki     |\n";
        cout << "| [13] Tampilkan Jurnalis Perempuan     |\n";
        cout << "| [14] Tampilkan Berita Terbaru         |\n";
        cout << "| [15] Tampilkan Berita Terlama         |\n";
        cout << "| [16] Cek Ketersediaan Berita          |\n";
        cout << "| [17] Cek Ketersediaan Jurnalis        |\n";
        cout << "| [18] Tambah Berita Baru               |\n";
        cout << "| [19] Tambah Jurnalis Baru             |\n";
        cout << "| [20] Update Data Berita               |\n";
        cout << "| [21] Update Data Jurnalis             |\n";
        cout << "| [22] Lihat Berita oleh Jurnalis       |\n";
        cout << "| [23] Kembali ke Menu Utama            |\n";
        cout << "+========================================+\n";

        pilihan = getValidMenuChoice(1, 23);

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
                showAllNewsWithJournalist(LB, LJ);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 3:
                system("cls");
                cout << "\n=== DAFTAR SEMUA JURNALIS ===\n";
                showAllJournalists(LJ);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 4: {
                system("cls");
                string id;
                cout << "\n=== CARI BERITA BERDASARKAN ID ===\n";
                cout << "Masukkan ID Berita: ";
                getline(cin, id);
                adrBerita result = findNewsByID(LB, id);
                if (result != nullptr) {
                    displayNewsDetail(result, LJ);
                } else {
                    cout << "Berita dengan ID '" << id << "' tidak ditemukan.\n";
                }
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;
            }

            case 5: {
                system("cls");
                string kategori;
                cout << "\n=== CARI BERITA BERDASARKAN KATEGORI ===\n";
                cout << "Masukkan Kategori: ";
                getline(cin, kategori);
                adrBerita result = findNewsByCategory(LB, kategori);
                if (result != nullptr) {
                    displayNewsDetail(result, LJ);
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

            case 6: {
                system("cls");
                string id;
                cout << "\n=== CARI JURNALIS BERDASARKAN ID ===\n";
                cout << "Masukkan ID Jurnalis: ";
                getline(cin, id);
                adrJurnalis result = findJournalistByID(LJ, id);
                if (result != nullptr) {
                    displayJournalistDetail(result);
                    cout << "\nJumlah berita yang ditulis: "
                         << countNewsByJournalist(LB, id) << " berita\n";
                } else {
                    cout << "Jurnalis dengan ID '" << id << "' tidak ditemukan.\n";
                }
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;
            }

            case 7: {
                system("cls");
                string nama;
                cout << "\n=== CARI JURNALIS BERDASARKAN NAMA ===\n";
                cout << "Masukkan Nama Jurnalis: ";
                getline(cin, nama);
                adrJurnalis result = findJournalistByName(LJ, nama);
                if (result != nullptr) {
                    displayJournalistDetail(result);
                    cout << "\nJumlah berita yang ditulis: "
                         << countNewsByJournalist(LB, result->info.id) << " berita\n";
                } else {
                    cout << "Jurnalis dengan nama '" << nama << "' tidak ditemukan.\n";
                }
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;
            }

            case 8:
                system("cls");
                showStatistics(LB, LJ);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 9:
                system("cls");
                cout << "\n=== TOTAL BERITA ===\n";
                cout << "Total Berita: " << countNews(LB) << " berita\n";
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 10: {
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

            case 11:
                system("cls");
                cout << "\n=== TOTAL JURNALIS ===\n";
                cout << "Total Jurnalis: " << countJournalists(LJ) << " orang\n";
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 12:
                system("cls");
                showMaleJournalists(LJ);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 13:
                system("cls");
                showFemaleJournalists(LJ);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 14: {
                system("cls");
                adrBerita newest = getNewestNews(LB);
                cout << "\n=== BERITA TERBARU ===\n";
                if (newest != nullptr) {
                    displayNewsDetail(newest, LJ);
                } else {
                    cout << "Tidak ada berita\n";
                }
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;
            }

            case 15: {
                system("cls");
                adrBerita oldest = getOldestNews(LB);
                cout << "\n=== BERITA TERLAMA ===\n";
                if (oldest != nullptr) {
                    displayNewsDetail(oldest, LJ);
                } else {
                    cout << "Tidak ada berita\n";
                }
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;
            }

            case 16:
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

            case 17:
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

            case 18:
                system("cls");
                insertNewsWithValidation(LB, LJ);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 19:
                system("cls");
                insertJournalistWithValidation(LJ);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;

            case 20: {
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

            case 21: {
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

            case 22: {
                system("cls");
                string id;
                cout << "\n=== LIHAT BERITA OLEH JURNALIS ===\n";
                cout << "Masukkan ID Jurnalis: ";
                getline(cin, id);
                showNewsByJournalist(LB, LJ, id);
                cout << "\nTotal berita: " << countNewsByJournalist(LB, id) << " berita\n";
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                break;
            }

            case 23:
                cout << "\nKembali ke menu utama...\n";
                break;
        }
    }
}
