# PROYEK-2 KELOMPOK-B5 SNAKESNACK

Repository untuk penugasan proyek 2 dari kelompok 5 kelas 1B Aplikasi Game Ular Mukbang

Anggota Kelompok 5 :

- Ridho Sulistyo Saputro (059)
- Salma Arifah Zahra (062)
- Samudra Putra Gunawan (063)
- Dimas Rizal Ramadhani (040)
- Akmal Rezaqi Al-Farhan (036)

## Cara melakukan compile aplikasi

1. Ketik di terminal : mingw32-make

2. Lalu jalankan melalui terminal : ./main.exe

## Modul Modul dan Pemiliknya

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
