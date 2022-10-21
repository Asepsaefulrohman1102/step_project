#include <iostream>
#include<stdlib.h>
#include <string>
//link list disebut unlimited karena tidak ada pembatasan

using namespace std;

//1. MEMBUAT DEKLARASI MENGGUNAKAN STRUCT
struct buku {
    //komponennya
    string judul;
    int thn;

    //ada pointer yang menunjukkan elemen selanjutnya
    buku *next;
};

//proses INISIALISASI, menyatakan bahwa linked list tidak ada
buku *head=NULL;
buku *body=NULL;
buku *tail=NULL;

//2. MEMBUAT FUNGSI PENGECEKAN LINKED LIST KOSONG ATAU TIDAK
bool isEmpty(){
    return head == NULL;
    //jika head sama dengan null maka link list kosong
    //menggunakan fungsi bool agar return yang dibalikkan mengasilkan true or false
}

//3. MEMBUAT FUNGSI INSERT DARI PILIHAN MENU 1
void insert ( string judul, int thn){
    //jika link list KOSONG maka head dan tail akan diisi oleh newnode
    if (isEmpty()){
        // new nama linklist atau struct untuk alokasi memori
        buku *newnode = new buku();
        //newnode diisi oleh variabel judul = diambil dari inputan
        newnode->judul=judul;
        newnode->thn=thn;
        //newnode nextnya ke NULL
        newnode->next=NULL;
        //jadi head dan tailnya akan diisi oleh newnoode jika linklist masih kosong
        head=newnode;
        tail=newnode;

      //jika link list TIDAK kosong maka newnode akan ke tail atau posisi akhir
    } else{
        buku *newnode = new buku();
        newnode->judul=judul;
        newnode->thn=thn;
        newnode->next=NULL;
        //tail nextnya newnode yang bernext NULL
        tail->next=newnode;
        //jadi tailnya diisi newnode atau inputan terbaru
        tail=newnode;
    }

}

//5. MEMBUAT PENCARIAN DATA
void find(string judul){
    //bisa mengambil code dari display
    buku *bantuan=head; //variabel pointer BANTUAN tipe datanya BUKU dan diisi mulai dari HEAD/AWAL
    int ulang=1; //dimulai dari 1
    bool ket=false; //buat variabel ket dengan tipe data boolean yang diinisialisasi false

    //jika bantuan tidak sama dengan 0 maka mengoutputkan datanya
    if (head != NULL){
        while(bantuan != NULL)
        {
            //diberi suatu kondisi dimana jika judul sama dengan judul yang dicari
            if(bantuan->judul==judul){
                cout << endl;
                cout << "== Data Ditemukan ==" << endl;
                cout << "Isi Data Ke - " << ulang << " || Judul Buku : " << bantuan->judul << " ; Tahun Terbit : " << bantuan->thn << endl;
                //jika variabel ket hasilnya true maka akan mengoutputkan dat ayng ditemukan
                ket = true;
            }

            ulang++;
            //head yang diubah bantuan, diubah ke bantuan next berarti setelah head / node ke 2
            bantuan=bantuan->next;
        }
    }
    //jika var ket false maka data tidak ditemukan
    if(ket == false){
        cout << endl;
        cout << "!! Data tidak ditemukan !!" << endl;
        cout << endl;

    }

}

//6.MENGUPDATE DATA MENU 4 dengan getlin
void update(string judul){
    //bisa mengambil code dari display
    buku *bantuan=head; //variabel pointer BANTUAN tipe datanya BUKU dan diisi mulai dari HEAD/AWAL
    int ulang=1; //dimulai dari 1
    bool ket=false; //buat variabel ket dengan tipe data boolean yang diinisialisasi false

    //jika bantuan tidak sama dengan 0 maka mengoutputkan datanya
    if (head != NULL){
        while(bantuan != NULL)
        {
            //diberi suatu kondisi dimana jika judul sama dengan judul yang dicari
            if(bantuan->judul==judul){
                cout << endl;
                cout << "== Data Ditemukan ==" << endl;
                cout << "Isi Data Ke - " << ulang << endl;
                cout << "Judul Buku : " << bantuan->judul << endl;
                cout << "Tahun Terbit : " << bantuan->thn << endl;
                //jika variabel ket hasilnya true maka akan mengoutputkan dat ayng ditemukan
                ket = true;
                cout << endl;
                //menginputkan data baru
                cout << "Masukkan Judul Buku Baru : ";
                getline(cin, bantuan->judul);
                cout << "Masukkan Tahun Terbit Baru : ";
                cin >> bantuan->thn;
                cout << endl;
                cout << "Data Berhasil Diupdate" << endl;
                cout << endl;
            }

            ulang++;
            //head yang diubah bantuan, diubah ke bantuan next berarti setelah head / node ke 2
            bantuan=bantuan->next;
        }
    }
    //jika var ket false maka data tidak ditemukan
    if(ket == false){
        cout << endl;
        cout << "!! Data tidak ditemukan !!" << endl;
        cout << endl;

    }

}


