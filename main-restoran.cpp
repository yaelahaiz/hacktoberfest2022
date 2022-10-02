#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 11

using namespace std;

struct Queue{
    string mikan[MAX]={"Ayam Geprek Mercon\t\t\t\t\t Rp 30000","Steak\t\t\t\t\t\t\t Rp 35000","Mie Drodog\t\t\t\t\t\t Rp 35000","Cup Cake Red Velvet\t\t\t\t\t Rp 30000","Aneka Sosis(Tempura dll)\t\t\t\t Rp 25000","Coffe Latte\t\t\t\t\t\t Rp 25000","Americano Coffee\t\t\t\t\t Rp 25000","Hot Chocolate\t\t\t\t\t\t Rp 25000","Juice\t\t\t\t\t\t\t Rp 15000","Milk Shake\t\t\t\t\t\t Rp 15000","Tea Ice\t\t\t\t\t\t\t Rp 10000"};
    int harga [MAX]={30000,35000,35000,30000,25000,25000,25000,25000,15000,15000,10000};
    string mikan2 [MAX]={"Ayam Geprek Mercon\t\t\t\t\t Rp 30000","Steak\t\t\t\t\t\t\t Rp 35000","Mie Drodog\t\t\t\t\t\t Rp 35000","Cup Cake Red Velvet\t\t\t\t\t Rp 30000","Aneka Sosis(Tempura dll)\t\t\t\t Rp 25000","Coffe Latte\t\t\t\t\t\t Rp 25000","Americano Coffee\t\t\t\t\t Rp 25000","Hot Chocolate\t\t\t\t\t\t Rp 25000","Juice\t\t\t\t\t\t\t Rp 15000","Milk Shake\t\t\t\t\t\t Rp 15000","Tea Ice\t\t\t\t\t\t\t Rp 10000"};
    int hargashorted[MAX]={25000,25000,30000,25000,30000,25000,15000,35000,15000,35000,10000};
    string pelanggan[MAX];
    int awal, akhir;
} antrian;

void tampilmenu(){


    cout<<"-------------------------------------------------------------------------\n";
    cout<<"\t\tSELAMAT DATANG DI RESTORAN WAIKIKI\n";
    cout<<"-------------------------------------------------------------------------\n";
    cout<<"\nDaftar Menu Makanan dan Minuman\n";
    for(int i=0;i<11;i++){
        cout<<"["<<i<<"].\t"<<antrian.mikan[i]<<endl;
    }

}
void tampilmenu2(){


    cout<<"-------------------------------------------------------------------------\n";
    cout<<"\t\tSELAMAT DATANG DI RESTORAN WAIKIKI\n";
    cout<<"-------------------------------------------------------------------------\n";
    cout<<"\nDaftar Menu Makanan dan Minuman\n";
    for(int i=0;i<11;i++){
        cout<<"["<<i<<"].\t"<<antrian.mikan2[i]<<endl;
    }

}

void pilihmakan()
{
    int juml=0,x,total=0;
    cout<<"-------------------------------------------------------------------------\n";
    cout<<"Berapa banyak jumlah pesanan : ";
    cin>>juml;
    cout<<endl;
    cout<<"Pilih Nomor Code Menu Makanan/Minuman\n";
    for(int i=0;i<juml;i++)
    {
        w:
        cout<<"Code ke-"<<i+1<<" : ";
        cin>>x;
        if(x>10)
        {
        cout<<"Code nomor "<<x<<" tidak tersedia mohon pilih menu yang lain"<<endl;
        goto w;
        }
        total=total+antrian.harga[x];
        cout<<antrian.mikan[x]<<endl;
    }
        cout<<"-------------------------------------------------------------------------\n";
        cout<<"Total yang harus dibayar : \t\t\t\t Rp "<<total<<endl;


}
void pilihmakan2()
{
    int juml=0,x,total=0;
    cout<<"-------------------------------------------------------------------------\n";
    cout<<"Berapa banyak jumlah pesanan : ";
    cin>>juml;
    cout<<"Pilih Nomor Menu Makanan/Minuman\n";
    for(int i=0;i<juml;i++)
    {
        w:
        cout<<"Code ke-"<<i+1<<" : ";
        cin>>x;
        cout<<endl;
        if(x>10)
        {
        cout<<"Code nomor "<<x<<" tidak tersedia mohon pilih menu yang lain"<<endl;
        goto w;
        }
        total=total+antrian.hargashorted[x];
        cout<<antrian.mikan2[x]<<endl;
        }
        cout<<"-------------------------------------------------------------------------\n";
        cout<<"Total yang harus dibayar : \t\t\t\t Rp "<<total<<endl;


}
void sorting(){
int i,j,min;
string temp,temp2;
for(i=0;i<11;i++){
    min = i;
    for(j=i+1;j<11;j++){
        if(antrian.mikan2[min]>antrian.mikan2[j])
            min=j;
    }
    if(antrian.mikan2[i] != antrian.mikan2[min]){
        temp=antrian.mikan2[i];
        antrian.mikan2[i]=antrian.mikan2[min];
        antrian.mikan2[min]=temp;
    }
}

}

