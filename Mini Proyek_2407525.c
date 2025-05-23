#include <stdio.h>

int main(){
    
   char nama[100][100], namaBarang[100];
   int jumlahOrang, hargaBarang = 0, jumlahBarang, totalPPN = 0, total[100] = {0};
   int totalPerOrang = 0;
   
   float ppn;

    printf("\n");

// input jumlah orang
printf("Masukkan jumlah orang yang pesan: ");
scanf("%d", &jumlahOrang);

// jumlah orang invalid
while (jumlahOrang <= 0){
        printf("Jumlah orang tidak valid. Masukkan ulang jumlah orang!\n");
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

    while (jumlahBarang <= 0){
        printf("Jumlah pesanan tidak valid. Masukkan ulang jumlah pesanan %s: ", nama[i]);
        scanf("%d", &jumlahBarang);
    }

//input pesanan dan harga masing-masing
    printf("\n");

for (int j = 0; j < jumlahBarang; j++){

    printf("Masukkan nama pesanan ke-%d: ", j+1);
    scanf(" %99[^\n]", namaBarang);

    printf("Berapa harga %s: ", namaBarang);
    scanf("%d", &hargaBarang);

    while (hargaBarang <= 0){
        printf("Harga tidak valid. Masukkan ulang harga %s: ", namaBarang);
        scanf("%d", &hargaBarang);
    }
    
    total[i] += hargaBarang;
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

    //belum termasuk PPN
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

     for (int j = 0; j < jumlahOrang; j++) {
        ppnPerOrang[j]= totalPPN/jumlahOrang;
        totalPerOrang = total[j] + ppnPerOrang[j];
        printf("%s: Total setelah termasuk PPN: %d\n", nama[j], totalPerOrang);
     }
    totalPPN = totalSeluruh + totalPPN;
    printf("Total Total keseluruhan setelah termasuk PPN: %d\n", totalPPN);
    printf("\n");

        
    return 0;
}