//4. MEMBUAT TAMPILAN SEMUA DATA MENU 3

void display(){
    //bantuan sebagai variabel pointer tipe data buku
    buku *bantuan=head; //variabel pointer BANTUAN tipe datanya BUKU dan diisi mulai dari HEAD/AWAL
    int ulang=1; //dimulai dari 1

    //jika bantuan tidak sama dengan 0 maka mengoutputkan datanya
    if (head != NULL){
        while(bantuan != NULL)
        {
            cout << endl;
            cout << "Isi Data Ke - " << ulang << endl;
            cout << "Judul Buku : " << bantuan->judul << endl;
            cout << "Tahun Terbit : " << bantuan->thn << endl;
            ulang++;
            //head yang diubah bantuan, diubah ke bantuan next berarti setelah head / node ke 2
            bantuan=bantuan->next;
        }
    } else {
        cout << endl;
        cout << "!! Data Kosong !!" << endl;
        cout << endl;
    }

}



int main()
{
    //deklarasi
    int pilih, thn;
    string judul;

    //menggunakan looping do while
    do {

        //3. MEMBUAT MENU TAMPILAN
        cout << endl;
        cout << "===============================" << endl;
        cout << "    DATA BUKU PERPUS HARAPAN   " << endl;
        cout << "===============================" << endl;
        cout << "1.Tambah buku baru" << endl;
        cout << "2.Cari buku" << endl;
        cout << "3.Tampilkan semua buku" << endl;
        cout << "4.Update buku" << endl;
        cout << "5.Hapus data buku" << endl;
        cout << "6.Keluar aplikasi" << endl;
        cout << "Masukkan pilihan anda (1-6) = ";
        cin >> pilih;
        switch(pilih){
            case 1:{
                cout << endl;
                cout << "== Tambah Buku Baru ==" << endl;
                cout << "Masukkan judul buku : ";
                //untuk bisa menambah spasi pada penginputan
                cin.ignore();
                getline(cin,judul);
                cout << "Masukkan tahun terbit : ";
                cin >> thn;
                //masukkan fungsi yang sudah dibuat
                insert(judul,thn);
                break;
            }

            case 2:{
                cout << endl;
                cout << "== Cari Buku ==" << endl;
                cout << "Masukkan judul buku yang dicari : ";
                cin.ignore();
                getline(cin,judul);
                find(judul);
                break;
            }

            case 3:{
                cout << endl;
                cout << "== Tampilkan Semua Data Buku ==" << endl;
                //masukkan fungsi menampilkan data
                display();
                break;
            }

            case 4:{
                cout << endl;
                cout << "== Update Judul Buku ==" << endl;
                cout << "Masukkan judul buku : ";
                cin.ignore();
                getline(cin,judul);
               /* cout << "Masukkan update judul : ";
                cin.ignore();
                getline(cin,judul);
                cout << "Masukkan update tahun : ";
                cin >> thn; */
                //masukan fungsi update
                update(judul);
                break;
            }

            case 5:{
                cout << endl;
                cout << "== Menghapus Data Buku =="<< endl;
                cout << "Masukkan judul buku yang akan dihapus : ";
                cin.ignore();
                getline(cin,judul);
                break;

            }

            case 6:{
                cout << endl;
                cout << "===== Keluar Dari Aplikasi ====="<< endl;
                break;
            }

            default:{
                cout << endl;
                cout << "!! Pilihan anda tidak ada di menu !! silahkan pilih kembali" << endl;

            }

        }
    } while(pilih != 6);
    //jika pilih tidak sama dengan 6 maka tidak dilakuka perulangan

    return 0;
}
