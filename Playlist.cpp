#include "Playlist.h"

void createListPlaylist(listPlaylist &LP)
{
    first(LP) = NULL;
    last(LP) = NULL;
}
void createListLagu(listLagu &LL)
{
    first(LL) = NULL;
    last(LL) = NULL;
}
void createListQueue(ListQueue &LQ)
{
    head(LQ) = NULL;
    tail(LQ) = NULL;
}

void createListRelation(ListRelation &LR)
{
    first(LR) = NULL;
    last(LR) = NULL;
}
adr_playlist createElemenLP(infotype_playlist infoLP)
{
    adr_playlist newLP = new elemenPlaylist;
    info(newLP) = infoLP;
    next(newLP) = NULL;
    prev(newLP) = NULL;
    createListRelation(lagu(newLP));
    return newLP;
}
adr_lagu createElemenLL(infotype_lagu infoLL)
{
    adr_lagu newLL = new elemenLagu;
    info(newLL) = infoLL;
    next(newLL) = NULL;
    prev(newLL) = NULL;
    return newLL;
}
adr_Queue createElemenLQ(infotype_lagu infoLQ)
{
    adr_Queue newLQ = new elemenQueue;
    info(newLQ) = infoLQ;
    next(newLQ) = NULL;
    return newLQ;
}
adr_relation createElemenLR(adr_lagu infoLR)
{
    adr_relation newLR = new elemenRelation;
    dataLagu(newLR) = infoLR;
    next(newLR) = NULL;
    prev(newLR) = NULL;
    return newLR;
}
bool isEmptyPlaylist(listPlaylist LP)
{
    return first(LP) == NULL;
}
bool isEmptyLagu(listLagu LL)
{
    return first(LL) == NULL;
}
bool isEmptyQueue(ListQueue LQ)
{
    return head(LQ) == NULL;
}
bool isEmptyRelation(ListRelation LR)
{
    return first(LR) == NULL;
}
void insertFirstPlaylist(listPlaylist &LP, adr_playlist P)
{
    if (isEmptyPlaylist(LP))
    {
        first(LP) = P;
        last(LP) = P;
    }
    else
    {
        next(P) = first(LP);
        prev(first(LP)) = P;
        first(LP) = P;
    }
}
void insertAfterPlaylist(listPlaylist &LP, adr_playlist Prec, adr_playlist P)
{
    if (Prec != NULL)
    {
        if (next(Prec) == NULL)
        {
            insertLastPlaylist(LP, P);
        }
        else
        {
            next(P) = next(Prec);
            prev(P) = Prec;
            prev(next(P)) = P;
            next(Prec) = P;
        }
    }
    else
    {
        insertFirstPlaylist(LP, P);
    }
}
void insertLastPlaylist(listPlaylist &LP, adr_playlist P)
{
    if (isEmptyPlaylist(LP))
    {
        first(LP) = P;
        last(LP) = P;
    }
    else
    {
        next(last(LP)) = P;
        prev(P) = last(LP);
        last(LP) = P;
    }
}
void insertFirstLagu(listLagu &LL, adr_lagu P)
{
    if (isEmptyLagu(LL))
    {
        first(LL) = P;
        last(LL) = P;
    }
    else
    {
        next(P) = first(LL);
        prev(first(LL)) = P;
        first(LL) = P;
    }
}
void insertAfterLagu(listLagu &LL, adr_lagu Prec, adr_lagu P)
{
    if (Prec != NULL)
    {
        if (next(Prec) == NULL)
        {
            insertLastLagu(LL, P);
        }
        else
        {
            next(P) = next(Prec);
            prev(P) = Prec;
            prev(next(P)) = P;
            next(Prec) = P;
        }
    }
    else
    {
        insertFirstLagu(LL, P);
    }
}
void insertLastLagu(listLagu &LL, adr_lagu P)
{
    if (isEmptyLagu(LL))
    {
        first(LL) = P;
        last(LL) = P;
    }
    else
    {
        next(last(LL)) = P;
        prev(P) = last(LL);
        last(LL) = P;
    }
}
void insertFirstRelation(ListRelation &LR, adr_relation P)
{
    if (isEmptyRelation(LR))
    {
        first(LR) = P;
        last(LR) = P;
    }
    else
    {
        next(P) = first(LR);
        prev(first(LR)) = P;
        first(LR) = P;
    }
}
void insertAfterRelation(ListRelation &LR, adr_relation Prec, adr_relation P)
{
    if (Prec != NULL)
    {
        if (next(Prec) == NULL)
        {
            insertLastRelation(LR, P);
        }
        else
        {
            next(P) = next(Prec);
            prev(P) = Prec;
            prev(next(P)) = P;
            next(Prec) = P;
        }
    }
    else
    {
        insertFirstRelation(LR, P);
    }
}
void insertLastRelation(ListRelation &LR, adr_relation P)
{
    if (isEmptyRelation(LR))
    {
        first(LR) = P;
        last(LR) = P;
    }
    else
    {
        prev(P) = last(LR);
        next(last(LR)) = P;
        last(LR) = P;
    }
}
void enqueue(ListQueue &LQ, adr_Queue P)
{
    if (isEmptyQueue(LQ))
    {
        head(LQ) = P;
        tail(LQ) = P;
    }
    else
    {
        next(tail(LQ)) = P;
        tail(LQ) = P;
    }
    next(P) = NULL;
}

void dequeue(ListQueue &LQ, adr_Queue &P)
{
    if (isEmptyQueue(LQ))
    {
        cout << "Maaf Tidak Ada Antrian Lagu yang Dapat Dihapus\n";
        P = NULL;
    }
    else
    {
        P = head(LQ);
        head(LQ) = next(head(LQ));
        if (head(LQ) == NULL)
        {
            tail(LQ) = NULL;
        }
    }
}

void deleteFirstPlaylist(listPlaylist &LP, adr_playlist &P)
{
    if (isEmptyPlaylist(LP))
    {
        cout << "Maaf Tidak Ada Playlist yang Dapat Dihapus\n";
    }
    else
    {
        if (first(LP) == last(LP))
        {
            P = first(LP);
            first(LP) = NULL;
            last(LP) = NULL;
        }
        else
        {
            P = first(LP);
            first(LP) = next(P);
            prev(first(LP)) = NULL;
            next(P) = NULL;
        }
        adr_relation R = lagu(P).first;
        ListRelation RE = lagu(P);
        while (!isEmptyRelation(RE))
        {
            deleteLastRelation(RE, R);
            delete R;
        }
        info(P).jumlahLagu--;
    }
}
void deleteAfterPlaylist(listPlaylist &LP, adr_playlist Prec, adr_playlist &P)
{
    if (isEmptyPlaylist(LP))
    {
        cout << "Maaf Tidak Ada Playlist yang Dapat Dihapus\n";
    }
    else
    {
        if (Prec != NULL)
        {
            P = next(Prec);
            if (P != NULL)
            {
                next(Prec) = next(P);
                if (next(P) != NULL)
                {
                    prev(next(P)) = Prec;
                }
                else
                {
                    last(LP) = Prec;
                }
                next(P) = NULL;
                prev(P) = NULL;
            }
        }
        adr_relation R = lagu(P).first;
        ListRelation RE = lagu(P);
        while (!isEmptyRelation(RE))
        {
            deleteLastRelation(RE, R);
            delete R;
        }
        info(P).jumlahLagu--;
    }
}
void deleteLastPlaylist(listPlaylist &LP, adr_playlist &P)
{
    if (isEmptyPlaylist(LP))
    {
        cout << "Maaf Tidak Ada Playlist yang Dapat Dihapus\n";
    }
    else
    {
        P = last(LP);
        if (first(LP) == last(LP))
        {
            first(LP) = NULL;
            last(LP) = NULL;
        }
        else
        {
            last(LP) = prev(P);
            next(last(LP)) = NULL;
            prev(P) = NULL;
        }
        adr_relation R = lagu(P).first;
        ListRelation RE = lagu(P);
        while (!isEmptyRelation(RE))
        {
            deleteLastRelation(RE, R);
            delete R;
        }
        info(P).jumlahLagu--;
    }
}
void deleteFirstLagu(listLagu &LL, adr_lagu &P)
{
    if (isEmptyLagu(LL))
    {
        cout << "Maaf Tidak Ada List Lagu yang Dapat Dihapus\n";
    }
    else
    {

        if (first(LL) == last(LL))
        {
            first(LL) = NULL;
            last(LL) = NULL;
        }
        else
        {
            P = first(LL);
            first(LL) = next(P);
            prev(first(LL)) = NULL;
            next(P) = NULL;
        }
    }
}
void deleteAfterLagu(listLagu &LL, adr_lagu Prec, adr_lagu &P)
{
    if (isEmptyLagu(LL))
    {
        cout << "Maaf Tidak Ada List Lagu yang Dapat Dihapus\n";
    }
    else
    {
        P = last(LL);
        if (first(LL) == last(LL))
        {
            first(LL) = NULL;
            last(LL) = NULL;
        }
        else
        {
            last(LL) = prev(P);
            next(last(LL)) = NULL;
            prev(P) = NULL;
        }
    }
}
void deleteLastLagu(listLagu &LL, adr_lagu &P)
{
    if (isEmptyLagu(LL))
    {
        cout << "Maaf Tidak Ada List Lagu yang Dapat Dihapus\n";
    }
    else
    {
        P = last(LL);
        if (first(LL) == last(LL))
        {
            first(LL) = NULL;
            last(LL) = NULL;
        }
        else
        {
            last(LL) = prev(P);
            next(last(LL)) = NULL;
            prev(P) = NULL;
        }
    }
}
void deleteFirstRelation(ListRelation &LR, adr_relation &P)
{
    if (isEmptyRelation(LR))
    {
        cout << "Maaf Tidak Ada List Relasi Lagu yang Dapat Dihapus\n";
    }
    else
    {
        if (first(LR) == last(LR))
        {
            first(LR) = NULL;
            last(LR) = NULL;
        }
        else
        {
            P = first(LR);
            first(LR) = next(P);
            prev(first(LR)) = NULL;
            next(P) = NULL;
        }
    }
}
void deleteAfterRelation(ListRelation &LR, adr_relation Prec, adr_relation &P)
{
    if (isEmptyRelation(LR))
    {
        cout << "Maaf Tidak Ada List Relasi Lagu yang Dapat Dihapus\n";
    }
    else
    {
        if (Prec != NULL)
        {
            P = next(Prec);
            if (P != NULL)
            {
                next(Prec) = next(P);
                if (next(P) != NULL)
                {
                    prev(next(P)) = Prec;
                }
                else
                {
                    last(LR) = Prec;
                }
                next(P) = NULL;
                prev(P) = NULL;
            }
        }
    }
}
void deleteLastRelation(ListRelation &LR, adr_relation &P)
{
    if (isEmptyRelation(LR))
    {
        cout << "Maaf Tidak Ada Relasi Lagu yang Dapat Dihapus\n";
    }
    else
    {
        P = last(LR);
        if (first(LR) == last(LR))
        {
            first(LR) = NULL;
            last(LR) = NULL;
        }
        else
        {
            last(LR) = prev(P);
            next(last(LR)) = NULL;
            prev(P) = NULL;
        }
    }
}
void showPlaylist(listPlaylist LP)
{
    adr_playlist P = first(LP);
    int i = 1;
    if (isEmptyPlaylist(LP))
    {
        cout << "Maaf Playlist Kosong\n";
    }
    else
    {
        cout << "Jumlah Playlist " << jumlahPlaylist(LP) << endl;
        while (P != NULL)
        {
            cout << "-----\t" << i << " -----\n";
            cout << "Nama Playlist :" << info(P).namaPlaylist << endl;
            cout << "Creator       :" << info(P).creator << endl;
            cout << "Likes         :" << info(P).likes << endl;
            cout << "Jumlah Lagu   :" << info(P).jumlahLagu << endl;
            i++;
            P = next(P);
        }
    }
}
void showListLagu(listLagu LL)
{
    adr_lagu P = first(LL);
    int i = 1;
    if (isEmptyLagu(LL))
    {
        cout << "Maaf List Lagu Kosong\n";
    }
    else
    {
        cout << "Jumlah Lagu " << jumlahListLagu(LL) << endl;
        cout << "=======================================================================================" << endl;
        cout << setw(10) << left << "No" << setw(33) << left << "Judul" << setw(16) << left << "Artist" << setw(15) << left << "Durasi" << setw(15) << left << "Album" << endl;
        cout << "=======================================================================================" << endl;
        while (P != last(LL))
        {
            cout << setw(5) << left << i << setw(35) << left << P->info.judul << setw(20) << left << P->info.artist << setw(10) << left << P->info.durasi << setw(20) << left << P->info.album << endl;
            cout << "---------------------------------------------------------------------------------------" << endl;
            P = next(P);
            i++;
        }
        if (P == last(LL))
        {
            cout << setw(5) << left << i << setw(35) << left << P->info.judul << setw(20) << left << P->info.artist << setw(10) << left << P->info.durasi << setw(20) << left << P->info.album << endl;
        }
    }
}

