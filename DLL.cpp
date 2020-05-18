#include"iostream"
#include <stdlib.h>
#include "AOS.h"
#include "SLL.h"
using namespace std;
ostream& bold_on(ostream& os)
{
    return os << "\e[1m";
}

ostream& bold_off(ostream& os)
{
    return os << "\e[0m";
}
typedef string infotype;
typedef struct tElmtList* address; 
typedef struct tElmtList {
	infotype Trans, Masuk, Kopi, Pemasok;
	int Banyak, Harga, Total;
	address prev;
	address next;
} ElmtList;

typedef struct {
	address First;
	address Last;
} List;

#define Trans(P) (P)->Trans
#define Masuk(P) (P)->Masuk
#define Kopi(P) (P)->Kopi
#define Pemasok(P) (P)->Pemasok
#define Banyak(P) (P)->Banyak
#define Harga(P) (P)->Harga
#define Total(P) (P)->Total
#define Prev(P) (P)->prev
#define Next(P) (P)->next
#define First(L) ((L).First)
#define Last(L) ((L).Last)
#define Nil NULL

bool IsEmpty(List L) {
	return (First(L) == NULL && Last(L) == NULL);
}

void createList(List* L) {
	First(*L) = NULL;
	Last(*L) = NULL;
}

address Allocation(infotype a, infotype b, infotype c, infotype d,int e,int f,int g) {
	address NewElmt;
	NewElmt = new(tElmtList);

	Trans(NewElmt) = a;
	Masuk(NewElmt) = b;
	Kopi(NewElmt) = c;
	Pemasok(NewElmt) = d;
	Banyak(NewElmt)=e;
	Harga(NewElmt)=f;
	Total(NewElmt)=g;
	Next(NewElmt) = NULL;
	Prev(NewElmt) = NULL;
	return NewElmt;
}

void Deallocation(address hapus) {
	free(hapus);
}

address Search(List L, infotype a) {
	address P = First(L);

	while (P != Nil) {
		if (Trans(P) == a) {
			return P;
		}
		P = Next(P);
	}
	return Nil;
}

void InsertFirst(List* L, infotype a, infotype b, infotype c, infotype d,int e,int f,int g) {
	address NewElmt;
	NewElmt = Allocation(a,b,c,d,e,f,g);

	if (NewElmt != NULL) {
		if (IsEmpty(*L)) {
			First(*L) = NewElmt;
			Last(*L) = NewElmt;
		}
		else {
			Next(NewElmt) = First(*L);
			Prev(First(*L)) = NewElmt;
			First(*L) = NewElmt;
		}
	}
}

void InsertLast(List* L, infotype a, infotype b, infotype c, infotype d,int e, int f, int g) {
	address NewElmt;
	NewElmt = Allocation(a,b,c,d,e,f,g);

	if (NewElmt != NULL) {
		if (IsEmpty(*L)) {
			InsertFirst(L, a, b, c, d, e, f, g);
		}
		else {
			Next(Last(*L)) = NewElmt;
			Prev(NewElmt) = Last(*L);
			Last(*L) = NewElmt;
		}
	}
}

void insert(List* L,infotype a,infotype b,infotype c,infotype d,int e, int f, int g){
	address NewElmt=Allocation(a,b,c,d,e,f,g);
	address temp=First(*L);
	address P;
	
	while(Trans(temp)>a){
		P=temp;
		temp=Next(temp);
	}
	if(IsEmpty(*L)||temp==First(*L)){
		InsertFirst(&*L,a,b,c,d,e,f,g);
	}
	else if(temp=NULL){
		InsertLast(&*L,a,b,c,d,e,f,g);
	}
	else{
	
	Next(NewElmt)=temp;
	Prev(NewElmt)=P;
	Next(P)=NewElmt;
	Prev(temp)=NewElmt;
	
	}
}
void DelFirst(List* L, address* P) {
	*P = First(*L);
	First(*L) = Next(*P);
	Prev(First(*L)) = Nil;
	Deallocation(*P);
}

void DelLast(List* L, address* P) {
	*P = Last(*L);
	Last(*L) = Prev(*P);
	Next(Last(*L)) = Nil;
	Prev(*P) = Nil;
	Deallocation(*P);
}

void DelKosong(List *L,address P){
	createList(&*L);
	Deallocation(P);
}

void DelAfter(List* L, address* Pdel, address Prec) {
	*Pdel = Next(Prec);
	Next(Prec) = Next(*Pdel);
	Prev(Next(*Pdel)) = Prec;
	Prev(*Pdel) = Nil;
	Next(*Pdel) = Nil;
	Deallocation(*Pdel);
}