void init(){
    antrian.awal=-1;
    antrian.akhir=-1;
}

bool penuh(){
    if(antrian.akhir==MAX-1){
        return true;
    } else {
        return false;
    }
}

bool kosong(){
    if(antrian.akhir==-1){
        return true;
    } else {
        return false;
    }
}

void cari(){
string x;

cout<<"Nama pelanggan yang ingin dicari : ";
getline(cin>>ws,x);

int i=0;
int posisi=0;

while(i<11 && antrian.pelanggan[i]!=x)
{
    i++;
}
if(antrian.pelanggan[i]!=x){
    cout<<"\nMaaf pelanggan yang dicari tidak ada";
}
else if(antrian.pelanggan[i]==x){
 posisi=i+1;

    cout<<"Antrian ke - "<<posisi<<endl;
}
getch();
}

void display(){
    int k;
    cout<<"\n\t\tDAFTAR ANTRIAN\n";
    cout<<"-------------------------------------------------------------------------\n";
    if(!kosong()){
        for(k=antrian.awal; k<antrian.akhir; k++){
            cout<<"Berada di antrian ke - "<<k+1<< " = "<<antrian.pelanggan[k]<<"\n";
        }
    }
    else
        cout<<"Antrian Kosong";

}

//menambahkan antrian
void inQueue(){
    string pelanggan;
    if(!penuh()){
        cout<<"\nMasukkan Nama Pelanggan : ";
        cin>>pelanggan;
        antrian.pelanggan[antrian.akhir] = pelanggan;
        antrian.akhir++;
        cout<<"\nPelanggan atas nama "<<" " << pelanggan <<" dalam Antrian\n";
        cout<<"-------------------------------------------------------------------------\n";
    if(!kosong()){
        display();
    }
    else {
        cout<<"Antrian Penuh !";
    }
    cout<<"-------------------------------------------------------------------------\n";
    if(!kosong()){
    }
    }
}

//mengeluarkan antrian
void deQueue(){
    int k;
    if(!kosong()){
        cout<<"Pelanggan atas nama : "<<antrian.pelanggan[antrian.awal]<<" selesai"<<endl;
        for(k=antrian.awal; k<antrian.akhir; k++){
            antrian.pelanggan[k]=antrian.pelanggan[k+1];
        }
        antrian.akhir--;
    } else {
        cout<<"Antrian Kosong";
    }
    cout<<"-------------------------------------------------------------------------\n";
}

int main()
{
    int pil;
    z:
    inQueue();
    cout<<"\nLanjut MENU UTAMA (tekan enter)";
    getch();
    x:
    system("CLS");
    cout<<"-------------------------------------------------------------------------\n";
    cout<<"\t\tSELAMAT DATANG DI RESTORAN WAIKIKI\t\t\n";
    cout<<"-------------------------------------------------------------------------\n";
    cout<<"\t\t\tPILIHAN MENU\n";
    cout<<"-------------------------------------------------------------------------\n";
    cout<<"\t[1]. Daftar Menu\n";
    cout<<"\t[2]. Daftar Menu tersorting (A...Z)\n";
    cout<<"\t[3]. Daftar antrian\n";
    cout<<"\t[4]. Cari nama pelanggan\n";
    cout<<"\t[5]. Hapus antrian yang sudah selesai\n";
    cout<<"\t[6]. Pesanan Berikutnya\n";
    cout<<"\t[7]. Keluar\n";
    cout<<"-------------------------------------------------------------------------\n";
    cout<<"Masukkan Pilihan Anda [1..7] : ";
    cin>>pil;
    cout<<"-------------------------------------------------------------------------\n";
    switch(pil){
    case 1:
        system("CLS");
        tampilmenu();
        pilihmakan();
        cout<<"\n-------------------------------------------------------------------------\n";
        cout<<"Kembali ke Menu(tekan Enter)";
        getch();
        goto x;
        break;
    case 2:
        system("CLS");
        sorting();
        tampilmenu2();
        pilihmakan2();
        cout<<"\n-------------------------------------------------------------------------\n";
        cout<<"Kembali ke Menu(tekan Enter)";
        getch();
        goto x;
        break;
    case 3:
        system("CLS");
        display();
        cout<<"\n-------------------------------------------------------------------------\n";
        cout<<"Kembali ke Menu(tekan Enter)";
        getch();
        goto x;
        break;
    case 4:
        system("CLS");
        cari();
        getch();
        goto x;
        break;
    case 5:
        system("CLS");
        deQueue();
        cout<<"Kembali ke Menu(tekan Enter)";
        getch();
        goto x;
        break;
    case 6:
        system("CLS");
        goto z;
        break;
    case 7:
        return 0;
        break;
    default:
        goto x;
        break;
    }
    return 0;
}
