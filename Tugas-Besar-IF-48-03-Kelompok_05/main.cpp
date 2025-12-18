#include "header.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void menuUser(listBerita &LB, listJurnalis &LJ);

int getValidMainMenuChoice() {
    string input;
    int choice;

    while (true) {
        cout << "\nPilihan: ";
        getline(cin, input);

        if (input.empty()) {
            cout << "Input tidak boleh kosong. Masukkan angka 1-4: ";
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
            cout << "Input harus berupa ANGKA. Masukkan angka 1-4: ";
            continue;
        }

        choice = stoi(input);

        if (choice >= 1 && choice <= 4) {
            return choice;
        } else {
            cout << "Pilihan harus antara 1 dan 4. Coba lagi: ";
        }
    }
}

void displayHeader() {
    system("cls");
    cout << "\n+===============================================+\n";
    cout << "|     SISTEM MANAJEMEN BERITA & JURNALIS        |\n";
    cout << "|         (Linked List Implementation)          |\n";
    cout << "+===============================================+\n";
}

void displayFooter() {
    cout << "\n+===============================================+\n";
    cout << "|        Tekan Enter untuk melanjutkan...       |\n";
    cout << "+===============================================+\n";
}

int main() {
    listBerita beritaAdmin;
    listJurnalis jurnalisAdmin;
    listBerita beritaUser;
    listJurnalis jurnalisUser;

    createNewsList(beritaAdmin);
    createJournalistList(jurnalisAdmin);
    createNewsList(beritaUser);
    createJournalistList(jurnalisUser);

    int pilihan = 0;

    while (pilihan != 4) {
        displayHeader();
        cout << "|                   MENU UTAMA                  |\n";
        cout << "+===============================================+\n";
        cout << "| [1] Menu Admin Berita                        |\n";
        cout << "|     - Kelola data berita (tambah, hapus,     |\n";
        cout << "|       edit, cari)                            |\n";
        cout << "+-----------------------------------------------+\n";
        cout << "| [2] Menu Admin Jurnalis                      |\n";
        cout << "|     - Kelola data jurnalis (tambah, hapus,   |\n";
        cout << "|       edit, cari)                            |\n";
        cout << "|     - Jurnalis bisa menulis berita           |\n";
        cout << "+-----------------------------------------------+\n";
        cout << "| [3] Menu User                                |\n";
        cout << "|     - Study case dengan data dummy           |\n";
        cout << "|     - Fitur lengkap dengan validasi          |\n";
        cout << "+-----------------------------------------------+\n";
        cout << "| [4] Keluar Program                           |\n";
        cout << "+===============================================+\n";

        pilihan = getValidMainMenuChoice();

        switch (pilihan) {
            case 1: {
                bool backToMain = false;

                while (!backToMain) {
                    displayHeader();
                    cout << "|             MENU ADMIN BERITA               |\n";
                    cout << "+===============================================+\n";
                    cout << "| Pilihan:                                     |\n";
                    cout << "| 1. Masuk ke menu admin berita                |\n";
                    cout << "| 2. Reset data berita admin                   |\n";
                    cout << "| 3. Kembali ke menu utama                     |\n";
                    cout << "+===============================================+\n";

                    int subPilihan;
                    string input;

                    while (true) {
                        cout << "Pilihan (1-3): ";
                        getline(cin, input);

                        if (input.empty() || !isdigit(input[0])) {
                            cout << "Input harus angka 1-3: ";
                            continue;
                        }

                        subPilihan = stoi(input);
                        if (subPilihan >= 1 && subPilihan <= 3) {
                            break;
                        }
                        cout << "Pilihan harus 1-3: ";
                    }

                    switch (subPilihan) {
                        case 1:
                            system("cls");
                            cout << "\nMEMUAT MENU ADMIN BERITA...\n";
                            menuNewsAdmin(beritaAdmin, jurnalisAdmin);
                            break;

                        case 2:
                            while (beritaAdmin.first != nullptr) {
                                deleteNewsFirst(beritaAdmin);
                            }
                            cout << "\n[OK] Data berita admin telah direset!\n";
                            displayFooter();
                            cin.get();
                            break;

                        case 3:
                            backToMain = true;
                            break;
                    }
                }
                break;
            }

            case 2: {
                bool backToMain = false;

                while (!backToMain) {
                    displayHeader();
                    cout << "|            MENU ADMIN JURNALIS              |\n";
                    cout << "+===============================================+\n";
                    cout << "| Pilihan:                                     |\n";
                    cout << "| 1. Masuk ke menu admin jurnalis              |\n";
                    cout << "| 2. Reset data jurnalis admin                 |\n";
                    cout << "| 3. Kembali ke menu utama                     |\n";
                    cout << "+===============================================+\n";

                    int subPilihan;
                    string input;

                    while (true) {
                        cout << "Pilihan (1-3): ";
                        getline(cin, input);

                        if (input.empty() || !isdigit(input[0])) {
                            cout << "Input harus angka 1-3: ";
                            continue;
                        }

                        subPilihan = stoi(input);
                        if (subPilihan >= 1 && subPilihan <= 3) {
                            break;
                        }
                        cout << "Pilihan harus 1-3: ";
                    }

                    switch (subPilihan) {
                        case 1:
                            system("cls");
                            cout << "\nMEMUAT MENU ADMIN JURNALIS...\n";
                            menuJournalistAdmin(jurnalisAdmin, beritaAdmin);
                            break;

                        case 2:
                            while (jurnalisAdmin.first != nullptr) {
                                deleteJournalistFirst(jurnalisAdmin);
                            }
                            cout << "\n[OK] Data jurnalis admin telah direset!\n";
                            displayFooter();
                            cin.get();
                            break;

                        case 3:
                            backToMain = true;
                            break;
                    }
                }
                break;
            }

            case 3: {
                bool backToMain = false;

                while (!backToMain) {
                    displayHeader();
                    cout << "|                MENU USER                    |\n";
                    cout << "+===============================================+\n";
                    cout << "| Pilihan:                                     |\n";
                    cout << "| 1. Masuk ke menu user                        |\n";
                    cout << "| 2. Reset data user                           |\n";
                    cout << "| 3. Info tentang menu user                    |\n";
                    cout << "| 4. Kembali ke menu utama                     |\n";
                    cout << "+===============================================+\n";

                    int subPilihan;
                    string input;

                    while (true) {
                        cout << "Pilihan (1-4): ";
                        getline(cin, input);

                        if (input.empty() || !isdigit(input[0])) {
                            cout << "Input harus angka 1-4: ";
                            continue;
                        }

                        subPilihan = stoi(input);
                        if (subPilihan >= 1 && subPilihan <= 4) {
                            break;
                        }
                        cout << "Pilihan harus 1-4: ";
                    }

                    switch (subPilihan) {
                        case 1:
                            system("cls");
                            cout << "\nMEMUAT MENU USER...\n";
                            cout << "(Data dummy akan otomatis dimuat)\n";
                            displayFooter();
                            cin.get();
                            menuUser(beritaUser, jurnalisUser);
                            break;

                        case 2:
                            while (beritaUser.first != nullptr) {
                                deleteNewsFirst(beritaUser);
                            }
                            while (jurnalisUser.first != nullptr) {
                                deleteJournalistFirst(jurnalisUser);
                            }
                            cout << "\n[OK] Data user telah direset!\n";
                            cout << "Data dummy akan dimuat ulang saat masuk menu user.\n";
                            displayFooter();
                            cin.get();
                            break;

                        case 3:
                            system("cls");
                            cout << "\n=== INFORMASI MENU USER ===\n";
                            cout << "\nFitur yang tersedia:\n";
                            cout << "1. Data dummy: 5 berita & 5 jurnalis\n";
                            cout << "2. Validasi ID duplikat\n";
                            cout << "3. Pencarian lengkap\n";
                            cout << "4. Statistik sistem\n";
                            cout << "5. Tambah data dengan validasi\n";
                            cout << "6. Update dan hapus data\n";
                            cout << "7. Tampilkan data terbaru/terlama\n";
                            cout << "8. Hitung total data\n";
                            cout << "9. Filter berdasarkan kategori/gender\n";
                            cout << "10. Relasi jurnalis-berita (many-to-many)\n";
                            cout << "\nMenu user dirancang untuk study case\n";
                            cout << "dengan validasi input yang lengkap.\n";
                            displayFooter();
                            cin.get();
                            break;

                        case 4:
                            backToMain = true;
                            break;
                    }
                }
                break;
            }

            case 4:
                displayHeader();
                cout << "|                KELUAR PROGRAM                 |\n";
                cout << "+===============================================+\n";
                cout << "|  Terima kasih telah menggunakan program!     |\n";
                cout << "|                                              |\n";
                cout << "\nProgram selesai. Tekan Enter untuk keluar...";
                cin.get();
                break;
        }
    }

    return 0;
}
