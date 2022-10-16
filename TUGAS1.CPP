#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#define nmax 5 

using namespace std;

int n = 0;
struct data
{
    int nim;
    char nama[30], kom;
};

struct data maba[nmax]; 
void tambah_data();     
void hapus_data();
void tampilkan_data();
void edit_data();

int main()
{
    int pil;
	menu:
    cout << "===========MENU==========\n";
    cout << "||1. Tambah Data       ||\n";
    cout << "||2. Hapus Data        ||\n";
    cout << "||3. Tampilkan Data    ||\n";
    cout << "||4. Edit Data         ||\n";
    cout << "||5. Keluar            ||\n";
    cout << "||=====================||\n";
    cout << "\nPilih Menu: "; cin >> pil;
    system("cls");
    
    if (pil == 1)
        tambah_data();
    else if (pil == 2)
        hapus_data();
    else if (pil == 3)
        tampilkan_data();
    else if (pil == 4)
        edit_data();
    else if (pil == 5)
        exit(1); 
    else
    {
        cout << "Pilih yang sesuai di menu!\n\n";
    }
    goto menu;
    getch();
}

void tambah_data()
{
    if (n < nmax)
    {
        cout << "Nama : ";
        cin >> maba[n].nama;
        cout << "NIM  : ";
        cin >> maba[n].nim;
        cout << "Kom  : ";
        cin >> maba[n].kom;
        n++;
        system("cls");
    }
    else
        cout << "\n Data telah melebihi maksimal data (" << nmax << ")\n\n";
}

void hapus_data()
{
    int x;
    cout << "Pilih data yang akan dihapus (1 - 5) : ";
    cin >> x;
    if (x < n && x > 0)
    {
        for (int i = x; i < n; i++)
        {
            strcpy(maba[i - 1].nama, maba[x].nama);
            maba[i - 1].nim = maba[x].nim;
            maba[i - 1].kom = maba[x].kom;
        }
        n--;
    }
    else if (x == n)
        n--;
    else
        cout << "\nData yang ingin dihapus tidak tersedia!\n\n";
}

void tampilkan_data()
{
    if (n == 0)
        cout << "Tidak ada data yang disimpan!\n\n";
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Data ke-" << i + 1 << " : ";
            cout << "\nNama : " << maba[i].nama;
            cout << "\nNIM  : " << maba[i].nim;
            cout << "\nKom  : " << maba[i].kom;
            cout << "\n\n";
            cout << endl;
        }
    }
}

void edit_data()
{
    int i, b_edit;
    cout << "Pilih data yang akan diedit: "; cin >> i;
    if ((n-i)>=0 && (i-1>=0)) {
        cout << "\n1. Nama";
        cout << "\n2. NIM";
        cout << "\n3. Kom";
        cout << "\n4. Nama, NIM, Kom\n" << endl;
	    cout << "Pilih bagian yang ingin diedit: "; cin >> b_edit;
        	
    	if (b_edit == 1){
    		cout << "Nama : "; cin >> maba[i-1].nama;
    		cout << endl;
    	}
    	
    	if (b_edit == 2){
    		cout << "NIM  : "; cin >> maba[i-1].nim;
    		cout << endl;
    	}
    	
    	if (b_edit == 3){
    		cout << "Kom  : "; cin >> maba[i-1].kom;
    		cout << endl;
    	}
    	
    	if(b_edit == 4){
    		cout << "Nama : "; cin >> maba[i-1].nama;
			cout << "NIM  : "; cin >> maba[i-1].nim;
			cout << "Kom  : "; cin >> maba[i-1].kom;
			cout << endl;   
		}
    }
    else
        cout << "\nTidak ada data yang dipilih\n\n";
}