void showAntrianLagu(ListQueue LQ)
{
    if (isEmptyQueue(LQ))
    {
        cout << "Tidak Ada Antrian Lagu!\n";
    }
    else
    {
        adr_Queue P;
        int i = 1;
        adr_Queue tanda = head(LQ);
        cout << "Jumlah Lagu Pada Antrian: " << jumlahAntrian(LQ) << endl;
        cout << "=======================================================================================" << endl;
        cout << setw(7) << left << "No" << setw(26) << left << "Judul" << setw(16) << left << "Artist" << setw(15) << left << "Durasi" << setw(15) << left << "Album" << endl;
        cout << "=======================================================================================" << endl;
        dequeue(LQ, P);
        cout << setw(5) << left << i << setw(28) << left << info(P).judul << setw(17) << left << info(P).artist << setw(12) << left << info(P).durasi << setw(25) << left << info(P).album << endl;
        i++;
        enqueue(LQ, P);
        while (head(LQ) != tanda)
        {
            dequeue(LQ, P);
            cout << setw(5) << left << i << setw(28) << left << info(P).judul << setw(17) << left << info(P).artist << setw(12) << left << info(P).durasi << setw(25) << left << info(P).album << endl;
            i++;
            enqueue(LQ, P);
        }
    }
}
/*
    cout << "=======================================================================================" << endl;
    cout << setw(7) << left << "No" << setw(26) << left << "Judul" << setw(16) << left << "Artist" << setw(15) << left << "Durasi" << setw(15) << left << "Album" << endl;
    cout << "=======================================================================================" << endl;
    while (L != NULL)
    {
        if (info(L).artist == namaArtist)
        {
            cout << setw(5) << left << i << setw(28) << left << info(L).judul << setw(17) << left << info(L).artist << setw(12) << left << info(L).durasi << setw(25) << left << info(L).album << endl;
*/

void showIsiPlaylist(listPlaylist LP, string Nama_Playlist)
{
    adr_playlist P = searchPlaylist(LP, Nama_Playlist);
    adr_relation R;
    int i = 1;

    if (P != NULL)
    {
        R = lagu(P).first;
        if (R == NULL)
        {
            cout << "Nama Playlist Berhasil Ditemukan, Tetapi Playlist Kosong\n";
        }
        else
        {
            cout << endl;
            cout << setw(20) << left << "Nama Playlist" << setw(20) << left << "Creator Playlist" << setw(10) << left << "Likes" << setw(15) << left << "Jumlah Lagu" << endl;
            cout << setw(20) << left << info(P).namaPlaylist << setw(20) << left << info(P).creator << setw(10) << left << info(P).likes << setw(15) << left << info(P).jumlahLagu << endl;
            cout << "=======================================================================================" << endl;
            cout << setw(7) << left << "No" << setw(26) << left << "Judul" << setw(16) << left << "Artist" << setw(15) << left << "Durasi" << setw(15) << left << "Album" << endl;
            cout << "=======================================================================================" << endl;

            while (R != lagu(P).last)
            {
                cout << setw(5) << left << i << setw(25) << left << R->dataLagu->info.judul << setw(20) << left << R->dataLagu->info.artist << setw(10) << left << R->dataLagu->info.durasi << setw(20) << left << R->dataLagu->info.album << endl;
                cout << "---------------------------------------------------------------------------------------" << endl;
                R = next(R);
                i++;
            }
            if (R == lagu(P).last)
            {
                cout << setw(5) << left << i << setw(25) << left << R->dataLagu->info.judul << setw(20) << left << R->dataLagu->info.artist << setw(10) << left << R->dataLagu->info.durasi << setw(20) << left << R->dataLagu->info.album << endl;
            }
        }
    }
    else
    {
        cout << "Maaf Playlist Tidak Ditemukan\n";
    }
}

void showRelasiLagu(listPlaylist LP, string judul_lagu)
{
    adr_playlist P = first(LP);
    adr_relation R;
    bool ketemu = false;
    int i = 1;
    cout << "Lagu yang dicari berada di: \n";
    if (P == NULL)
    {
        cout << "Maaf Playlist Kosong\n";
    }
    while (P != NULL)
    {
        R = P->lagu.first;
        while (R != NULL)
        {
            if (R->dataLagu->info.judul == judul_lagu)
            {
                cout << i << ". Nama Playlist  :" << info(P).namaPlaylist << endl;
                ketemu = true;
                i++;
            }
            R = next(R);
        }
        if (R == NULL)
        {
            P = next(P);
        }
    }
    if (!ketemu)
    {
        cout << "Maaf Lagu Tidak Ditemukan\n";
    }
}

void showLaguByArtist(listLagu LL, string namaArtist)
{
    adr_lagu L = first(LL);
    bool ketemu = false;
    int i = 0;
    cout << "List lagu berdasarkan artist yang dicari:\n";
    cout << "=======================================================================================" << endl;
    cout << setw(7) << left << "No" << setw(26) << left << "Judul" << setw(16) << left << "Artist" << setw(15) << left << "Durasi" << setw(15) << left << "Album" << endl;
    cout << "=======================================================================================" << endl;
    while (L != NULL)
    {
        if (info(L).artist == namaArtist)
        {
            i++;
            cout << setw(5) << left << i << setw(28) << left << info(L).judul << setw(17) << left << info(L).artist << setw(12) << left << info(L).durasi << setw(25) << left << info(L).album << endl;
            ketemu = true;
        }
        L = next(L);
    }
    if (!ketemu)
    {
        cout << "Maaf Artist Tidak Ditemukan\n";
    }
}

void showSameTitle(listLagu LL, string judul_lagu)
{
    int jumlah = 0;
    int i = 0;
    adr_lagu L = first(LL);
    adr_lagu cek = first(LL);
    while (L != NULL)
    {
        if (L->info.judul == judul_lagu)
        {
            jumlah++;
        }
        L = next(L);
    }

    if (jumlah >= 2)
    {
        cout << "Ditemukan " << jumlah << " lagu dengan judul yang sama pada List Lagu\n";
        cout << "Berikut list lagu yang sama :\n";
        cout << "=======================================================================================" << endl;
        cout << setw(7) << left << "No" << setw(26) << left << "Judul" << setw(16) << left << "Artist" << setw(15) << left << "Durasi" << setw(15) << left << "Album" << endl;
        cout << "=======================================================================================" << endl;
        while (cek != NULL)
        {
            if (cek->info.judul == judul_lagu)
            {
                i++;
                cout << setw(5) << left << i << setw(28) << left << info(cek).judul << setw(17) << left << info(cek).artist << setw(12) << left << info(cek).durasi << setw(25) << left << info(cek).album << endl;
            }
            cek = next(cek);
        }
    }
    else
    {
        if (jumlah == 1)
        {
            cout << "Maaf Judul Lagu Hanya Ada 1 atau Tidak Ada yang Sama\n";
        }
        if (jumlah == 0)
        {
            cout << "Maaf Judul Lagu Tidak Ditemukan pada List Lagu\n";
        }
    }
}

int jumlahPlaylist(listPlaylist LP)
{
    adr_playlist P = first(LP);
    int jumlah = 0;
    while (P != NULL)
    {
        jumlah++;
        P = next(P);
    }
    return jumlah;
}
int jumlahListLagu(listLagu LL)
{
    adr_lagu L = first(LL);
    int jumlah = 0;
    while (L != NULL)
    {
        jumlah++;
        L = next(L);
    }
    return jumlah;
}
int jumlahAntrian(ListQueue LQ)
{
    adr_Queue Q = head(LQ);
    adr_Queue P;
    int jumlah = 0;
    if (Q == head(LQ))
    {
        jumlah++;
        dequeue(LQ, P);
        enqueue(LQ, P);
    }
    while (Q != head(LQ))
    {
        jumlah++;
        dequeue(LQ, P);
        enqueue(LQ, P);
    }
    return jumlah;
}

