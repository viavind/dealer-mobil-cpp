#include <iostream>
#include "pabrik.h"
#include "produk.h"
#include "relasi.h"

using namespace std;

int main()
{
    List_pabrik LP;
    List_produk LPR;

    createListPabrik(LP);
    createListProduk(LPR);

    adr_pabrik P, precP;
    adr_produk PR, precPR;
    adr_relasi R, precR;

    adr_pabrik elm1 = createElmPabrik("HND001", "Jakarta", 0);
    adr_pabrik elm2 = createElmPabrik("HND002", "Bandung", 0);
    adr_pabrik elm3 = createElmPabrik("HND003", "Bekasi", 0);
    adr_pabrik elm4 = createElmPabrik("HND004", "Banten", 0);
    adr_pabrik elm5 = createElmPabrik("HND005", "Jogjakarta", 0);

    insertLastPabrik(LP, elm1);
    insertLastPabrik(LP, elm2);
    insertLastPabrik(LP, elm3);
    insertLastPabrik(LP, elm4);
    insertLastPabrik(LP, elm5);

    adr_produk elmP1 = createElmProduk("SUV", 0);
    adr_produk elmP2 = createElmProduk("MPV", 0);
    adr_produk elmP3 = createElmProduk("Crossover", 0);
    adr_produk elmP4 = createElmProduk("LCGC", 0);
    adr_produk elmP5 = createElmProduk("Jazz", 0);

    insertLastProduk(LPR, elmP1);
    insertLastProduk(LPR, elmP2);
    insertLastProduk(LPR, elmP3);
    insertLastProduk(LPR, elmP4);
    insertLastProduk(LPR, elmP5);

    string pilih, kode, lokasi, type, newtype, newkode, newlokasi;
    int produksi, x;

    display();
    menu();
    cout << "Masukkan Opsi Angka yang Ingin Dipilih : ";
    cin >> pilih;

    while (pilih != "0"){
        if (pilih == "1"){
            cout << " " << endl;
            cout << "Jumlah Pabrik yang Akan Ditambahkan :  ";
            cin >> x;
            cout << "Kode Pabrik Berisi 3 Abjad Inisial Brand dan 3 Angka Unik (XXX123)" << endl;
            for (int i = 1; i <= x; i++){
                cout << "Masukkan Kode Pabrik " << i << " : ";
                cin >> kode;
                cout << "Masukkan Lokasi Pabrik " << i << " : ";
                cin >> lokasi;
                cout << "Masukkan Total Produksi Pabrik " << i << " : ";
                cin >> produksi;
                cout << " " << endl;

                P = findElmPabrik(LP, kode);
                if (P != nullptr){
                    cout << "Pabrik Dengan Kode " << info(P).KodePabrik << " Telah Tersedia" << endl;
                } else {
                    adr_pabrik newPabrik = createElmPabrik(kode, lokasi, produksi);
                    insertLastPabrik(LP, newPabrik);
                }
            }
            showAllPabrik(LP);
            cout << " " << endl;

        } else if (pilih == "2"){
            cout << " " << endl;
            cout << "Jumlah Tipe Mobil yang Akan Dimasukan : ";
            cin >> x;
            for (int i = 1; i <= x; i++){
                cout << "Masukkan Tipe Mobil " << i << " : ";
                cin >> type;
                cout << "Masukkan Jumlah Terjual " << i << " : ";
                cin >> produksi;
                cout << " " << endl;

                PR = findElmProduk(LPR, type);
                if (PR != nullptr){
                    cout << "Mobil Dengan Tipe " << info(PR).TypeMobil << " Telah Tersedia" << endl;
                } else {
                    adr_produk newProduk = createElmProduk(type, produksi);
                    insertLastProduk(LPR, newProduk);
                }
            }
            cout << " " << endl;
            printInfoProduk(LPR);
            cout << " " << endl;

        } else if (pilih == "3"){
            cout << " " << endl;
            showAllPabrik(LP);
            cout << " " << endl;

            cout << "Masukan Kode Pabrik yang Akan Dihapus : ";
            cin >> kode;

            P = findElmPabrik(LP, kode);

            if (P == first(LP)){
                deleteFirstPabrik(LP, P);
            } else if (P == last(LP)){
                deleteLastPabrik(LP, P);
            } else {
                deleteAfterPabrik(LP, P);
            }

            cout << " " << endl;
            showAllPabrik(LP);
            cout << " " << endl;

        } else if (pilih == "4") {
            cout << " " << endl;
            printInfoProduk(LPR);
            cout << " " << endl;

            cout << "Masukan Tipe Mobil yang Akan Dihapus : ";
            cin >> type;

            PR = findElmProduk(LPR, type);
            if (PR == first(LPR)){
                deleteFirstProduk(LPR, PR);
            } else if (PR == last(LPR)){
                deleteLastProduk(LPR, PR);
            } else {
                deleteAfterProduk(LPR, PR);
            }

            cout << " " << endl;
            printInfoProduk(LPR);
            cout << " " << endl;

        } else if (pilih == "5") {
            cout << " " << endl;
            showAllPabrik(LP);
            cout << " " << endl;

            cout << "Masukan Kode Pabrik yang Akan Diubah : ";
            cin >> kode;
            cout << "Masukan Kode Baru Pabrikan : ";
            cin >> newkode;
            cout << "Masukan Lokasi Baru Pabrikan : ";
            cin >> newlokasi;
            cout << "Apakah Ada Tambahan Produksi? (Jika Tidak Maka Ketik 0) : ";
            cin >> produksi;

            cout << " " << endl;
            editPabrikan(LP, kode, newkode, newlokasi, produksi);
            cout << " " << endl;

            showAllPabrik(LP);
            cout << " " << endl;

        } else if (pilih == "6") {
            cout << " " << endl;
            showAllPabrik(LP);

            cout << "Masukkan Kode Pabrik yang Akan Ditambah Produksinya : ";
            cin >> kode;

            cout << " " << endl;
            printInfoRelasibyPabrik(LP, kode);
            cout << " " << endl;

            printInfoProduk(LPR);
            cout << " " << endl;

            cout << "Masukkan Tipe Mobil yang Akan Diproduksi : ";
            cin >> type;

            cout << "Masukkan Jumlah Mobil yang Akan Diproduksi : ";
            cin >> produksi;

            adr_produk tipe = findElmProduk(LPR, type);

            if (tipe != nullptr) {
                produksiPabrikan(LP, LPR, kode, type, produksi);
            } else {
                adr_produk newProduk = createElmProduk(type, 0);
                insertLastProduk(LPR, newProduk);
                produksiPabrikan(LP, LPR, kode, type, produksi);
            }

            cout << " " << endl;
            printInfoRelasibyPabrik(LP, kode);
            cout << " " << endl;

        } else if (pilih == "7") {
            cout << " " << endl;
            printInfoPabrik(LP);
            cout << " " << endl;

            cout << "Masukan kode pabrik yang akan diubah produksinya : ";
            cin >> kode;
            cout << " " << endl;

            printInfoRelasibyPabrik(LP, kode);
            cout << " " << endl;

            cout << "Tipe Mobil yang Akan Berhenti Diproduksi : ";
            cin >> type;
            cout << " " << endl;

            printInfoProduk(LPR);
            cout << " " << endl;

            cout << "Tipe Mobil yang Akan Diproduksi : ";
            cin >> newtype;
            cout << "Jumlah Mobil yang Akan Produksi : ";
            cin >> produksi;

            PR = findElmProduk(LPR, type);
            P = findElmPabrik(LP, kode);
            adr_produk newProduk = findElmProduk(LPR, newtype);

            if (newProduk == nullptr){
                newProduk = createElmProduk(newtype, 0);
                insertLastProduk(LPR, newProduk);
                produksiPabrikan(LP, LPR, kode, newtype, produksi);
                findElmRelasi(LP, LPR, PR, P);
            } else {
                produksiPabrikan(LP, LPR, kode, newtype, produksi);
                findElmRelasi(LP, LPR, PR, P);
            }

            cout << " " << endl;
            printInfoRelasibyPabrik(LP, kode);
            cout << " " << endl;

        } else if (pilih == "8") {
            cout << " " << endl;
            printInfoPabrik(LP);

            cout << "Masukan kode pabrik yang akan diubah produksinya : ";
            cin >> kode;

            cout << " " << endl;
            printInfoRelasibyPabrik(LP, kode);
            cout << " " << endl;

            cout << "Tipe mobil yang akan berhenti diproduksi : ";
            cin >> type;

            PR = findElmProduk(LPR, type);
            P = findElmPabrik(LP, kode);

            findElmRelasi(LP, LPR, PR, P);

            cout << " " << endl;
            printInfoPabrik(LP);

        } else if (pilih == "9") {
            cout << " " << endl;
            MaxProduksi(LP);

        } else if (pilih == "10"){
            cout << " " << endl;
            MaxTerjual(LPR);
            cout << " " << endl;

        } else if (pilih == "11"){
            cout << " " << endl;
            showAllPabrik(LP);

            printInfoProduk(LPR);
            cout << " " << endl;

        } else if (pilih == "12"){
            cout << " " << endl;
            showAllPabrik(LP);
            cout << " " << endl;

            cout << "Masukan Kode Pabrik yang Akan Dikunjungi : ";
            cin >> kode;

            cout << " " << endl;
            printInfoRelasibyPabrik(LP, kode);
        }
        menu();
        cout << "Masukkan Opsi Angka yang Ingin Dipilih : ";
        cin >> pilih;
    }
    return 0;
}



