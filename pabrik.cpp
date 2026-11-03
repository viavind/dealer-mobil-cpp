#include "pabrik.h"
#include "produk.h"
#include "relasi.h"

void createListPabrik(List_pabrik &L){
    first(L) = nullptr;
    last(L) = nullptr;
}

adr_pabrik createElmPabrik(string kode, string lokasi, int produksi){
    adr_pabrik P = new elm_pabrik;
    info(P).KodePabrik = kode;
    info(P).Lokasi = lokasi;
    info(P).Produksi = produksi;
    createListRelasi(produk(P));
    next(P) = nullptr;
    prev(P) = nullptr;
    return P;
}

void dealokasi(adr_pabrik &P){
    if (P != nullptr) {
        next(P) = nullptr;
        prev(P) = nullptr;
        delete P;
    }
}

void insertLastPabrik(List_pabrik &L, adr_pabrik P){
    if ((first(L) == nullptr) && (last(L) == nullptr)){
        first(L) = P;
        last(L) = P;
        next(P) = P;
        prev(P) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void editPabrikan(List_pabrik &L, string kode, string newKode, string newLokasi, int Produksi) {
    adr_pabrik P = findElmPabrik(L, kode);
    if (P != nullptr) {
        info(P).KodePabrik = newKode;
        info(P).Lokasi = newLokasi;
        info(P).Produksi += Produksi;
        cout << "Data Pabrik Berhasil Diubah." << endl;
    } else {
        cout << "Pabrik Dengan Kode " << kode << " Tidak Ditemukan." << endl;
    }
}

void deleteFirstPabrik(List_pabrik &L, adr_pabrik &P){
    if(first(L)!= nullptr){
        P = first(L);
        if(next(first(L)) == first(L)){
            first(L) = nullptr;
            last(L) = nullptr;
        } else {
            first(L) = next(P);
            next(last(L)) = first(L);
            prev(next(P)) = last(L);
            dealokasi(P);
        }
    } else {
        cout << "List Pabrik Tidak Mengandung Elemen" << endl;
    }
}

void deleteLastPabrik(List_pabrik &L, adr_pabrik &P){
    adr_pabrik Q;
    if(first(L)!= nullptr){
        if(next(first(L))== nullptr){
            first(L) = nullptr;
            last(L) = nullptr;
        } else {
            P = last(L);
            Q = prev(P);
            next(Q) = first(L);
            prev(first(L)) = Q;
            last(L) = Q;
            dealokasi(P);
        }
    } else {
        cout << "List Pabrik Tidak Mengandung Elemen" << endl;
    }
}

void deleteAfterPabrik(List_pabrik &L, adr_pabrik &P){
    adr_pabrik Prec;

    Prec = prev(P);
    if(first(L)!= nullptr){
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        dealokasi(P);
    }
}


adr_pabrik findElmPabrik(List_pabrik L, string kode){
    adr_pabrik P, Q;
    Q = nullptr;
    if ((first(L) == nullptr) && (last(L) == nullptr)){
        Q = nullptr;
    } else {
        P = first(L);
        do {
            if (info(P).KodePabrik == kode) {
                Q = P;
            }
            P = next(P);
        } while (P != first(L));
    }
    return Q;
}

void printInfoPabrik(List_pabrik LP){
    adr_pabrik P = first(LP);

    if (P == nullptr) {
        cout << "Pabrik List Kosong." << endl;
    } else {
        cout << "List Pabrik" << endl;
        do {
            printInfoRelasibyPabrik(LP, info(P).KodePabrik);
            cout << " " << endl;
            P = next(P);
        } while (P != first(LP));
    }
}

void showAllPabrik(List_pabrik &L){
    adr_pabrik P = first(L);

    if (P == nullptr){
        cout << "Pabrik List Kosong" << endl;
    } else {
        do {
            cout << "|| Pabrik " << info(P).KodePabrik << " || " << endl;
            cout << "Berlokasi Di " << info(P).Lokasi << " Telah Memproduksi Sebanyak " << info(P).Produksi << " Mobil." << endl;
            cout << " " << endl;
            P = next(P);
        } while (P != first(L));

    }

}


void findElmRelasi(List_pabrik &LP, List_produk LPR, adr_produk PR, adr_pabrik P){
    adr_relasi temp = first(produk(P));
    while (temp != nullptr){
        if ( info(temp) == PR){
            if (temp == first(produk(P))){
                deleteFirstRelasi(produk(P), temp);
            } else if (next(temp) == nullptr){
                deleteLastRelasi(produk(P), temp);
            } else {
                adr_relasi prec = first(produk(P));
                while (next(prec) != temp){
                    temp = next(prec);
                }
                deleteAfterRelasi(produk(P), prec, temp);
            }
        }
        temp = next(temp);
    }
}

void printInfoRelasibyPabrik(List_pabrik &LP, string kode){
    adr_pabrik P = first(LP);
    adr_relasi R;

    if (first(produk(P)) == nullptr){
        cout << "Kode Pabrik : " << info(P).KodePabrik << ", Lokasi : " << info(P).Lokasi << ", Produksi : " << info(P).Produksi << endl;
        cout << "Saat Ini Pabrik Tidak Memproduksi Mobil" << endl;
    } else {
        do{
            if (info(P).KodePabrik == kode){
                R = first(produk(P));
                cout << "Kode Pabrik : " << info(P).KodePabrik << ", Lokasi : " << info(P).Lokasi << ", Produksi : " << info(P).Produksi << endl;
                while (R != nullptr){
                    cout << "Memproduksi Mobil Tipe " << info(info(R)).TypeMobil << endl;
                    R = next(R);
                }
            }
            P = next(P);
        } while (P != first(LP));
    }
}


void produksiPabrikan(List_pabrik &LP, List_produk &LPR, string kode, string type, int produksi) {
    adr_pabrik P = findElmPabrik(LP, kode);

    if (P != nullptr) {
        info(P).Produksi += produksi;
    }

    adr_produk PR = findElmProduk(LPR, type);

    if (PR != nullptr) {
        info(PR).Terjual += produksi;
    }

    adr_relasi Relasi = createElmRelasi(PR);

    adr_relasi R = first(produk(P));

    if (R == nullptr) {
        first(produk(P)) = Relasi;
    } else {
        while (next(R) != nullptr) {
            R = next(R);
        }
        next(R) = Relasi;
    }
}

void editProduksiPabrikan(List_pabrik &LP, List_produk &LPR, string type, string newtype, string kode, int produksi){
    adr_pabrik P = findElmPabrik(LP, kode);
    if (P != nullptr){
        info(P).Produksi = info(P).Produksi + produksi;
    }

    adr_produk PR = findElmProduk(LPR, type);
        if (PR != nullptr){
        info(PR).Terjual = info(PR).Terjual + produksi;
    }

    if (P != nullptr && PR != nullptr){
        adr_relasi R = first(produk(P));
        while (R != nullptr){
            if (info(info(R)).TypeMobil == type){
                info(info(R)).TypeMobil = newtype;
            }
            R = next(R);
        }

    }
}

void MaxProduksi (List_pabrik L){
    if (first(L) == NULL) {
        cout << "List Kosong.\n";
        return;
    }

    adr_pabrik P = first(L);
    int maxProduksi = info(P).Produksi;
    adr_pabrik maxPabrik = P;

    do {
        if (info(P).Produksi > maxProduksi) {
            maxProduksi = info(P).Produksi;
            maxPabrik = P;
        }
        P = next(P);
    } while (P != first(L));

    cout << "Pabrik Dengan Produksi Terbanyak: Pabrik " << info(maxPabrik).KodePabrik << endl;

    cout << " " << endl;
    printInfoRelasibyPabrik(L, info(maxPabrik).KodePabrik);
}

void display(){
    cout << "======================================================" << endl;
    cout << "====                Dealer Mobil                  ====" << endl;
    cout << "====              by Via & Celenie                ====" << endl;
    cout << "======================================================" << endl;
}

void menu(){
    cout << "======================================================" << endl;
    cout << "                          MENU                        " << endl;
    cout << "1. Input Data Pabrik" << endl;
    cout << "2. Input Data Mobil" << endl;
    cout << "3. Hapus Pabrikan" << endl;
    cout << "4. Hapus Mobil" << endl;
    cout << "5. Edit Pabrikan" << endl;
    cout << "6. Tambahkan Produksi Pabrikan" << endl;
    cout << "7. Ubah Produksi Pabrikan" << endl;
    cout << "8. Hapus Produksi Pabrikan" << endl;
    cout << "9. Tampilkan Pabrikan dengan produksi terbanyak" << endl;
    cout << "10. Tampilkan Tipe Mobil Dengan Penjualan Tertinggi" << endl;
    cout << "11. Tampilkan Data Pabrikan dan Data Mobil" << endl;
    cout << "12. Kunjungi Pabrik Tertentu" << endl;
    cout << "0. Keluar" << endl;
    cout << "======================================================" << endl;
}
