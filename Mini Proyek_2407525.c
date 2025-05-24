#include <stdio.h>

int main(){
    

    //Deklarasi variabel yang akan digunakan, termasuk array.
   char nama[100][100], namaBarang[100];
   int jumlahOrang, hargaBarang = 0, jumlahBarang, totalPPN = 0, total[100] = {0};
   int totalPerOrang = 0;
   float ppn;

    printf("\n");

// input jumlah orang
printf("Masukkan jumlah orang yang pesan: ");
scanf("%d", &jumlahOrang);

// jumlah orang invalid, looping while, ketika jumlahOrangBarang <= 0, program akan terus berulang sampai jumlahOrang > 0.
while (jumlahOrang <= 0){
        printf("Jumlah orang tidak valid!\n");
        printf("Masukkan jumlah orang yang pesan: ");
        scanf("%d", &jumlahOrang);
    }

// input nama dan jumlah pesanannya
for (int i = 0; i < jumlahOrang; i++){
    printf("\n");
    printf("Siapa nama pemesan ke-%d: ", i+1 );
    scanf("%s", nama[i]);
    printf("Berapa banyak pesanan %s: ", nama[i]);
    scanf("%d", &jumlahBarang);

    //looping while, ketika jumlahBarang <= 0, program akan terus berulang sampai jumlahBarang > 0.
    while (jumlahBarang <= 0){
        printf("Jumlah pesanan tidak valid!\n");
        printf(" Masukkan ulang jumlah pesanan %s: ", nama[i]);
        scanf("%d", &jumlahBarang);
    }

//input pesanan dan harga masing-masing
    printf("\n");

    // looping for digunakan agar program berulang sesuai dengan jumlah barang yang di inputkan sebelumnya.
for (int j = 0; j < jumlahBarang; j++){

    printf("Masukkan nama pesanan ke-%d: ", j+1);
    scanf(" %99[^\n]", namaBarang); //" %99[^\n]" menggunakan format ini agar program dapat membaca string dengan spasi.

    printf("Berapa harga %s: ", namaBarang);
    scanf("%d", &hargaBarang);

    //looping while, ketika hargaBarang <= 0, program akan terus berulang sampai hargaBarang > 0.
    while (hargaBarang <= 0){
        printf("Harga tidak valid. Masukkan ulang harga %s: ", namaBarang);
        scanf("%d", &hargaBarang); 
    }
    
    total[i] += hargaBarang; //menyimpan dan menambahkan harga dari variabel hargaBarang ke array total.
}
 
}
     printf("\n");

// perhitungan total dan ppn
    printf("Masukkan PPN dalam persen: ");
    scanf("%f", &ppn);
   
    // output
     printf("\n");

    printf("\n***** Rincian tagihan *****\n");
    
    // total 
    printf("\n");

    //output perhitungan belum termasuk PPN, menggunakan looping for agar program berjalan menyesuaikan jumlah orang
    int totalSeluruh = 0;
     for (int i = 0; i < jumlahOrang; i++) {
        totalPPN = (total[i] * ppn / 100);
        totalPerOrang = total[i] + totalPPN;
        printf("%s: Total sebelum PPN: %d\n", nama[i], total[i]);
        
        totalSeluruh += total[i];
    }

    printf("Total keseluruhan belum termasuk PPN: %d\n", totalSeluruh);
    
    printf("\n");
    //Total keseluruhan termasuk PPN
    totalPPN = totalSeluruh * ppn/100;
    int ppnPerOrang[100] = {0};

    // looping ini digunakan agar print berulang sesuai dengan jumlah orangnya
     for (int j = 0; j < jumlahOrang; j++) {
        ppnPerOrang[j]= totalPPN/jumlahOrang; //perhitungan PPN perorang
        totalPerOrang = total[j] + ppnPerOrang[j]; //PPN per orang ditambah dengan total agar menghasilkan total per-orang
        printf("%s: Total setelah termasuk PPN: %d\n", nama[j], totalPerOrang);
     }

    //  total keseluruhan setelah termasuk PPN
    totalPPN = totalSeluruh + totalPPN;
    printf("Total Total keseluruhan setelah termasuk PPN: %d\n", totalPPN);
    printf("\n");

        
    return 0;
}
