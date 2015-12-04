#ifndef STUDIO_H_INCLUDED
#define STUDIO_H_INCLUDED
#define nil NULL
#include <iostream>
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define film(P) P->film
#define jadwal(P) P->jadwal
#define last(L) L.last
using namespace std;
struct hours{
    int hour;
    int minute;
};
struct infostudio
{
   string id_studio, nama_studio;
};
struct infojadwal
{
    string id_jadwal;
    string hari;
    hours jam;
    int k[];
};

typedef infostudio infotype;
typedef struct elmstudio *address_s;
typedef struct elmjadwal *address_j;
typedef struct elmfilm *address_f;
typedef char infotypefilm;

struct elmjadwal
{
    infojadwal info;
    address_j next;
    address_j prev;
};
struct list_j
{
    address_j first;
    address_j last;
};
struct elmstudio
{
    infotype info;
    address_s next;
    address_f film;
    list_j jadwal;
};

struct list_s
{
    address_s first;
};

void create_list_studio(list_s &L);
address_s alokasistudio(infotype x);
void insfirststudio(list_s &L, address_s P);
void insafterstudio(list_s &L, address_s P, address_s Prec);
void inslaststudio(list_s &L, address_s P);
void printstudio (list_s L);
void delfirststudio(list_s &L, address_s &P);
void delafterstudio(list_s &L, address_s &P, address_s Prec);
void dellaststudio(list_s &L, address_s &P);
address_s findstudio(list_s L, string x);
void editstudio (list_s &L,address_s &J);
void create_list(list_j &J);
address_j alokasijadwal(infojadwal x);
void barujadwal (infojadwal &x);
void insertfirstjadwal(list_j &L, address_j J);
void insertlastjadwal(list_j &L, address_j J);
void insertafterjadwal(list_j &L, address_j P, address_j Prec);
void printjadwal(list_j L);
void delfirstjadwal(list_j &L, address_j &PJ);
void dellastjadwal(list_j &P,address_j &PJ);
void delafterjadwal(list_j &L,address_j &PJ,address_j Prec);
address_j findjadwal(list_j &L, string Es);
void editjadwal (list_j &L,address_j &J);
void sortingstudio_asc(list_s &L);
void sortingjadwalid(list_j &L);
void sortingjadwaljam(list_j &L);
#endif // STUDIO_H_INCLUDED
