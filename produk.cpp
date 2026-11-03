#include "pabrik.h"
#include "produk.h"
#include "relasi.h"

void createListProduk(List_produk &L){
    first(L) = nullptr;
    last(L) = nullptr;
}

adr_produk createElmProduk(string type, int penjualan){
    adr_produk P = new elm_produk;
    info(P).TypeMobil = type;
    info(P).Terjual = penjualan;
    next(P) = nullptr;
    prev(P) = nullptr;
    return P;
}

void dealokasi(adr_produk &P){
    if (P != nullptr) {
        next(P) = nullptr;
        prev(P) = nullptr;
        delete P;
    }
}

void insertLastProduk(List_produk &L, adr_produk P){
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

void deleteFirstProduk(List_produk &L, adr_produk &P){
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
        cout << "List Produk Kosong" << endl;
    }
}

void deleteLastProduk(List_produk &L, adr_produk &P){
    adr_produk Q;
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
        cout << "List Produk Kosong" << endl;
    }
}

void deleteAfterProduk(List_produk &L, adr_produk &P){
    adr_produk Prec = prev(P);
    if(first(L)!= nullptr){
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        dealokasi(P);
    }
}


adr_produk findElmProduk(List_produk L, string type){
    adr_produk P, Q;
    Q = nullptr;
    if ((first(L) == nullptr) && (last(L) == nullptr)){
        Q = nullptr;
    } else {
        P = first(L);
        do {
            if (info(P).TypeMobil == type) {
                Q = P;
            }
            P = next(P);
        } while (P != first(L));
    }
    return Q;
}

void printInfoProduk(List_produk L){
    adr_produk P = first(L);

    if (P == nullptr) {
        cout << "List Produk Kosong." << endl;
    } else {
        cout << "List Produk" << endl;
        do {
            cout << "Type Mobil : " << info(P).TypeMobil << ", Terjual : " << info(P).Terjual << endl;
            P = next(P);
        } while (P != first(L));
    }
}


void MaxTerjual(List_produk L) {
    if (first(L) == nullptr) {
        cout << "List Kosong.\n";
        return;
    }

    adr_produk P = first(L);
    int maxTerjual = info(P).Terjual;
    adr_produk maxProduk = P;

    do {
        if (info(P).Terjual > maxTerjual) {
            maxTerjual = info(P).Terjual;
            maxProduk = P;
        }
        P = next(P);
    } while (P != first(L));

    cout << "Type Mobil yang Paling Banyak Terjual : Mobil Tipe " << info(maxProduk).TypeMobil << endl;
    cout << "Telah Terjual Sebanyak " << info(maxProduk).Terjual << " Mobil." << endl;
}