int jumlahLaguPL(listPlaylist LP, string Nama_Playlist)
{
    int jumlah = 0;
    adr_relation R;
    adr_playlist P = first(LP);
    if (info(P).namaPlaylist == Nama_Playlist)
    {

        R = lagu(P).first;
        if (R != NULL)
        {
            while (R != NULL)
            {
                jumlah++;
                R = next(R);
            }
        }
    }

    return jumlah;
}

// MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM//// MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM//
// MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM//// MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM//
// MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM//// MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM//
// MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM//// MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM////MENU PROGRAM//

void menuUtama(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    int pilihan;
    cout << "= = = = = = = = MENU UTAMA = = = = = = = =\n";
    cout << "1. Input Data\n";
    cout << "2. Delete Data\n";
    cout << "3. Show Data\n";
    cout << "4. Search Data\n";
    cout << "5. Change Data\n";
    cout << "6. Queue Lagu\n";
    cout << "0. Exit\n";
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
    case 1:

        menuInput(LP, LL, LR, LQ);
        break;
    case 2:

        menuDelete(LP, LL, LR, LQ);
        break;
    case 3:

        menuShowData(LP, LL, LR, LQ);
        break;
    case 4:

        menuSearch(LP, LL, LR, LQ);
        break;
    case 5:

        menuUbah(LP, LL, LR, LQ);
        break;
    case 6:

        menuQueue(LP, LL, LR, LQ);
        break;
    case 0:
        cout << "ANDA TELAH KELUAR DARI PROGRAM\n";
        break;
    case 6623:

        DeveloperMode(LP, LL, LR, LQ);
        cout << "Anda Menambahkan Base Data!\n";
        menuUtama(LP, LL, LR, LQ);
        break;
    default:

        cout << "Maaf Pilihan Tidak Tersedia\n";
        menuUtama(LP, LL, LR, LQ);
        break;
    }
}
void menuInput(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    int pilihan;

    cout << "= = = = = = = = MENU INPUT = = = = = = =\n";
    cout << "1. Input Playlist\n";
    cout << "2. Input Lagu\n";
    cout << "3. Input Relasi\n";
    cout << "4. Input Like\n";
    cout << "0. Kembali\n";
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
    case 1:

        inputPlaylist(LP, LL, LR, LQ);
        break;
    case 2:

        inputLagu(LP, LL, LR, LQ);
        break;
    case 3:

        inputRelasi(LP, LL, LR, LQ);
        break;
    case 4:
        likePlaylist(LP, LL, LR, LQ);
        break;
    case 0:
        menuUtama(LP, LL, LR, LQ);
        break;
    default:

        cout << "Pilihan tidak tersedia\n";
        menuInput(LP, LL, LR, LQ);
        break;
    }
}
void inputPlaylist(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    int pilihan;
    infotype_playlist X;
    string playlistBefore;
    adr_playlist Prec = first(LP);
    adr_playlist cek;

    cout << "Masukkan nama playlist: ";

    getline(cin, X.namaPlaylist);
    cek = searchPlaylist(LP, X.namaPlaylist);
    if (cek == NULL)
    {
        cout << "Masukkan creator playlist: ";
        getline(cin, X.creator);
        X.likes = 0;
        X.jumlahLagu = 0;
        adr_playlist P = createElemenLP(X);
        do
        {
            cout << "Masukkan metode insert: \n";
            cout << "1. Insert First\n";
            cout << "2. Insert After\n";
            cout << "3. Insert Last\n";
            cout << "0. BATAL\n";
            cout << "Pilihan: ";
            cin >> pilihan;
            cin.ignore();
            switch (pilihan)
            {
            case 1:

                insertFirstPlaylist(LP, P);
                cout << "Playlist Telah Dimasukkan!\n";
                menuInput(LP, LL, LR, LQ);
                break;
            case 2:

                if (isEmptyPlaylist(LP))
                {
                    cout << "Gagal! Tidak Ada Playlist yang Ditemukan.\n";
                    pilihan = 99;
                }
                else
                {
                    cout << "Masukkan nama playlist sebelumnya: ";

                    getline(cin, playlistBefore);

                    while (Prec != NULL)
                    {
                        if (info(Prec).namaPlaylist == playlistBefore)
                        {
                            insertAfterPlaylist(LP, Prec, P);
                            cout << "Playlist Telah Dimasukkan!\n";
                        }
                        Prec = next(Prec);
                    }
                    menuInput(LP, LL, LR, LQ);
                }
                break;
            case 3:

                insertLastPlaylist(LP, P);
                cout << "Playlist Telah Dimasukkan!\n";
                menuInput(LP, LL, LR, LQ);
                break;
            case 0:

                menuInput(LP, LL, LR, LQ);
                break;
            default:

                cout << "Pilihan Tidak tersedia!\n";
                inputPlaylist(LP, LL, LR, LQ);
                break;
            }
        } while (pilihan < 1 || pilihan > 3);
    }
    else
    {
        cout << "Maaf Nama Playlist Sudah Ada\n";
        cout << "Silahkan Input Nama Playlist Baru atau Kembali Ke Menu Utama\n";
        do
        {
            cout << "Pilih Menu: \n";
            cout << "1. Input Kembali\n";
            cout << "0. Kembali Ke Menu\n";
            cout << "Pilihan: ";
            cin >> pilihan;
            cin.ignore();
            switch (pilihan)
            {
            case 1:
                inputPlaylist(LP, LL, LR, LQ);
                break;
            case 0:
                menuInput(LP, LL, LR, LQ);
                break;
            default:
                cout << "Pilihan Tidak tersedia!\n";
                inputPlaylist(LP, LL, LR, LQ);
                break;
            }
        } while (pilihan > 1);
    }
}
void inputLagu(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    int pilihan;
    infotype_lagu X;
    string laguBefore, penyanyi;
    adr_lagu Prec, cek;

    cout << "Masukkan Judul Lagu: ";
    getline(cin, X.judul);
    cout << "Masukkan Nama Artis: ";
    getline(cin, X.artist);
    cek = searchLagu(LL, X.judul, X.artist);
    if (cek == NULL)
    {
        cout << "Masukkan Durasi Lagu: ";
        getline(cin, X.durasi);
        cout << "Masukkan Album Lagu: ";
        getline(cin, X.album);
        adr_lagu P = createElemenLL(X);
        do
        {
            cout << "Masukkan metode insert: \n";
            cout << "1. Insert First\n";
            cout << "2. Insert After\n";
            cout << "3. Insert Last\n";
            cout << "0. BATAL\n";
            cout << "Pilihan: ";
            cin >> pilihan;
            cin.ignore();
            switch (pilihan)
            {
            case 1:

                insertFirstLagu(LL, P);
                cout << "Lagu telah dimasukkan!.\n";
                menuInput(LP, LL, LR, LQ);
                break;
            case 2:
                if (!isEmptyLagu(LL))
                {
                    cout << "Masukkan nama lagu sebelumnya: ";
                    getline(cin, laguBefore);
                    cout << "Masukkan nama penyanyi: ";
                    getline(cin, penyanyi);
                    Prec = searchLagu(LL, laguBefore, penyanyi);
                    insertAfterLagu(LL, Prec, P);
                    cout << "Lagu telah dimasukkan!.\n";
                    menuInput(LP, LL, LR, LQ);
                }
                else
                {
                    cout << "Daftar lagu kosong.\n";
                    pilihan = 99;
                }
                break;
            case 3:
                insertLastLagu(LL, P);
                cout << "Lagu telah dimasukkan!.\n";
                menuInput(LP, LL, LR, LQ);
                break;
            case 0:
                menuInput(LP, LL, LR, LQ);
                break;
            default:

                cout << "Pilihan Tidak tersedia!\n";
                break;
            }
        } while (pilihan < 0 || pilihan > 3);
    }
    else
    {
        cout << "Maaf Judul Lagu dan Penyanyi Sudah Ada\n";
        cout << "Silahkan Input Judul Lagu Baru atau Kembali Ke Menu Utama\n";
        do
        {
            cout << "Pilih Menu: \n";
            cout << "1. Input Kembali\n";
            cout << "0. Kembali Ke Menu\n";
            cout << "Pilihan: ";
            cin >> pilihan;
            cin.ignore();
            switch (pilihan)
            {
            case 1:
                inputLagu(LP, LL, LR, LQ);
                break;
            case 0:
                menuInput(LP, LL, LR, LQ);
                break;
            default:
                cout << "Pilihan Tidak tersedia!\n";
                inputLagu(LP, LL, LR, LQ);
                break;
            }
        } while (pilihan > 1);
    }
}
void inputRelasi(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    string namaPlaylist, judulLagu, penyanyi;
    int pilihan, pilihan2;
    adr_relation Prec;

    if (isEmptyPlaylist(LP))
    {
        cout << "Tidak Ada Playlist yang dibuat.\nSilahkan buat playlist terlebih dahulu.\n";
    }
    else
    {
        showPlaylist(LP);
        cout << "Masukkan nama playlist: ";

        getline(cin, namaPlaylist);
        if (isEmptyLagu(LL))
        {
            cout << "Belum ada lagu yang dimasukan.\nSilahkan masukkan lagu terlebih dahulu!\n";
        }
        else
        {
            showListLagu(LL);
            cout << "Masukkan judul lagu: ";
            getline(cin, judulLagu);
            cout << "Masukkan penyanyi: ";
            getline(cin, penyanyi);

            adr_playlist P = searchPlaylist(LP, namaPlaylist);
            adr_lagu L = searchLagu(LL, judulLagu, penyanyi);
            adr_relation R;

            if (P != NULL && L != NULL)
            {
                R = createElemenLR(L);
                do
                {
                    cout << "Masukkan metode insert: \n";
                    cout << "1. Insert First\n";
                    cout << "2. Insert After\n";
                    cout << "3. Insert Last\n";
                    cout << "0. BATAL\n";
                    cout << "Pilihan: ";
                    cin >> pilihan;
                    cin.ignore();
                    switch (pilihan)
                    {
                    case 1:

                        insertFirstRelation(lagu(P), R);
                        cout << "Lagu telah ditambahkan ke playlist!.\n";
                        P->info.jumlahLagu++;
                        menuInput(LP, LL, LR, LQ);
                        break;
                    case 2:
                        if (isEmptyRelation(P->lagu))
                        {
                            cout << "Gagal! Tidak ada data untuk dilakukan operasi ini.\n";
                        }
                        else
                        {
                            cout << "Masukkan judul lagu sebelumnya: ";
                            getline(cin, judulLagu);

                            Prec = searchRelation(LP, judulLagu, namaPlaylist);
                            insertAfterRelation(lagu(P), prev(Prec), R);
                            cout << "Lagu telah ditambahkan ke playlist!.\n";
                        }
                        menuInput(LP, LL, LR, LQ);
                        break;
                    case 3:

                        insertLastRelation(lagu(P), R);
                        cout << "Lagu telah ditambahkan ke playlist!.\n";
                        P->info.jumlahLagu++;
                        menuInput(LP, LL, LR, LQ);
                        break;
                    case 0:
                        menuInput(LP, LL, LR, LQ);
                        break;
                    default:
                        cout << "Pilihan Tidak tersedia!\n";
                        break;
                    }
                } while (pilihan < 0 || pilihan > 3);
            }
            else
            {
                cout << "Playlist atau lagu tidak ditemukan.\n";
                cout << "1. Ulangi\n";
                cout << "0. Kembali\n";
                cout << "Pilihan: ";
                cin >> pilihan2;
                cin.ignore();
                while (pilihan2 < 0 || pilihan2 > 1)
                {
                    cout << "Pilihan Tidak tersedia!\n";
                    cout << "1. Ulangi\n";
                    cout << "0. Kembali\n";
                    cout << "Pilihan: ";
                    cin >> pilihan2;
                    cin.ignore();
                }
                if (pilihan2 == 1)
                {
                    inputRelasi(LP, LL, LR, LQ);
                }
                else if (pilihan2 == 0)
                {
                    menuInput(LP, LL, LR, LQ);
                }
            }
        }
    }
}

