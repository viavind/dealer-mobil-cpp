#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "pabrik.h"
#include "produk.h"

#include <iostream>

using namespace std;

#define next(P) P->next
#define first(L) L.first
#define info(P) P->info

// Define adr_relasi as a pointer to elm_relasi
typedef struct elm_relasi* adr_relasi;

//SLL
// Define elm_relasi
struct elm_relasi {
    adr_relasi next;
    adr_produk info;
};

struct List_relasi {
    adr_relasi first;
};

void createListRelasi(List_relasi &L);
adr_relasi createElmRelasi(adr_produk C);
void deleteFirstRelasi(List_relasi &L, adr_relasi &P);
void deleteLastRelasi(List_relasi &L, adr_relasi &P);
void deleteAfterRelasi(List_relasi &L, adr_relasi Prec, adr_relasi &P);

#endif // RELASI_H_INCLUDED
