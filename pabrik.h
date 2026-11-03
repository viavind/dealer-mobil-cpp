#ifndef PABRIK_H_INCLUDED
#define PABRIK_H_INCLUDED

#include <iostream>

#include "relasi.h"

using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define info(P) P->info
#define produk(P) P->produk

//CDLL
// Define adr_pabrik as a pointer to elm_pabrik
typedef struct elm_pabrik* adr_pabrik;

// Define infotype_pabrik
struct infotype_pabrik {
    string KodePabrik;
    string Lokasi;
    int Produksi;
};

// Define elm_pabrik
struct elm_pabrik {
    infotype_pabrik info;
    adr_pabrik next;
    adr_pabrik prev;
    List_relasi produk;
};

struct List_pabrik {
    adr_pabrik first;
    adr_pabrik last;
};


void createListPabrik(List_pabrik &L);
adr_pabrik createElmPabrik(string kode, string lokasi, int produksi);
void dealokasi(adr_pabrik &P);
void insertLastPabrik(List_pabrik &L, adr_pabrik P);
void editPabrikan(List_pabrik &L, string kode, string newKode, string newLokasi, int Produksi);
void deleteFirstPabrik(List_pabrik &L, adr_pabrik &P);
void deleteLastPabrik(List_pabrik &L, adr_pabrik &P);
void deleteAfterPabrik(List_pabrik &L, adr_pabrik &P);

adr_pabrik findElmPabrik(List_pabrik L, string kode);
void printInfoPabrik(List_pabrik L);
void showAllPabrik(List_pabrik &L);

void findElmRelasi(List_pabrik &LP, List_produk LPR, adr_produk PR, adr_pabrik P);
void printInfoRelasibyPabrik(List_pabrik &LP, string kode);

void produksiPabrikan(List_pabrik &LP, List_produk &LPR, string kode, string type, int produksi);
void editProduksiPabrikan(List_pabrik &LP, List_produk &LPR, string type, string newtype, string kode, int produksi);
void MaxProduksi(List_pabrik L);

void display();
void menu();

#endif // PABRIK_H_INCLUDED
