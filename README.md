# PROYEK-2-KELOMPOK5-B
Repository untuk penugasan proyek 2 dari kelompok 5 kelas 1B

Kelompok 5 : 
- Ridho Sulistyo Saputro
- Salma Arifah Zahra
- Samudra Putra Gunawan
- Dimas Rizal Ramadhani 
- Akmal Rezaqi Al-Farhan

APLIKASI ULAR MAKAN APEL HEHE

// running aplikasi

g++ main.c function/mainbody.c function/pages.c function/makanan.c function/stopwatch.c function/ular.c -o main.exe -I"C:\MinGW-w64\mingw64\include" -L"C:\MinGW-w64\mingw64\lib" -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

//branch samudra
//perubahan terdapat pada modul  void Makanan(MakananStruct makanan), bool CekMakanMakanan(MakananStruct *makanan), void LoopGame(), dan void Tampilkanscore(). 
//penambahan modul makananType GeneratemakananType() dan struct makanan type, makananstruct 