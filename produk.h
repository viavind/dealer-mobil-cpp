#ifndef PRODUK_H_INCLUDED
#define PRODUK_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

// Define adr_produk as a pointer to elm_produk
typedef struct elm_produk* adr_produk;

// Define infotype_produk
struct infotype_produk {
    string TypeMobil;
    int Terjual;
};

// Define elm_produk
struct elm_produk {
    infotype_produk info;
    adr_produk next;
    adr_produk prev;
};

struct List_produk {
    adr_produk first;
    adr_produk last;
};

void createListProduk(List_produk &L);
adr_produk createElmProduk(string type, int penjualan);
void dealokasi(adr_produk &P);
void insertLastProduk(List_produk &L, adr_produk P);
void deleteFirstProduk(List_produk &L, adr_produk &P);
void deleteLastProduk(List_produk &L, adr_produk &P);
void deleteAfterProduk(List_produk &L, adr_produk &P);

adr_produk findElmProduk(List_produk L, string type);
void printInfoProduk(List_produk L);

void MaxTerjual(List_produk L);

#endif // PRODUK_H_INCLUDED
