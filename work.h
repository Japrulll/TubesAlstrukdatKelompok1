#ifndef WORK_H
#define WORK_H

#include "mesinkarakter.h"
#include "mesinkata.h"

#define MAX_JOBS 5
#define JOB_NAME_LEN 50
#define MAX_LEN 100

typedef struct {
    char jobName[JOB_NAME_LEN];
    int pekerjaan;
    int durasi; // dalam detik
} Job;

// Operasi string
int compareStrings(const char *str1, const char *str2);
/* Membandingkan dua string str1 dan str2 */
/* I.S.: str1 dan str2 adalah string yang akan dibandingkan */
/* F.S.: Mengembalikan nilai integer */

void copyString(char *dest, const char *src);
/* Menyalin string dari source ke destination sebagai pengganti strcpy */
/* I.S. src merupakan source dan dest merupakan destination dari source */
/* F.S. src telah disalin ke dest */

// Fungsi utama
void simulateWork(int durasi);
/* Mensimulasikan proses kerja dengan durasi tertentu */
/* I.S.: Parameter durasi diberikan dalam satuan detik */
/* F.S.: Fungsi akan menunggu selama durasi detik, menunjukkan proses kerja yang sedang berlangsung (misalnya, melalui animasi atau teks) */

void work(int *balance);
/* Menambahkan penghasilan dari pekerjaan yang dipilih ke saldo pengguna */
/* I.S.: Pointer balance menunjuk ke saldo pengguna saat ini */
/* F.S.: Saldo (*balance) bertambah sesuai penghasilan pekerjaan yang telah diselesaikan, setelah */

int main();
/* Fungsi utama program yang menjalankan simulasi kerja dan memperbarui saldo pengguna */
/* I.S.: Tidak ada saldo awal yang ditetapkan */
/* F.S.: Memanggil fungsi work() untuk menambahkan penghasilan ke variabel saldo (balance). Setelah pekerjaan selesai, saldo saat ini ditampilkan dalam format rupiah ke layar */

#endif