void menuDelete(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    int pilihan;

    cout << "= = = = = = = = MENU DELETE = = = = = = =\n";
    cout << "1. Delete Playlist\n";
    cout << "2. Delete Lagu\n";
    cout << "3. Delete Relasi\n";
    cout << "0. Kembali\n";
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
    case 1:

        menuDeletePlaylist(LP, LL, LR, LQ);
        break;
    case 2:

        menuDeleteLagu(LP, LL, LR, LQ);
        break;
    case 3:

        menuDeleteRelasi(LP, LL, LR, LQ);
        break;
    case 0:

        menuUtama(LP, LL, LR, LQ);
        break;
    default:

        cout << "Pilihan Tidak tersedia!\n";
        menuDeletePlaylist(LP, LL, LR, LQ);
        break;
    }
}
void menuDeletePlaylist(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    int pilihan;
    string judul_playlist;
    adr_playlist P, Prec;
    if (isEmptyPlaylist(LP))
    {
        cout << "Maaf, Tidak Ada Playlist yang Dapat Dihapus\n";
        menuDelete(LP, LL, LR, LQ);
    }
    else
    {
        showPlaylist(LP);
        cout << "= = = = = = = = MENU DELETE PLAYLIST = = = = = = =\n";
        cout << "1. Delete Berdasarkan Nomor\n";
        cout << "2. Delete Berdasarkan Nama Playlist\n";
        cout << "3. Delete First\n";
        cout << "4. Delete Last\n";
        cout << "0. Kembali\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1:

            cout << "Masukkan nomor playlist yang ingin dihapus: ";
            int nomor_playlist;
            cin >> nomor_playlist;
            cin.ignore();
            P = first(LP);
            for (int i = 1; i < nomor_playlist && P != NULL; ++i)
            {
                P = next(P);
            }
            if (P != NULL)
            {
                deleteAfterPlaylist(LP, prev(P), P);
                cout << "Playlist Dihapus\n";
                menuDelete(LP, LL, LR, LQ);
            }
            else
            {
                cout << "Nomor playlist tidak valid.\n";
            }
            menuDeletePlaylist(LP, LL, LR, LQ);
            break;

        case 2:

            cout << "Masukkan nama playlist yang ingin dihapus: ";
            getline(cin, judul_playlist);

            P = searchPlaylist(LP, judul_playlist);
            if (P != NULL)
            {
                deleteAfterPlaylist(LP, prev(P), P);
                cout << "Playlist Dihapus\n";
                menuDelete(LP, LL, LR, LQ);
            }
            else
            {
                cout << "Playlist tidak ditemukan.\n";
                menuDeletePlaylist(LP, LL, LR, LQ);
            }
            break;
        case 3:

            deleteFirstPlaylist(LP, P);
            cout << "Playlist Dihapus\n";
            menuDelete(LP, LL, LR, LQ);
            break;
        case 4:

            deleteLastPlaylist(LP, P);
            cout << "Playlist Dihapus\n";
            menuDelete(LP, LL, LR, LQ);
            break;
        case 0:

            menuDelete(LP, LL, LR, LQ);
            break;
        default:

            cout << "Pilihan tidak valid.\n";
            menuDeletePlaylist(LP, LL, LR, LQ);
            break;
        }
    }
}
void menuDeleteLagu(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    int pilihan;
    adr_lagu Prec, P;
    string judulLagu, penyanyi;

    if (isEmptyLagu(LL))
    {
        cout << "Maaf, Tidak Ada Lagu yang Dapat Dihapus\n";
        menuDelete(LP, LL, LR, LQ);
    }
    else
    {
        showListLagu(LL);
        cout << "= = = = = = = = MENU DELETE LAGU = = = = = = = =\n";
        cout << "1. Delete First Lagu\n";
        cout << "2. Delete After Lagu\n";
        cout << "3. Delete Last Lagu\n";
        cout << "4. Delete Sesuai Judul Lagu dan Penyanyinya\n";
        cout << "0. Kembali\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan)
        {
        case 1:
        {
            adr_playlist pl = LP.first;
            adr_relation R, Rdel;
            while (pl != NULL)
            {
                R = searchRelation(LP, LL.first->info.judul, pl->info.namaPlaylist);
                if (R != NULL)
                {
                    if (R->dataLagu->info.artist == LL.first->info.artist)
                    {
                        if (R == pl->lagu.first)
                        {
                            deleteFirstRelation(pl->lagu, Rdel);
                            delete Rdel;
                        }
                        else if (R == pl->lagu.last)
                        {
                            deleteLastRelation(pl->lagu, Rdel);
                            delete Rdel;
                        }
                        else
                        {
                            deleteAfterRelation(pl->lagu, prev(R), Rdel);
                            delete Rdel;
                        }
                        cout << "Delete Relasi Lagu " << LL.first->info.judul << " dengan Penyanyi " << LL.first->info.artist << " di Playlist " << pl->info.namaPlaylist << " Berhasil\n";
                    }
                }
                pl = next(pl);
            }
            deleteFirstLagu(LL, P);
            cout << "Lagu Berhasil Dihapus\n";
            menuDelete(LP, LL, LR, LQ);
            break;
        }
        case 2:
        {

            cout << "Masukkan judul lagu yang ingin dihapus: ";
            getline(cin, judulLagu);
            cout << "Masukkan penyanyi dari lagu tersebut: ";
            getline(cin, penyanyi);

            Prec = searchLagu(LL, judulLagu, penyanyi);
            if (Prec != NULL)
            {
                adr_playlist pl = LP.first;
                adr_relation R, Rdel;
                while (pl != NULL)
                {
                    R = searchRelation(LP, Prec->info.judul, pl->info.namaPlaylist);
                    if (R != NULL)
                    {
                        if (R->dataLagu->info.artist == Prec->info.artist)
                        {
                            if (R == pl->lagu.first)
                            {
                                deleteFirstRelation(pl->lagu, Rdel);
                                delete Rdel;
                            }
                            else if (R == pl->lagu.last)
                            {
                                deleteLastRelation(pl->lagu, Rdel);
                                delete Rdel;
                            }
                            else
                            {
                                deleteAfterRelation(pl->lagu, prev(R), Rdel);
                                delete Rdel;
                            }
                            cout << "Delete Relasi Lagu " << Prec->info.judul << " dengan Penyanyi " << Prec->info.artist << " di Playlist " << pl->info.namaPlaylist << " Berhasil\n";
                        }
                    }
                    pl = next(pl);
                }
                deleteAfterLagu(LL, prev(Prec), P);
                cout << "Lagu Berhasil Dihapus\n";
                menuDelete(LP, LL, LR, LQ);
            }
            else
            {
                cout << "Lagu tidak ditemukan\n";
                menuDeleteLagu(LP, LL, LR, LQ);
            }
            break;
        }
        case 3:
        {
            adr_playlist pl = LP.first;
            adr_relation R;
            while (next(pl) != NULL)
            {

                R = searchRelation(LP, LL.last->info.judul, pl->info.namaPlaylist);
                if (R != NULL)
                {
                    if (R->dataLagu->info.artist == LL.last->info.artist)
                    {
                        if (R == pl->lagu.first)
                        {
                            deleteFirstRelation(pl->lagu, R);
                            delete R;
                        }
                        else if (R == pl->lagu.last)
                        {
                            deleteLastRelation(pl->lagu, R);
                            delete R;
                        }
                        else
                        {
                            deleteAfterRelation(pl->lagu, prev(R), R);
                            delete R;
                        }
                        cout << "Delete Relasi Lagu " << LL.last->info.judul << " dengan Penyanyi " << LL.last->info.artist << " di Playlist " << pl->info.namaPlaylist << " Berhasil\n";
                    }
                }
                pl = next(pl);
            }
            deleteLastLagu(LL, P);
            cout << "Lagu Berhasil Dihapus\n";
            menuDelete(LP, LL, LR, LQ);
            break;
        }
        case 4:
        {
            adr_playlist pl = LP.first;
            adr_relation R, Rdel;
            adr_lagu L;
            cout << "Masukkan Judul Lagu yang ingin dihapus: ";
            getline(cin, judulLagu);
            cout << "Masukkan penyanyi dari lagu tersebut: ";
            getline(cin, penyanyi);
            L = searchLagu(LL, judulLagu, penyanyi);
            if (L != NULL)
            {
                while (pl != NULL)
                {
                    R = searchRelation(LP, judulLagu, pl->info.namaPlaylist);
                    if (R != NULL)
                    {
                        if (R->dataLagu->info.artist == penyanyi)
                        {
                            if (R == pl->lagu.first)
                            {
                                deleteFirstRelation(pl->lagu, Rdel);
                                delete Rdel;
                            }
                            else if (R == pl->lagu.last)
                            {
                                deleteLastRelation(pl->lagu, Rdel);
                                delete Rdel;
                            }
                            else
                            {
                                deleteAfterRelation(pl->lagu, prev(R), Rdel);
                                delete Rdel;
                            }
                            cout << "Delete Relasi Lagu " << L->info.judul << " dengan Penyanyi " << L->info.artist << " di Playlist " << pl->info.namaPlaylist << " Berhasil\n";
                        }
                    }
                    pl = next(pl);
                }
                if (L == first(LL))
                {
                    deleteFirstLagu(LL, P);
                }
                else if (L == last(LL))
                {
                    deleteLastLagu(LL, P);
                }
                else
                {
                    deleteAfterLagu(LL, prev(L), P);
                }
            }
            else
            {
                cout << "Judul Lagu tidak ditemukan.\n";
            }
            break;
        }
        case 0:

            menuDelete(LP, LL, LR, LQ);
            break;
        default:

            cout << "Pilihan tidak valid\n";
            menuDeleteLagu(LP, LL, LR, LQ);
            break;
        }
    }
}
void menuDeleteRelasi(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    string namaPlaylist, judulLaguBefore;
    int pilihan, pilihan2;
    adr_relation R, Prec;
    adr_lagu laguBefore;

    if (isEmptyPlaylist(LP))
    {
        cout << "Maaf, Tidak Ada Playlist yang Dapat Dihapus\n";
        menuDelete(LP, LL, LR, LQ);
    }
    else
    {

        showPlaylist(LP);
        cout << "= = = = = = = = MENU DELETE RELASI = = = = = = = =\n";
        cout << "Masukkan nama playlist: ";
        getline(cin, namaPlaylist);

        adr_playlist P = searchPlaylist(LP, namaPlaylist);
        if (P != NULL)
        {
            do
            {
                cout << "Masukkan Metode Delete:\n";
                cout << "1. Delete First Relasi Playlist\n";
                cout << "2. Delete After Relasi Playlist\n";
                cout << "3. Delete Last Relasi Playlist\n";
                cout << "Pilihan: ";
                cin >> pilihan;
                cin.ignore();

                switch (pilihan)
                {
                case 1:

                    deleteFirstRelation(lagu(P), R);
                    P->info.jumlahLagu--;
                    cout << "Relasi Dihapus\n";
                    menuDelete(LP, LL, LR, LQ);
                    break;
                case 2:

                    cout << "Masukkan judul lagu sebelumnya: ";
                    getline(cin, judulLaguBefore);

                    Prec = searchRelation(LP, judulLaguBefore, namaPlaylist);
                    if (Prec != NULL)
                    {
                        deleteAfterRelation(lagu(P), prev(Prec), R);
                        P->info.jumlahLagu--;
                        cout << "Relasi Dihapus\n";
                        menuDelete(LP, LL, LR, LQ);
                    }
                    else
                    {
                        cout << "Lagu sebelumnya tidak ditemukan.\n";
                        cout << "1.Ulangi\n";
                        cout << "0. Kembali\n";
                        cout << "Pilihan: ";
                        cin >> pilihan2;
                        cin.ignore();
                        while (pilihan2 < 0 || pilihan2 > 1)
                        {
                            cout << "Pilihan Tidak tersedia!\n";
                            cout << "1.Ulangi\n";
                            cout << "0. Kembali\n";
                            cout << "Pilihan: ";
                            cin >> pilihan2;
                            cin.ignore();
                        }
                        if (pilihan2 == 1)
                        {
                            menuDeleteRelasi(LP, LL, LR, LQ);
                            break;
                        }
                        else if (pilihan2 == 0)
                        {
                            menuDelete(LP, LL, LR, LQ);
                            break;
                        }
                    }
                    break;
                case 3:

                    deleteLastRelation(lagu(P), R);
                    P->info.jumlahLagu--;
                    cout << "Relasi Dihapus\n";
                    menuDelete(LP, LL, LR, LQ);
                    break;
                default:

                    cout << "Pilihan tidak valid.\n";
                    break;
                }
            } while (pilihan < 1 || pilihan > 3);
        }
        else
        {
            cout << "Playlist tidak ditemukan.\n";
            cout << "1.Ulangi\n";
            cout << "0. Kembali\n";
            cout << "Pilihan: ";
            cin >> pilihan2;
            cin.ignore();
            while (pilihan2 < 0 || pilihan2 > 1)
            {
                cout << "Pilihan Tidak tersedia!\n";
                cout << "1.Ulangi\n";
                cout << "0. Kembali\n";
                cout << "Pilihan: ";
                cin >> pilihan2;
                cin.ignore();
            }
            if (pilihan2 == 1)
            {
                menuDeleteRelasi(LP, LL, LR, LQ);
            }
            else if (pilihan2 == 0)
            {
                menuDelete(LP, LL, LR, LQ);
            }
        }
    }
}

