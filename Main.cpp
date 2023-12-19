#include "Playlist.h"
#include "Playlist.cpp"

int main()
{
    listLagu LL;
    listPlaylist LP;
    ListQueue LQ;
    ListRelation LR;

    createListPlaylist(LP);
    createListLagu(LL);
    createListQueue(LQ);

    menuUtama(LP, LL, LR, LQ);
    return 0;

    /*
    DEBUG:
    1. Menu Input      gajadi
    2. Delete Data
    3. Show Data      beres
    4. Search Data
    5. Change Data
    6. Queue Lagu     beres

    - Tambahin output kaya data berhasil dimasukan
    - Input Lagu masih salah karena perulangan masukannya balik ke menu input
    - Show isi playlist masih salah, kalai playlistnya masih kosong jangan di tambahin
    - menu delete lagu masih kurang
    - show lagu by penyanyi salah karena kalau gaada lagunya masih inputin
    - cek break; (SUDAH)

    */
}
