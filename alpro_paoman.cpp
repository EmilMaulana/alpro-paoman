#include <iostream>
#include <iomanip>

using namespace std;

// variabel yang dideklarasikan di luar semua fungsi, yang berarti bahwa variabel tersebut dapat diakses oleh semua fungsi dalam program
int menu, jml_buku, ketemu;
char pil;
string nama[5] = {" Emil Maulana          Fitri Akmaliah", " M Ardho Rantisy       Muhammad Hanif", " M Reynaldo Aulia R"};
string cari;

//fungsi untuk menampilkan garis
void garis(){
    cout <<" =================================================================================";
    cout<<endl;
}

//fungsi untuk menampilkan header
void header(){
    garis();
    cout <<" \t\t\t Program Pendataan Buku " <<endl;
    garis();
    cout<<endl;
    for(int i = 0; i <= 3 ; i++){
        cout<<"\t\t "<<nama[i]<<endl;
    }

    garis();
}

//tipe data untuk menyimpan variabel buku
struct Buku{
    string judul_buku, pengarang;
    int tahun_terbit, isbn;

};

//function main
int main(){

    login :
    string username, password;
    string *uname=&username;


    cout<<" \n\n\n \t\t\t\t\t ---- LOGIN SISTEM PENDATAAN BUKU ----  \t\t\t\t \n";
    cout << "\t\t\tMasukkan username: ";
    cin >> username;
    cout << "\t\t\tMasukkan password: ";
    cin >> password;

    if (username == "admin" && password == "admin123"){
            cout << endl << "Login Berhasil" << endl;
            cout << &username << endl;
            cout << uname << endl;
			system("pause");
			system("cls");
			goto menu_utama;

    }else if (username == "admin" ){
        cout << endl << "password salah" << endl;
        cout << &username << endl;
        cout << uname << endl;
        system("pause");
        system("cls");
        goto login;

    }else if (password == "admin123"){
        cout << endl << "username salah" << endl;
        cout << &username << endl;
        cout << uname << endl;
        system("pause");
        system("cls");
        goto login;


    }else if ( username != "admin" && password != "admin123"){
        cout << endl << "username dan password salah" << endl;
        cout << &username << endl;
        cout << uname << endl;
        system("pause");
        system("cls");
        goto login;
    }


    menu_utama :
        header();
        cout<<endl;
        garis();
        cout<<"  1. TAMBAH DAFTAR BUKU "<<endl;
        cout<<"  2. TAMPILKAN DAFTAR BUKU "<<endl;
        cout<<"  3. CARI BUKU "<<endl;
        garis();
        cout<<" SILAHKAN PILIH MENU : ";
        cin>>menu;

        if(menu == 1){
            system("cls");
            goto tambah_buku;
        }else if(menu == 2){
            system("cls");
            goto tampil_buku;
        }else if(menu == 3){
            system("cls");
            goto cari_buku;
        }else{
            system("cls");
            cout <<endl;
            garis();
            cout <<"\t\t\t === MENU TIDAK TERSEDIA === "<<endl;
            garis();
            exit(0);
        }



    tambah_buku :
        header();
        cout<<" MASUKKAN BANYAKNYA BUKU : ";
        cin>>jml_buku;
        //system("cls");

        Buku *b;
        b =  new Buku[100];

        for(int i = 1; i <= jml_buku; i++){
            cout<<" MASUKKAN JUDUL BUKU KE - "<< i <<" : ";
            getline(cin,b[i].judul_buku);
            getline(cin,b[i].judul_buku);
            cout<<" MASUKKAN ISBN BUKU : ";
            cin>>b[i].isbn;
            cout<<" MASUKKAN TAHUN TERBIT : ";
            cin>>b[i].tahun_terbit;
            cout<<" MASUKKAN NAMA PENGARANG : ";
            cin>>b[i].pengarang;
            garis();
            cout<<endl;
        }
        garis();
        cout <<" BUKU BERHASIL DITAMBAHKAN "<<endl;
        garis();
        system(" pause ");
        system("cls");
        goto menu_utama;

    tampil_buku :
        //header();
        if(jml_buku > 0){
            cout << " \t\t\t\t TABEL BUKU MAHASISWA " << endl;
            garis();
            cout << " |          JUDUL BUKU           |     ISBN     |  TAHUN TERBIT  |   PENGARANG   |\n";
            garis();
            for (int i = 1; i <= jml_buku; i++){
                    cout<<setiosflags (ios::left)<<" |"<<setw (30)<<b[i].judul_buku;
                    cout<<setiosflags (ios::left)<<" |   "<<setw (10)<<b[i].isbn;
                    cout<<setiosflags (ios::left)<<" | "<<setw (14)<<b[i].tahun_terbit;
                    cout<<setiosflags (ios::left)<<" |  "<<setw (8)<<b[i].pengarang<< "     |" << endl;
            }
            garis();
            system("pause");
            system ("cls");
            goto menu_utama;
        }else if(jml_buku == 0){
            system("cls");
            garis();
            cout<<"\t\t\t\t DATA BUKU KOSONG "<<endl;
            cout<<"\t\t\t SILAHKAN TAMBAHKAN BUKU TERLEBIH DAHULU "<<endl;
            garis();
            system("pause");
            system ("cls");
            goto menu_utama;
        }

    cari_buku :
        if(jml_buku > 0){
            cout << " \t\t\t\t TABEL BUKU MAHASISWA " << endl;
            garis();
            cout << "\t\t\t |            JUDUL BUKU             |\n";
            garis();
            for (int i = 1; i <= jml_buku; i++){

                    cout<<setiosflags (ios::left)<<"\t\t\t |"<<setw (30)<<b[i].judul_buku<< "     |" << endl;
            }
            garis();

        }else if(jml_buku == 0){
            system("cls");
            garis();
            cout<<"\t\t\t\t DATA BUKU KOSONG "<<endl;
            cout<<"\t\t\t SILAHKAN TAMBAHKAN BUKU TERLEBIH DAHULU "<<endl;
            garis();
            goto menu_utama;
        }

        cout<<" CARI BUKU BERDASARKAN JUDUL : ";
        cin>>cari;


        ketemu=0;
        for (int i = 1; i <= jml_buku; i++){
            if (b[i].judul_buku == cari){
                garis();
                ketemu = 1;
                cout<<" BUKU YANG ANDA CARI BERADA DI RAK KE " << i  << ".\n";
                //cout<<" JUDUL BUKU : "<< b[i].judul_buku;
                garis();
                cout << " |          JUDUL BUKU           |     ISBN     |  TAHUN TERBIT  |   PENGARANG   |\n";
                garis();
                cout<<setiosflags (ios::left)<<" |"<<setw (30)<<b[i].judul_buku;
                cout<<setiosflags (ios::left)<<" |   "<<setw (10)<<b[i].isbn;
                cout<<setiosflags (ios::left)<<" | "<<setw (14)<<b[i].tahun_terbit;
                cout<<setiosflags (ios::left)<<" |  "<<setw (8)<<b[i].pengarang<< "     |" << endl;
                garis();
            }
        }
        if(ketemu == 0){
            garis();
            cout<<" DATA BUKU TIDAK DITEMUKAN "<<endl;
            garis();
        }

        cout << " APAKAH ANDA INGIN MENCARI BUKU LAGI (Y/N)? ";
        cin >> pil;
        if (pil =='y'|| pil =='Y'){
            system("cls");
            goto cari_buku;
        }else if (pil =='n'|| pil =='N'){
            system ("cls");
            goto menu_utama;
        }else{
            cout<<" PILIHAN TIDAK TERSEDIA "<<endl;
            garis();
            system("pause");
            system ("cls");
            goto menu_utama;
        }

        return 0;

}