void likePlaylist(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    string namapl;
    cout << "= = = = = = = = MENU LIKE PLAYLIST = = = = = = = =\n";
    showPlaylist(LP);
    cout << "Input Nama Playlist yang Ingin Diberi Likes\n";
    getline(cin, namapl);
    adr_playlist P = searchPlaylist(LP, namapl);
    if (P != NULL)
    {
        P->info.likes++;
        cout << "Playlist Berhasil Ditemukan! Jumlah Like Bertambah 1\n";
    }
    else
    {
        cout << "Playlist Tidak Ditemukan\n";
    }
    menuInput(LP, LL, LR, LQ);
}
void menuSearch(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    int pilihan;
    cout << "= = = = = = = = MENU SEARCH = = = = = = = =\n";
    cout << "1. Search Playlist\n";
    cout << "2. Search Lagu\n";
    cout << "0. Kembali\n";
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
    case 1:

        menuSearchPlaylist(LP, LL, LR, LQ);
        break;
    case 2:

        menuSearchLagu(LP, LL, LR, LQ);
        break;
    case 0:

        menuUtama(LP, LL, LR, LQ);
        break;
    default:

        cout << "Maaf Pilihan Tidak Tersedia\n";
        menuSearch(LP, LL, LR, LQ);
        break;
    }
}