void Del(List *L){
	infotype a;
	if(IsEmpty(*L)){
		cout<<"List Masih Kosong, ";
	}
	else{
		cout<<"ID Transaksi : ";cin>>a;
	address temp=Search(*L,a);
		
		if(temp!=NULL){
			
	if(Prev(temp)==NULL && Next(temp)==NULL){
		DelKosong(&*L,temp);
	}
	else if(Prev(temp)==NULL){
		DelFirst(&*L,&temp);
	}
	else if(Next(temp)==NULL){
		DelLast(&*L,&temp);
	}
	else{
	
	Next(Prev(temp))=Next(temp);
	Prev(Next(temp))=Prev(temp);
	
	temp->next=NULL;
	temp->prev=NULL;
	Deallocation(temp);
	}
		}
		else{
			cout<<"ID "<<a<<"Tidak Ditemukan ";
		}
	}
}

void print(List L) {
	address temp;
	temp = First(L);
	int index = 0;
	if(IsEmpty(L))cout<<"List Masih Kosong, ";
	else{
		while (temp != NULL) {
			index++;
			cout << "#" << index << endl;
			cout << "ID Transaksi     : " << Trans(temp) << endl;
			cout << "Tanggal Masuk   : " << Masuk(temp) << endl;
			cout << "Harga Total : " <<Total(temp)<<endl;
			cout << endl;

			temp = Next(temp);
	}
	}
}
void printblakang(List L){
	address temp=Last(L);
	int index=0;
	if(IsEmpty(L)){
		cout<<"List Masih Kosong";
	}else{
		while (temp != NULL) {
			system("cls");
			cout<<"\t=========================================\t\n";
		cout<<"\t   SELAMAT DATANG DIGUDANG KOPI A'SEDE \t\t\n";
		cout<<"\t=========================================\t\n\n";
		
			cout<<bold_on<<"Tampilan Dari Belakang "<<bold_off<<endl<<endl;
			index++;
			cout << "#" << index << endl;
			cout << "ID Transaksi     : " << Trans(temp) << endl;
			cout << "Tanggal Masuk   : " << Masuk(temp) << endl;
			cout << "Harga Total : " <<Total(temp)<<endl;
			cout << endl;

			temp = Prev(temp);
		}
	}
}

void cetak(address temp) {
		cout<<"\t=========================================\t\n";
		cout<<"\t   SELAMAT DATANG DIGUDANG KOPI A'SEDE \t\t\n";
		cout<<"\t=========================================\t\n\n";
		cout<<bold_on<<"DATA TRANSAKSI "<<bold_off<<endl<<endl;
		cout << "ID Transaksi     : " << Trans(temp) << endl;
		cout << "Tanggal Masuk   : " << Masuk(temp) << endl;
		cout << "ID Kopi : " << Kopi(temp) << endl;
		cout << "Kode Pemasok : " << Pemasok(temp) << endl;
		cout<<"Harga Total : " <<Total(temp)<<endl;
		cout << endl;

}
void Update(List L){
	infotype a;
	
	if(IsEmpty(L)) cout<<"List Masih Kosong, ";
	else{
		cout<<"ID Transaksi : ";cin>>a;
		address temp=Search(L,a);
		if(temp!=NULL){
				infotype b,c,d,e;
		int f,g,h;
	system("cls");
		cout<<"\t=========================================\t\n";
		cout<<"\t   SELAMAT DATANG DIGUDANG KOPI A'SEDE \t\t\n";
		cout<<"\t=========================================\t\n\n";
	cout << "ID Transaksi     : "<<a<<endl;
	cout << "Tanggal Transaksi   : ";cin.ignore();getline(cin,c); Masuk(temp)=c;
	cout << "ID Kopi : ";cin>>d; Kopi(temp)=d;
	cout << "Kode Pemasok : ";cin>>e; Pemasok(temp)=e;
	cout<<"Banyak Kopi (Kg) : ";cin>>f; Banyak(temp)=f;
	cout<<"Harga Kopi (/Kg) : Rp ";cin>>g; Harga(temp)=g;
	h=f*g; Total(temp)=h;
	cout<<"Harga Total : Rp "<<h;
		}
		else{
			cout<<"Tidak Ditemukan Data Dengan ID: "<<a;
		}
	}
	
	
}

