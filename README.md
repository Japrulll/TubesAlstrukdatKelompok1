"Bismillah Lancar Jaya Tubes"

---

# Purrmart Kelompok 8 K02

## Deskripsi Program

PURRMART merupakan sebuah aplikasi dengan sistem jual beli ke Borma berbasis CLI (command-line interface) yang mana sistem tersebut penting untuk membantu membawakan kemenangan bagi OWCA. Aplikasi PURRMART dibuat dengan menggunakan bahasa C dan memanfaatkan struktur Abstract Data Type (ADT) seperti ADT kustom, ADT List, ADT Mesin Karakter dan ADT Mesin Kata, dan ADT Queue.
Dalam sistem ini, terdapat fitur-fitur untuk menampilkan daftar barang, menambah barang baru, menyimpan dan membeli barang, menampilkan barang yang dibeli, mengelola wishlist user, dan bekerja untuk menghasilkan uang. Fitur-fitur tersebut direalisasikan melalui kode program yang terdiri dari main menu dan berisikan welcome menu, serta beberapa command seperti START, LOAD, dan juga HELP. Setelah itu, program akan berisikan login menu, yang terdiri dari command LOGIN, REGISTER, dan HELP. Terakhir, pengguna akan masuk ke main menu dan beberapa penanganan command lain sehingga program akan terus menerima command hingga diberikan command QUIT yang berlaku pada semua menu untuk keluar dari program.


## Anggota :
- Farella Kamala Budianto / 18223046
- Ananda Fajrul Zidan / 18223067
- Muhammad Arya Putra Prihastono / 18223068
- Muhammad Refino Ramadhan / 18223070
- Hans Joseph B. W. Silitonga / 18223072
- Michael Jeremi Bungaran S / 18221136

## Requirements :
- gcc (hanya untuk mengkompile program)

## Cara Mengkompile Program
1. Buka terminal dan set lokasi folder terminal ke tempat source codenya berada
2. Copy command di bawah ini dan paste di terminal, lalu enter
```
gcc main.c help.c save.c load.c masukdaftar.c work.c tebak_angka.c WORDL3.c StoreList.c Cartj.c history.c WISHLIST.c "./Folder ADT/ADTFile.c" "./Folder ADT/ADTItem.c" "./Folder ADT/ADTUser.c" "./Folder ADT/mesinkata.c" "./Folder ADT/mesinkarakter.c" "./Folder ADT/queue.c" "./Folder ADT/ADTSetMap.c" "./Folder ADT/ADTLinkedlist.c" "./Folder ADT/ADTStack.c" -o main.exe
```
3. Hasil kompile dapat berupa main.exe yang terletak pada lokasi folder tersebut

## Cara Menjalankan Program
1. Pastikan terdapat folder bernama "save" yang di dalamnya terdapat file "default_save.txt", berada di direktori yang sama dengan main.exe.
2. Buka terminal dan arahkan lokasi kerja terminal ke direktori tempat file main.exe berada.
3. Jalankan perintah berikut di terminal:
`./main.exe`.
4. Program akan mulai berjalan dalam terminal.

## Cara Menavigasi Program
![image](https://github.com/user-attachments/assets/3dfd6433-a040-41d6-a92a-2769dbab2401)

Ketika dijalankan, program akan kelihatan seperti ini.
Untuk menavigasi menu tersebut, bisa dengan mengetik angka yang tertulis atau mengetik kata pertama menu tersebut

contoh untuk ke menu file dapat ketik : `1` atau `file`

command dapat juga di _chain_ dengan dipisah dengan spasi agar dapat menginput lebih dari satu 

contoh ketika di login untuk meregistrasi dapat langsung `registrasi <username> <password>`