void menuShowData(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    int pilihan, pilihan2;
    string Nama_Playlist;
    string penyanyi;
    string Judul_Lagu;

    do
    {
        cout << "= = = = = = = = MENU SHOW DATA = = = = = = = =\n";
        cout << "1. Show Playlist\n";
        cout << "2. Show List Lagu\n";
        cout << "3. Show Antrian Lagu\n";
        cout << "4. Show Isi Playlist\n";
        cout << "5. Show Relasi Lagu\n";
        cout << "6. Show Lagu dari Penyanyi\n";
        cout << "7. Show Lagu dengan Judul yang Sama\n";
        cout << "0. Kembali\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan)
        {
        case 1:

            showPlaylist(LP);
            do
            {
                cout << "= = = = = = = = = = = = = = = =\n";
                cout << "0. Kembali\n";
                cout << "Pilihan: ";
                cin >> pilihan;
                cin.ignore();
                switch (pilihan)
                {
                case 0:
                    menuShowData(LP, LL, LR, LQ);
                    break;
                default:
                    cout << "Pilihan tidak tersedia!\n";
                    break;
                }
            } while (pilihan != 0);
            break;
        case 2:

            showListLagu(LL);
            do
            {
                cout << "= = = = = = = = = = = = = = = =\n";
                cout << "0. Kembali\n";
                cout << "Pilihan: ";
                cin >> pilihan;
                cin.ignore();
                switch (pilihan)
                {
                case 0:
                    menuShowData(LP, LL, LR, LQ);
                    break;
                default:
                    cout << "Pilihan tidak tersedia!\n";
                    break;
                }
            } while (pilihan != 0);
            break;
        case 3:

            showAntrianLagu(LQ);
            do
            {
                cout << "= = = = = = = = = = = = = = = =\n";
                cout << "0. Kembali\n";
                cout << "Pilihan: ";
                cin >> pilihan;
                cin.ignore();
                switch (pilihan)
                {
                case 0:
                    menuShowData(LP, LL, LR, LQ);
                    break;
                default:
                    cout << "Pilihan tidak tersedia!\n";
                    break;
                }
            } while (pilihan != 0);
            break;
        case 4:
            showPlaylist(LP);
            cout << "Masukkan nama Playlist: ";
            getline(cin, Nama_Playlist);

            showIsiPlaylist(LP, Nama_Playlist);
            do
            {
                cout << "= = = = = = = = = = = = = = = =\n";
                cout << "0. Kembali\n";
                cout << "Pilihan: ";
                cin >> pilihan;
                cin.ignore();
                switch (pilihan)
                {
                case 0:
                    menuShowData(LP, LL, LR, LQ);
                    break;
                default:
                    cout << "Pilihan tidak tersedia!\n";
                    break;
                }
            } while (pilihan != 0);

            break;
        case 5:

            cout << "Masukkan judul Lagu: ";
            getline(cin, Judul_Lagu);

            showRelasiLagu(LP, Judul_Lagu);
            do
            {
                cout << "= = = = = = = = = = = = = = = =\n";
                cout << "0. Kembali\n";
                cout << "Pilihan: ";
                cin >> pilihan2;
                cin.ignore();
                switch (pilihan2)
                {
                case 0:
                    menuShowData(LP, LL, LR, LQ);
                    break;
                default:
                    cout << "Pilihan tidak tersedia!\n";
                    break;
                }
            } while (pilihan2 != 0);
            break;
        case 6:

            cout << "Masukkan nama penyanyi: ";
            getline(cin, penyanyi);

            showLaguByArtist(LL, penyanyi);
            do
            {
                cout << "= = = = = = = = = = = = = = = =\n";
                cout << "0. Kembali\n";
                cout << "Pilihan: ";
                cin >> pilihan;
                cin.ignore();
                switch (pilihan)
                {
                case 0:
                    menuShowData(LP, LL, LR, LQ);
                    break;
                default:
                    cout << "Pilihan tidak tersedia!\n";
                    break;
                }
            } while (pilihan != 0);
            break;
        case 7:
            cout << "Masukkan Judul Lagu: ";
            getline(cin, Judul_Lagu);

            showSameTitle(LL, Judul_Lagu);
            do
            {
                cout << "= = = = = = = = = = = = = = = =\n";
                cout << "0. Kembali\n";
                cout << "Pilihan: ";
                cin >> pilihan;
                cin.ignore();
                switch (pilihan)
                {
                case 0:
                    menuShowData(LP, LL, LR, LQ);
                    break;
                default:
                    cout << "Pilihan tidak tersedia!\n";
                    break;
                }
            } while (pilihan != 0);
            break;
        case 0:

            menuUtama(LP, LL, LR, LQ);
            break;
        default:

            cout << "Maaf Pilihan Tidak Tersedia\n";
            break;
        }
    } while (pilihan < 0 || pilihan > 7);
}
void menuSearchPlaylist(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    int pilihan, pilihan2;
    string namaplaylist, namacreator;
    adr_playlist P;

    do
    {
        cout << "= = = = = = = = MENU SEARCH PLAYLIST= = = = = = = =\n";
        cout << "1. Cari berdasarkan nama playlist\n";
        cout << "2. Cari berdasarkan Creator playlist\n";
        cout << "0. Kembali\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan)
        {
        case 1:

            cout << "Masukkan nama playlist yang ingin dicari: ";
            getline(cin, namaplaylist);

            P = searchPlaylist(LP, namaplaylist);
            if (P == NULL)
            {
                cout << "Playlist tidak ditemukan!\n";
            }
            else
            {
                cout << "Playlist Ditemukan!\n";
                do
                {
                    cout << "= = = = = = = = = = = = = = = =\n";
                    cout << "1. Tampilkan info playlist\n";
                    cout << "2. Tampilkan info playlist beserta isinya\n";
                    cout << "0. Kembali\n";
                    cout << "Pilihan: ";
                    cin >> pilihan2;
                    cin.ignore();
                    switch (pilihan2)
                    {
                    case 1:

                        cout << setw(20) << left << "Nama Playlist" << setw(20) << left << "Creator Playlist" << setw(10) << left << "Likes" << setw(15) << left << "Jumlah Lagu" << endl;
                        cout << setw(20) << left << info(P).namaPlaylist << setw(20) << left << info(P).creator << setw(10) << left << info(P).likes << setw(15) << left << info(P).jumlahLagu << endl;
                        break;
                    case 2:

                        showIsiPlaylist(LP, info(P).namaPlaylist);
                        break;
                    case 0:
                        menuSearchPlaylist(LP, LL, LR, LQ);
                        break;
                    default:

                        cout << "Pilihan tidak valid!\n";
                        break;
                    }
                } while (pilihan2 < 0 || pilihan2 > 2);
            }
            break;
        case 2:

            cout << "Masukkan nama creator playlist yang ingin dicari: ";
            getline(cin, namacreator);

            P = searchPlaylistByCreator(LP, namacreator);
            if (P == NULL)
            {
                cout << "Playlist tidak ditemukan untuk creator tersebut!\n";
            }
            else
            {
                cout << "Playlist Ditemukan!\n";
                do
                {
                    cout << "= = = = = = = = = = = = = = = =\n";
                    cout << "1. Tampilkan info playlist\n";
                    cout << "2. Tampilkan info playlist beserta isinya\n";
                    cout << "Pilihan: ";
                    cin >> pilihan2;
                    cin.ignore();
                    switch (pilihan2)
                    {
                    case 1:

                        cout << setw(20) << left << "Nama Playlist" << setw(20) << left << "Creator Playlist" << setw(10) << left << "Likes" << setw(15) << left << "Jumlah Lagu" << endl;
                        cout << setw(20) << left << info(P).namaPlaylist << setw(20) << left << info(P).creator << setw(10) << left << info(P).likes << setw(15) << left << info(P).jumlahLagu << endl;
                        break;
                    case 2:

                        showIsiPlaylist(LP, info(P).namaPlaylist);
                        break;
                    default:

                        cout << "Pilihan tidak valid!\n";
                        break;
                    }
                } while (pilihan2 < 1 || pilihan2 > 2);
            }
            break;
        case 0:

            menuSearch(LP, LL, LR, LQ);
            break;
        default:

            cout << "Pilihan tidak valid!\n";
            break;
        }
    } while (pilihan < 1 || pilihan > 2);
    do
    {
        cout << "= = = = = = = = = = = = = = = =\n";
        cout << "0. Kembali\n";
        cout << "1. Kembali ke Menu Utama\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        if (pilihan == 0)
        {

            menuSearch(LP, LL, LR, LQ);
        }
        else if (pilihan == 1)
        {

            menuUtama(LP, LL, LR, LQ);
        }
        else
        {

            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan < 0 || pilihan > 1);
}
void menuSearchLagu(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    int pilihan, pilihan2;
    string judulLagu, namaArtist;
    adr_lagu P;

    do
    {
        cout << "= = = = = = = = MENU SEARCH PLAYLIST= = = = = = = =\n";
        cout << "1. Cari lagu berdasarkan judul\n";
        cout << "2. Cari lagu berdasarkan Artist\n";
        cout << "0. Kembali\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan)
        {
        case 1:

            cout << "Masukkan judul lagu yang ingin dicari: ";
            getline(cin, judulLagu);
            cout << "Masukkan penyanyi dari lagu tersebut: ";
            getline(cin, namaArtist);

            P = searchLagu(LL, judulLagu, namaArtist);
            if (P == NULL)
            {
                cout << "Lagu tidak ditemukan!\n";
            }
            else
            {
                cout << "Lagu Ditemukan!\n";
                do
                {
                    cout << "= = = = = = = = = = = = = = = =\n";
                    cout << "1. Tampilkan info Lagu\n";
                    cout << "2. Tampilkan Relasinya\n";
                    cout << "0. kembali\n";
                    cout << "Pilihan: ";
                    cin >> pilihan2;
                    cin.ignore();
                    switch (pilihan2)
                    {
                    case 1:

                        cout << "Judul Lagu: " << P->info.judul << endl;
                        cout << "Artist    : " << P->info.artist << endl;
                        cout << "durasi    : " << P->info.durasi << endl;
                        cout << "Album     : " << P->info.album << endl;
                        break;
                    case 2:

                        showRelasiLagu(LP, judulLagu);
                        break;
                    case 0:

                        menuSearchLagu(LP, LL, LR, LQ);
                        break;
                    default:

                        cout << "Pilihan tidak tersedia!\n";
                        break;
                    }
                } while (pilihan2 < 0 || pilihan2 > 2);
            }
            break;
        case 2:

            cout << "Masukkan nama artist yang ingin dicari: ";
            getline(cin, namaArtist);

            showLaguByArtist(LL, namaArtist);
            break;
        case 0:

            menuSearch(LP, LL, LR, LQ);
            break;
        default:

            cout << "Pilihan tidak tersedia!\n";
            break;
        }
    } while (pilihan < 0 || pilihan > 2);
    do
    {
        cout << "= = = = = = = = = = = = = = = =\n";
        cout << "0. Kembali\n";
        cout << "1. Kembali ke Menu Utama\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        if (pilihan == 0)
        {

            menuSearch(LP, LL, LR, LQ);
        }
        else if (pilihan == 1)
        {

            menuUtama(LP, LL, LR, LQ);
        }
        else
        {

            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan < 0 || pilihan > 1);
}
adr_playlist searchPlaylist(listPlaylist LP, string namaPlaylist)
{
    adr_playlist P = first(LP);
    while (P != NULL)
    {
        if (info(P).namaPlaylist == namaPlaylist)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}
adr_lagu searchLagu(listLagu LL, string judulLagu, string penyanyi)
{
    adr_lagu L = first(LL);
    while (L != NULL)
    {
        if (info(L).judul == judulLagu && info(L).artist == penyanyi)
        {
            return L;
        }
        L = next(L);
    }
    return NULL;
}
adr_relation searchRelation(listPlaylist LP, string judulLagu, string namaPlaylist)
{
    adr_relation Prec;
    adr_playlist P = searchPlaylist(LP, namaPlaylist);
    if (P != NULL)
    {
        Prec = P->lagu.first;
        while (Prec != NULL)
        {
            if (Prec->dataLagu->info.judul == judulLagu)
            {
                return Prec;
            }
            Prec = next(Prec);
        }
    }
    return NULL;
}
adr_playlist searchPlaylistByCreator(listPlaylist LP, string creatorName)
{
    adr_playlist P = first(LP);

    while (P != NULL)
    {
        if (info(P).creator == creatorName)
        {
            return P;
        }

        P = next(P);
    }

    return NULL;
}

void menuQueue(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    int pilihan;

    cout << "= = = = = = = = MENU QUEUE= = = = = = = =\n";
    cout << "1. Tambah Antrian\n";
    cout << "2. Hapus Antrian\n";
    cout << "3. Tampilkan Antrian\n";
    cout << "4. Play Antrian\n";
    cout << "5. Prioritaskan Antrian\n";
    cout << "0. Kembali\n";
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
    case 1:

        songToQueue(LP, LL, LR, LQ);
        break;
    case 2:
        clearQueue(LP, LL, LR, LQ);
        menuQueue(LP, LL, LR, LQ);
        break;
    case 3:

        menuTampilkanQueue(LP, LL, LR, LQ);
        break;
    case 4:
        playSongs(LP, LL, LR, LQ);
        menuQueue(LP, LL, LR, LQ);
        break;
    case 5:
        changePriority(LP, LL, LR, LQ);
        menuQueue(LP, LL, LR, LQ);
        break;
    case 0:
        menuUtama(LP, LL, LR, LQ);
        break;
    default:

        cout << "Pilihan Tidak Tersedia!\n";
        menuQueue(LP, LL, LR, LQ);
        break;
    }
}

void menuTampilkanQueue(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    int access;

    showAntrianLagu(LQ);
    do
    {
        cout << "= = = = = = = = = = = = = = = =\n";
        cout << "0. Kembali\n";
        cout << "Pilihan: ";
        cin >> access;
        cin.ignore();
        switch (access)
        {
        case 0:
            menuQueue(LP, LL, LR, LQ);
            break;
        default:
            cout << "Pilihan Tidak Tersedia!\n";
            break;
        }
    } while (access != 0);
}
void playSongs(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    showAntrianLagu(LQ);
    adr_Queue Q;
    if (isEmptyQueue(LQ))
    {
        cout << "Maaf Antrian Kosong, Tidak Ada yang Bisa di Play\n";
    }
    else
    {
        string stop = "Y";
        while (!isEmptyQueue(LQ) && (stop == "Y" || stop == "y"))
        {
            dequeue(LQ, Q);
            cout << "= = = = = = = = MEMUTAR LAGU = = = = = = = =\n";
            showAntrianLagu(LQ);
            cout << "====================================== NOW PLAYING ======================================\n";
            cout << "|| " << setw(84) << left << info(Q).judul << "||" << endl;
            cout << "|| " << setw(84) << left << info(Q).artist << "||" << endl;
            cout << "||                        ------------------>-------------------  " << setw(21) << left << info(Q).durasi << "||" << endl;
            cout << "=========================================================================================\n";
            cout << "Apakah Akan Lanjut Play Lagu? (Y/N)\n";
            cin >> stop;
            cin.ignore();
        }
        if (stop == "N" || stop == "n")
        {
            if (!isEmptyQueue(LQ))
            {
                cout << "Lagu yang Tersisa pada Antrian:\n";
                showAntrianLagu(LQ);
            }
        }
        else
        {
            if (isEmptyQueue(LQ))
            {
                cout << "Maaf Antrian Kosong, Tidak Ada yang Bisa di Play\n";
            }
        }
    }
}

void songToQueue(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    string Nama_Playlist, Judul_Lagu, penyanyi;
    int access;
    string setuju = "N";
    adr_playlist pl;
    adr_relation pr;
    int i = 1;
    int jumlah;
    cout << "= = = = = = = = MENU INPUT SONG TO QUEUE = = = = = = = =\n";
    cout << "1. Input lagu berdasarkan playlist\n";
    cout << "2. Input manual per lagu\n";
    cout << "0. Kembali\n";
    cout << "Pilihan: ";
    cin >> access;
    cin.ignore();
    switch (access)
    {
    case 1:

        cout << "SHOW PLAYLIST\n";
        showPlaylist(LP);
        while (setuju == "N")
        {
            cout << "Input Nama Playlist yang Ingin Dilihat Isinya: ";
            getline(cin, Nama_Playlist);

            pl = searchPlaylist(LP, Nama_Playlist);
            if (pl != NULL)
            {
                cout << "SHOW DATA PLAYLIST\n";
                showIsiPlaylist(LP, Nama_Playlist);
                cout << "Apakah Ingin Memasukkan Playlist Tersebut pada Antrian? (Y/N)\n";
                cin >> setuju;
                cin.ignore();
            }
            else
            {
                cout << "Maaf Playlist tidak ditemukan.\nCoba Lagi!\n";
                songToQueue(LP, LL, LR, LQ);
            }
        }
        pr = pl->lagu.first;
        while (pr != NULL)
        {
            enqueue(LQ, createElemenLQ(pr->dataLagu->info));
            pr = next(pr);
        }
        cout << "Isi Antrian Lagu Setelah Memasukkan Lagu Baru\n";
        showAntrianLagu(LQ);

        menuQueue(LP, LL, LR, LQ);
        break;
    case 2:

        cout << "SHOW LIST LAGU\n";
        showListLagu(LL);
        cout << "Berapa Banyak Lagu Yang Ingin Diinputkan: ";
        cin >> jumlah;
        cin.ignore();
        for (i; i <= jumlah; i++)
        {
            cout << "Input Judul Lagu Yang Ingin Diinputkan Dalam Antrian: ";
            getline(cin, Judul_Lagu);
            cout << "Masukkan penyanyi dari lagu tersebut: ";
            getline(cin, penyanyi);

            adr_lagu P = searchLagu(LL, Judul_Lagu, penyanyi);
            enqueue(LQ, createElemenLQ(P->info));
        }
        cout << "Isi Antrian Lagu Setelah Memasukkan Lagu Baru\n";
        showAntrianLagu(LQ);
        menuQueue(LP, LL, LR, LQ);
        break;
    case 0:
        menuQueue(LP, LL, LR, LQ);
        break;
    default:
        cout << "Pilihan tidak tersedia!\n";
        songToQueue(LP, LL, LR, LQ);
        break;
    }
}
void clearQueue(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    if (!isEmptyQueue(LQ))
    {
        adr_Queue P, tanda;
        bool ketemu = false;
        int access;
        string Judul_Lagu;
        cout << "= = = = = = = = MENU DELETE QUEUE = = = = = = = =\n";
        cout << "1. Delete 1 Lagu\n";
        cout << "2. Delete Semua Antrian\n";
        cout << "0. Kembali\n";
        cout << "Pilihan: ";
        cin >> access;
        cin.ignore();
        switch (access)
        {
        case 1:
            ListQueue Q2;
            createListQueue(Q2);
            cout << "Masukkan Judul Lagu yang ingin dihapus dari antrian: ";
            getline(cin, Judul_Lagu);

            if (isEmptyQueue(LQ))
            {
                cout << "List Antrian Kosong\n";
            }
            else
            {
                while (!isEmptyQueue(LQ))
                {
                    dequeue(LQ, P);
                    if (P->info.judul != Judul_Lagu)
                    {
                        enqueue(Q2, P);
                    }
                }
                while (!isEmptyQueue(Q2))
                {
                    dequeue(Q2, P);
                    enqueue(LQ, P);
                }
                cout << "Lagu Berhasil Dihapus\n";
            }
            break;

        case 2:

            adr_Queue P;
            cout << "CLEAR QUEUE:\n";
            if (!isEmptyQueue(LQ))
            {
                while (!isEmptyQueue(LQ))
                {
                    dequeue(LQ, P);
                }
                cout << "Clear Queue Berhasil Dilakukan\n";
            }
            else
            {
                cout << "Maaf Queue Sudah Kosong, Tidak Ada yang Bisa Dihapus\n";
            }
            break;
        }
    }
    else
    {
        cout << "Maaf Queue Sudah Kosong, Tidak Ada yang Bisa Dihapus\n";
    }
}
void changePriority(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    string judulLagu;
    adr_Queue depan = head(LQ);
    adr_Queue belakang = tail(LQ);
    adr_Queue R, P;

    if (!isEmptyQueue(LQ))
    {
        showAntrianLagu(LQ);
        cout << "= = = = = = = = MENU UBAH PRIORITAS ANTRIAN = = = = = = = =\n";
        cout << "Masukan judul lagu yang ingin didahulukan: ";
        getline(cin, judulLagu);

        bool ketemu;
        while (info(head(LQ)).judul != judulLagu && head(LQ) != belakang)
        {
            dequeue(LQ, P);
            enqueue(LQ, P);
        }
        if (info(head(LQ)).judul == judulLagu)
        {
            dequeue(LQ, R);
            ketemu = true;
            while (head(LQ) != depan)
            {
                dequeue(LQ, P);
                enqueue(LQ, P);
            }
            enqueue(LQ, R);
            while (info(head(LQ)).judul != judulLagu)
            {
                dequeue(LQ, P);
                enqueue(LQ, P);
            }
            cout << "Antrian berhasil diubah!\n";
        }
        if (!ketemu)
        {
            cout << "Lagu yang anda cari tidak ketemu!\n";
        }
    }
    else
    {
        cout << "Maaf Antrian masih kosong! \n";
    }
}

void menuUbah(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    int access;

    cout << "= = = = = = = = MENU UBAH QUEUE = = = = = = = =\n";
    cout << "1. Ubah Info Playlist\n";
    cout << "2. Ubah Info Lagu\n";
    cout << "3. Ubah Isi Playlist\n";
    cout << "0. Kembali\n";
    cout << "Pilihan: ";
    cin >> access;
    cin.ignore();
    switch (access)
    {
    case 1:

        ubahPlaylist(LP, LL, LR, LQ);
        menuUbah(LP, LL, LR, LQ);
        break;
    case 2:

        ubahLagu(LP, LL, LR, LQ);
        menuUbah(LP, LL, LR, LQ);
        break;
    case 3:

        ubahRelasi(LP, LL, LR, LQ);
        menuUbah(LP, LL, LR, LQ);
        break;
    case 0:
        menuUtama(LP, LL, LR, LQ);
        break;
    default:

        cout << "Pilihan Tidak Tersedia!\n";
        menuUbah(LP, LL, LR, LQ);
        break;
    }
}
void ubahPlaylist(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    cout << "= = = = = = = = UBAH NAMA PLAYLIST = = = = = = = =\n";
    cout << "SHOW PLAYLIST\n";
    showPlaylist(LP);
    string namaBaru, namaLama;
    int i, jumlah;
    cout << "Input Berapa Banyak Playlist yang Ingin Diiubah Namanya:\n";
    cin >> jumlah;
    cin.ignore();
    for (i = 1; i <= jumlah; i++)
    {
        cout << "Input Nama Playlist Awal: \n";
        getline(cin, namaLama);

        adr_playlist P = searchPlaylist(LP, namaLama);
        if (P != NULL)
        {
            cout << "Playlist Berhasil Ditemukan, Input Nama Playlist Baru: \n";
            getline(cin, namaBaru);
            info(P).namaPlaylist = namaBaru;
            cout << "Nama Playlist Berhasil Diubah!\n";
        }
        else
        {
            cout << "Maaf Nama Playlist Tidak Ditemukan\n";
        }
    }
}
void ubahLagu(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    cout << "= = = = = = = = UBAH DATA LAGI = = = = = = = =\n";
    cout << "SHOW LIST LAGU\n";
    showListLagu(LL);
    string judulLama, judulBaru, penyanyi, durasi, album;
    int i, jumlah;
    cout << "Input Berapa Banyak Data Lagu yang Ingin Diiubah: ";
    cin >> jumlah;
    cin.ignore();
    for (i = 1; i <= jumlah; i++)
    {
        cout << "Input Judul Lagu Awal: ";
        getline(cin, judulLama);
        cout << "Masukkan penyanyi dari lagu tersebut: ";
        getline(cin, penyanyi);

        adr_lagu P = searchLagu(LL, judulLama, penyanyi);
        if (P != NULL)
        {
            cout << "Lagu Berhasil Ditemukan, Input Data Baru\n";
            cout << "Judul Lagu: ";
            getline(cin, judulBaru);

            info(P).judul = judulBaru;
            cout << "Nama Penyanyi: ";
            getline(cin, penyanyi);

            info(P).artist = penyanyi;
            cout << "Durasi Lagu: ";
            getline(cin, durasi);

            info(P).durasi = durasi;
            cout << "Nama Album: ";
            getline(cin, album);

            info(P).album = album;
            cout << "Data Lagu Berhasil Diubah!\n";
        }
        else
        {
            cout << "Maaf Judul Lagu Tidak Ditemukan\n";
        }
    }
}
void ubahRelasi(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    string setuju = "N";
    string namapl, judul, judulBaru, penyanyi;
    adr_playlist P;
    adr_relation R;
    adr_lagu L;
    bool selesai = false;

    cout << "= = = = = = = = UBAH ISI PLAYLIST = = = = = = = =\n";
    while (setuju != "Y")
    {
        cout << "SHOW PLAYLIST\n";
        showPlaylist(LP);
        cout << "Input Nama Playlist yang Ingin Dilihat Lagunya: ";
        getline(cin, namapl);

        P = searchPlaylist(LP, namapl);
        if (P != NULL)
        {
            showIsiPlaylist(LP, namapl);
            cout << "Apakah Ingin Mengubah Isi Playlist Tersebut? (Y/N)\n";
            cin >> setuju;
            cin.ignore();
        }
        else
        {
            cout << "Maaf Nama Playlist Tidak Ditemukan\n";
            setuju = "N";
        }
    }
    if (setuju == "Y")
    {
        while (!selesai)
        {
            cout << "Masukkan Judul Lagu yang Ingin Diubah: \t";
            getline(cin, judul);

            R = searchRelation(LP, judul, namapl);
            if (R != NULL)
            {
                while (!selesai)
                {
                    showListLagu(LL);
                    cout << "Masukkan data lagu baru dengan menuliskan judul lagunya:\n";
                    getline(cin, judulBaru);
                    cout << "Masukkan penyanyi dari lagu tersebut: ";
                    getline(cin, penyanyi);

                    L = searchLagu(LL, judulBaru, penyanyi);
                    if (L != NULL)
                    {
                        R->dataLagu = L;
                        cout << "Isi Playlist Berhasil Diubah!\n";
                        selesai = true;
                    }
                    else
                    {
                        cout << "Judul Lagu Tidak Ditemukan Pada List Lagu\n";
                    }
                }
            }
            else
            {
                cout << "Judul Lagu yang Diinputkan Tidak Ditemukan Pada Playlist\n";
            }
        }
    }
}

void DeveloperMode(listPlaylist &LP, listLagu &LL, ListRelation &LR, ListQueue &LQ)
{
    infotype_lagu x;
    infotype_playlist Y;
    adr_playlist p1, p2, p3, p4;
    adr_lagu L;

    x = {"Light Switch", "Charlie Puth", "3:07", "CHARLIE"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"P.S.I LOVE YOU", "Paul Partohap", "4:01", "P.S.I LOVE YOU"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Unconditionally", "Katy Perry", "3:48", "PRISM"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"I Dont Think I Like Her", "Charlie Puth", "3:08", "CHARLIE"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Night Changes", "One Direction", "3:48", "FOUR (Deluxe)"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Daylight", "Taylor Swift", "4:53", "Lover"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Give Me Your Forever", "Zack Tabudlo", "4:05", "Episode"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Stuck With U", "Stuck With U", "3:48", "Lover"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Charlie Be Quiet!", "Charlie Puth", "2:08", "CHARLIE"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Perfect", "One Direction", "3:50", "Made In The A.M"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Steal My Girl", "One Direction", "3:48", "FOUR (Deluxe)"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Spaces", "One Direction", "3:48", "FOUR (Deluxe)"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Old Love", "yuji", "4:09", "Old Love"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"8 Letters", "Why Don't We", "3:10", "8 Letters"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Where Do Broken Hearts Go", "One Direction", "3:48", "FOUR (Deluxe)"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Beauty And A Beat", "Justin Bieber", "3:47", "Belive"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Everyday", "Ariana Grande", "3:15", "Daengerous Woman"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"That's Hilarious", "Charlie Puth", "2:24", "CHARLIE"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Here With Me", "d4vd", "4:02", "Here With Me"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"free love", "HONNE", "3:29", "no song without you"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Favorite Girl", "Justin Bieber", "4:16", "My Worlds (International Version)"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"18", "One Direction", "4:08", "FOUR (Deluxe)"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Left and Right", "Charlie Puth", "2:34", "CHARLIE"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Cupid - Twin Ver.", "FIFTY FIFTY", "2:54", "The Begining Cupid"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"There's Nothing Holdin' Me Back", "Shawn Mendes", "3:19", "Illuminate (Deluxe)"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Beside You", "keshi", "2:46", "beside you"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"No Control", "One Direction", "3:48", "FOUR (Deluxe)"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Girl Almighty", "One Direction", "3:48", "FOUR (Deluxe)"};
    insertLastLagu(LL, createElemenLL(x));
    x = {"Daylight", "Maroon 5", "3:45", "Overexposed"};
    insertLastLagu(LL, createElemenLL(x));

    Y = {"Kaka Dede", "RCCA & DAFII"};
    p1 = createElemenLP(Y);
    insertLastPlaylist(LP, p1);
    Y = {"POPMIX", "Spotipis"};
    p2 = createElemenLP(Y);
    insertLastPlaylist(LP, p2);
    Y = {"ThisisCharlie", "Charlie Puth"};
    p3 = createElemenLP(Y);
    insertLastPlaylist(LP, p3);
    Y = {"FOUR", "One Direction"};
    p4 = createElemenLP(Y);
    insertLastPlaylist(LP, p4);

    L = searchLagu(LL, "Daylight", "Taylor Swift");
    insertLastRelation(p1->lagu, createElemenLR(L));
    L = searchLagu(LL, "18", "One Direction");
    insertLastRelation(p1->lagu, createElemenLR(L));
    L = searchLagu(LL, "Stuck With U", "Stuck With U");
    insertLastRelation(p1->lagu, createElemenLR(L));
    L = searchLagu(LL, "Perfect", "One Direction");
    insertLastRelation(p1->lagu, createElemenLR(L));
    L = searchLagu(LL, "Here With Me", "d4vd");
    insertLastRelation(p1->lagu, createElemenLR(L));
    L = searchLagu(LL, "free love", "HONNE");
    insertLastRelation(p1->lagu, createElemenLR(L));
    L = searchLagu(LL, "P.S.I LOVE YOU", "Paul Partohap");
    insertLastRelation(p1->lagu, createElemenLR(L));
    L = searchLagu(LL, "Cupid - Twin Ver.", "FIFTY FIFTY");
    insertLastRelation(p1->lagu, createElemenLR(L));
    L = searchLagu(LL, "Beside You", "keshi");
    insertLastRelation(p1->lagu, createElemenLR(L));
    L = searchLagu(LL, "Old Love", "yuji");
    insertLastRelation(p1->lagu, createElemenLR(L));
    L = searchLagu(LL, "Give Me Your Forever", "Zack Tabudlo");
    insertLastRelation(p1->lagu, createElemenLR(L));
    L = searchLagu(LL, "Favorite Girl", "Justin Bieber");
    insertLastRelation(p1->lagu, createElemenLR(L));
    L = searchLagu(LL, "Light Switch", "Charlie Puth");
    insertLastRelation(p1->lagu, createElemenLR(L));
    p1->info.jumlahLagu = 13;

    L = searchLagu(LL, "Everyday", "Ariana Grande");
    insertLastRelation(p2->lagu, createElemenLR(L));
    L = searchLagu(LL, "There's Nothing Holdin' Me Back", "Shawn Mendes");
    insertLastRelation(p2->lagu, createElemenLR(L));
    L = searchLagu(LL, "Beauty And A Beat", "Justin Bieber");
    insertLastRelation(p2->lagu, createElemenLR(L));
    L = searchLagu(LL, "Unconditionally", "Katy Perry");
    insertLastRelation(p2->lagu, createElemenLR(L));
    L = searchLagu(LL, "8 Letters", "Why Don't We");
    insertLastRelation(p2->lagu, createElemenLR(L));
    L = searchLagu(LL, "Daylight", "Maroon 5");
    insertLastRelation(p2->lagu, createElemenLR(L));
    p2->info.jumlahLagu = 6;

    L = searchLagu(LL, "That's Hilarious", "Charlie Puth");
    insertLastRelation(p3->lagu, createElemenLR(L));
    L = searchLagu(LL, "Charlie Be Quiet!", "Charlie Puth");
    insertLastRelation(p3->lagu, createElemenLR(L));
    L = searchLagu(LL, "Light Switch", "Charlie Puth");
    insertLastRelation(p3->lagu, createElemenLR(L));
    L = searchLagu(LL, "Left and Right", "Charlie Puth");
    insertLastRelation(p3->lagu, createElemenLR(L));
    L = searchLagu(LL, "I Dont Think I Like Her", "Charlie Puth");
    insertLastRelation(p3->lagu, createElemenLR(L));
    p3->info.jumlahLagu = 5;

    L = searchLagu(LL, "18", "One Direction");
    insertLastRelation(p4->lagu, createElemenLR(L));
    L = searchLagu(LL, "Steal My Girl", "One Direction");
    insertLastRelation(p4->lagu, createElemenLR(L));
    L = searchLagu(LL, "Where Do Broken Hearts Go", "One Direction");
    insertLastRelation(p4->lagu, createElemenLR(L));
    L = searchLagu(LL, "Night Changes", "One Direction");
    insertLastRelation(p4->lagu, createElemenLR(L));
    L = searchLagu(LL, "No Control", "One Direction");
    insertLastRelation(p4->lagu, createElemenLR(L));
    L = searchLagu(LL, "Spaces", "One Direction");
    insertLastRelation(p4->lagu, createElemenLR(L));
    p4->info.jumlahLagu = 6;
}