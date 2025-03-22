# PROYEK-2-KELOMPOK5-B

Repository untuk penugasan proyek 2 dari kelompok 5 kelas 1B

Kelompok 5 :

- Ridho Sulistyo Saputro
- Salma Arifah Zahra
- Samudra Putra Gunawan
- Dimas Rizal Ramadhani
- Akmal Rezaqi Al-Farhan

APLIKASI ULAR MAKAN APEL HEHE

// untuk melakukan compile aplikasi

g++ main.c function/mainbody.c function/pages.c function/makanan.c function/stopwatch.c function/ular.c -o main.exe -I"C:\MinGW-w64\mingw64\include" -L"C:\MinGW-w64\mingw64\lib" -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

atau compile menggunakan

mingw32-make

# Modul Modul dan Pemiliknya

Ridho : 
- Modul AmbilWarna
- Modul tulisan
- Modul Kotak
- Modul tombol
- Modul ResetGame
- Modul tampilanAwal
- Modul PopUpPause

Salma : 
- Modul Titik
- Modul gambarAwan
- Modul Tombolpause
- Modul HandlePause
- Modul tampilanPlay
- Modul tampilanArena

Samudra : 
- Modul GenerateRandomPosition
- Modul GeneratemakanantType
- Modul Makanan
- Modul TampilkanScore

Dimas : 
- Modul LoopGame
- Modul InitUlar
- Modul GerakUlar
- Modul CekTabrakan
- Modul CekMakanMakanan
- Modul GambarUlar

Farhan : 
- Modul Stopwatch
- Modul startStopwatch


## Update Perbahan Minggu ke-6
Update Ridho :
- Membuat fitur play and pause : modul LoopGame mainbody
- menambahkan modul ResetGame
- menambahkan variabel global di mainhead
- perbaikan di modul stopwatch

Update Salma :
- Mouse Click untuk Pause/Resume : function/mainbody.c(line 97)

Update Dimas :
- 10/03/2025, Perbaikan panjang ular maksimal (sudah disesuaikan dengan ukuran arena)

Update Samudra : 
- perubahan terdapat pada modul  void Makanan(MakananStruct makanan)
- bool CekMakanMakanan(MakananStruct *makanan)
- void LoopGame()
- dan void Tampilkanscore() 
- penambahan modul makananType GeneratemakananType() dan struct makanan type, makananstruct 
