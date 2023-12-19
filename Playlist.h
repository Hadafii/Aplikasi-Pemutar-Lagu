#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <string>
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define lagu(P) (P)->lagu
#define dataLagu(P) (P)->dataLagu
#define first(L) L.first
#define last(L) L.last
#define head(Q) Q.head
#define tail(Q) Q.tail
using namespace std;

typedef struct elemenPlaylist *adr_playlist;
typedef struct elemenLagu *adr_lagu;
typedef struct elemenRelation *adr_relation;
typedef struct elemenQueue *adr_Queue;

struct infotype_playlist
{
    string namaPlaylist;
    string creator;
    int likes;
    int jumlahLagu;
};

struct infotype_lagu
{
    string judul;
    string artist;
    string durasi;
    string album;
};

struct ListRelation
{
    adr_relation first;
    adr_relation last;
};
struct elemenPlaylist
{
    infotype_playlist info;
    adr_playlist next;
    adr_playlist prev;
    ListRelation lagu;
};

struct elemenLagu
{
    infotype_lagu info;
    adr_lagu next;
    adr_lagu prev;
};

struct elemenRelation
{
    adr_lagu dataLagu;
    adr_relation next;
    adr_relation prev;
};

struct elemenQueue
{
    infotype_lagu info;
    adr_Queue next;
};

struct listPlaylist
{
    adr_playlist first;
    adr_playlist last;
};

struct listLagu
{
    adr_lagu first;
    adr_lagu last;
};

struct ListQueue
{
    adr_Queue head;
    adr_Queue tail;
};

void createListPlaylist(listPlaylist &LP);
void createListLagu(listLagu &LL);
void createListQueue(ListQueue &LQ);
void createListRelation(ListRelation &LR);
adr_playlist createElemenLP(infotype_playlist infoLP);
adr_lagu createElemenLL(infotype_lagu infoLL);
adr_Queue createElemenLQ(infotype_lagu infoLQ);
adr_relation createElemenLR(adr_lagu infoLR);
bool isEmptyPlaylist(listPlaylist LP);
bool isEmptyLagu(listLagu LL);
bool isEmptyQueue(ListQueue LQ);
bool isEmptyRelation(ListRelation LR);
void insertFirstPlaylist(listPlaylist &LP, adr_playlist P);
void insertAfterPlaylist(listPlaylist &LP, adr_playlist Prec, adr_playlist P);
void insertLastPlaylist(listPlaylist &LP, adr_playlist P);
void insertFirstLagu(listLagu &LL, adr_lagu P);
void insertAfterLagu(listLagu &LL, adr_lagu Prec, adr_lagu P);
void insertLastLagu(listLagu &LL, adr_lagu P);
void insertFirstRelation(ListRelation &LR, adr_relation P);
void insertAfterRelation(ListRelation &LR, adr_relation Prec, adr_relation P);
void insertLastRelation(ListRelation &LR, adr_relation P);
void enqueue(ListQueue &LQ, adr_Queue P);
void dequeue(ListQueue &LQ, adr_Queue &P);
void deleteFirstPlaylist(listPlaylist &LP, adr_playlist &P);
void deleteAfterPlaylist(listPlaylist &LP, adr_playlist Prec, adr_playlist &P);
void deleteLastPlaylist(listPlaylist &LP, adr_playlist &P);
void deleteFirstLagu(listLagu &LL, adr_lagu &P);
void deleteAfterLagu(listLagu &LL, adr_lagu Prec, adr_lagu &P);
void deleteLastLagu(listLagu &LL, adr_lagu &P);
void deleteFirstRelation(ListRelation &LR, adr_relation &P);
void deleteAfterRelation(ListRelation &LR, adr_relation Prec, adr_relation &P);
void deleteLastRelation(ListRelation &LR, adr_relation &P);
void showPlaylist(listPlaylist LP);
void showListLagu(listLagu LL);
void showAntrianLagu(ListQueue LQ);
void showIsiPlaylist(listPlaylist LP, string Nama_Playlist);
void showRelasiLagu(listPlaylist LL, string judul_lagu);
void showSameTitle(listLagu LL, string judul_lagu);
int jumlahPlaylist(listPlaylist LP);
int jumlahListLagu(listLagu LL);
int jumlahAntrian(ListQueue LQ);
int jumlahLaguPL(listPlaylist LP, string Nama_Playlist);

// BAGIAN MENU APLIKASI (LP, LL, LR, LQ) // BAGIAN MENU APLIKASI (LP, LL, LR, LQ) //
void menuUtama(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void menuInput(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void inputPlaylist(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void inputLagu(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void inputRelasi(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void menuDelete(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void menuDeletePlaylist(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void likePlaylist(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void menuDeleteLagu(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void menuDeleteRelasi(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void menuSearch(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void menuSearchPlaylist(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void menuSearchLagu(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void menuShowData(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
adr_playlist searchPlaylist(listPlaylist LP, string namaPlaylist);
adr_lagu searchLagu(listLagu LL, string judulLagu, string penyanyi);
adr_relation searchRelation(listPlaylist LP, string judulLagu, string namaPlaylist);
adr_playlist searchPlaylistByCreator(listPlaylist LP, string creatorName);
// VOID ANTRIAN LAGU BELUM
void menuQueue(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void menuTampilkanQueue(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void clearQueue(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void playSongs(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void songToQueue(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void changePriority(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
// menu ubah
void menuUbah(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void ubahPlaylist(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void ubahLagu(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void ubahRelasi(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
void DeveloperMode(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ);
#endif // PLAYLIST_H_INCLUDED