#include "pabrik.h"
#include "produk.h"
#include "relasi.h"

void createListRelasi(List_relasi &L){
    first(L) = nullptr;
}

adr_relasi createElmRelasi(adr_produk C){
    adr_relasi P = new elm_relasi;
    info(P) = C;
    next(P) = nullptr;
    return P;
}

void deleteFirstRelasi(List_relasi &L, adr_relasi &P){
    if(first(L)!= nullptr){
        P = first(L);
        if(next(first(L)) == nullptr){
            first(L) = nullptr;
        } else {
            first(L) = next(P);
            next(P) = nullptr;
        }
    } else {
        cout << "Pabrik Tidak Memiliki Relasi" << endl;
    }
}

void deleteLastRelasi(List_relasi &L, adr_relasi &P){
    P = first(L);
    if (P != nullptr) {
        if (next(P) == nullptr) {
            first(L) = nullptr;
        } else {
            adr_relasi Q = first(L);
            while (next(next(Q)) != nullptr) {
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = nullptr;
        }
    } else {
        cout << "Pabrik Tidak Memiliki Relasi" << endl;
    }
}

void deleteAfterRelasi(List_relasi &L, adr_relasi Prec, adr_relasi &P){
    if (first(L) != nullptr) {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = nullptr;
    }
}