void cari(List L){
	infotype a;
		cout<<"\t=========================================\t\n";
		cout<<"\t   SELAMAT DATANG DIGUDANG KOPI A'SEDE \t\t\n";
		cout<<"\t=========================================\t\n\n";
	if(IsEmpty(L)){
		cout<<"List Masih Kosong, ";
		}else{
				
			cout<<"ID Transaksi : ";cin>>a;
			address temp=Search(L,a);
			if(temp!=NULL){
				system("cls");
				
				cetak(temp);
				cout<<endl;
				cout<<bold_on<<"DATA KOPI "<<bold_off<<endl<<endl;
				tunjuk(Kopi(temp));
				cout<<endl;
				cout<<bold_on<<"DATA PEMASOK "<<bold_off<<endl<<endl;
				ini(Pemasok(temp));
				cout<<endl;
				
			}
			else{
				cout<<"ID "<<a<<" Tidak Ditemukan ";
			}
			
	}
}
void tampil(){
	system("cls");
	List L;
	createList(&L);
	infotype transaksi,tanggal,kopi,pemasok,a;
	int banyak,harga, total,pilih;
	cout<<"\t=========================================\t\n";
	cout<<"\t   SELAMAT DATANG DIGUDANG KOPI A'SEDE \t\t\n";
	cout<<"\t=========================================\t\n\n";
	cout<<"Menu	:\n";
	cout<<"1. Stok Kopi \n";
	cout<<"2. Tambah Stok \n";
	cout<<"3. Update Data Kopi \n";
	cout<<"4. Hapus Data Kopi \n";
	cout<<"5. Cari Kopi \n";
	cout<<"6. Keluar \n\n";
	InsertLast(&L,"1234","28 Juli 2000","AR01","PE2",12,20000,12*20000);
	cout<<"Pilih : ";	cin>>pilih;
	while(pilih!=6){
		system("cls");
		if(pilih==1){
			system("cls");
			pilihulang:
		cout<<"\t=========================================\t\n";
		cout<<"\t   SELAMAT DATANG DIGUDANG KOPI A'SEDE \t\t\n";
		cout<<"\t=========================================\t\n\n";
		cout<<"1. Tampilka dari Depan \n";
		cout<<"2. Tampilkan dari Belakang \n";
		cout<<"Pilih : ";cin>>pilih;

		switch(pilih){
			case 1: 	print(L);
						cout<<endl;
						system("pause");
						break;
			case 2: printblakang(L);
					cout<<endl;
					system("pause");
					break;
			default: cout<<"Inputan Salah ";
						goto pilihulang;
					
		}
		
		}
		else if(pilih==2){
		cout<<"\t=========================================\t\n";
		cout<<"\t   SELAMAT DATANG DIGUDANG KOPI A'SEDE \t\t\n";
		cout<<"\t=========================================\t\n\n";

			cout << "ID Transaksi     : ";cin>>transaksi;
			cout << "Tanggal Transaksi   : ";cin.ignore();getline(cin,tanggal);
			cout << "ID Kopi : ";cin>>kopi;
			cout << "Kode Pemasok : ";cin>>pemasok;
			cout<<"Banyak Kopi (Kg) : ";cin>>banyak;
			cout<<"Harga Kopi (/Kg) : Rp ";cin>>harga;
			total=banyak*harga;
			cout<<"Harga Total : Rp "<<total;
			InsertLast(&L,transaksi,tanggal,kopi,pemasok,banyak,harga,total);
			cout<<endl;
			system("pause");
		}
		else if(pilih==3){
		cout<<"\t=========================================\t\n";
		cout<<"\t   SELAMAT DATANG DIGUDANG KOPI A'SEDE \t\t\n";
		cout<<"\t=========================================\t\n\n";

			
			Update(L);
			cout<<endl;
			system("pause");
			
		}
		else if(pilih==4){
		cout<<"\t=========================================\t\n";
		cout<<"\t   SELAMAT DATANG DIGUDANG KOPI A'SEDE \t\t\n";
		cout<<"\t=========================================\t\n\n";

		
			Del(&L);
			system("pause");
			
		}else if(pilih==5){
		cout<<"\t=========================================\t\n";
		cout<<"\t   SELAMAT DATANG DIGUDANG KOPI A'SEDE \t\t\n";
		cout<<"\t=========================================\t\n\n";

			system("CLS");
			cari(L);
			system("pause");
		}
		system("cls");
		cout<<"\t=========================================\t\n";
		cout<<"\t   SELAMAT DATANG DIGUDANG KOPI A'SEDE \t\t\n";
		cout<<"\t=========================================\t\n\n";
		cout<<"Menu	:\n";
		cout<<"3. Update Data  \n";
		cout<<"4. Hapus Data  \n";
		cout<<"5. Lihat Data  \n";
		cout<<"6. Keluar \n\n";
		cout<<"Pilih : ";cin>>pilih;
		}
	}
		cout<<"1. Stok Kopi \n";
		cout<<"2. Tambah Stok \n";
	



int main(){
	tampil();
	
	return 0;	
}
