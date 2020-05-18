#include<iostream>
#include<stdlib.h>
using namespace std;

typedef string infotype;
typedef struct SLL* add;
typedef struct SLL{
	infotype Kode,Nama,Alamat,Cp;
	add next;
}ElmtL;

typedef struct{
	add first;
}Node;

#define Kode(P) (P)->Kode
#define Nama(P) (P)->Nama
#define Alamat(P) (P)->Alamat
#define Cp(P) (P)->Cp
#define Next(P) (P)->next
#define First(L) (L).first
#define Nil NULL

bool Kosong (Node L){
	return First(L)=NULL;
}

void CreateEmpty(Node* L){
	First(*L)=NULL;
}

add alokasi(infotype a,infotype b, infotype c, infotype d){
	add NewElmt;
	NewElmt = new(SLL);
	
	Kode(NewElmt)=a;
	Nama(NewElmt)=b;
	Alamat(NewElmt)=c;
	Cp(NewElmt)=d;
	
	return NewElmt;
}

void masuk(Node *L, infotype a,infotype b,infotype c,infotype d){
	add New=alokasi(a,b,c,d);
	add P=First(*L);
	if(NewElmt!=NULL){
		if(Kosong(*L)){
			First(*L)=NewElmt;
		}
		else{
			Next(New)=First(*L);
			First(*L)=NewElmt;
		}
	}
}

add cari(Node L, infotype a){
	add temp=First(L);
	
	while(temp!=NULL){
		if(temp->Kode==a){
			return temp;	
		}
		temp=Next(temp);
	}
		return NULL;
}

void ini(string a){
	Node L;
	CreateEmpty(&L);
	masuk(&L,"PE6","Aulia Belsasar Silalahi","jl. Aku Bersama Dia Selalu No.69","081263271637");
	masuk(&L,"PE5","Daniel Sipangkar","jl. Bersamanya No.46","081264391566");
	masuk(&L,"PE4","Hendri Kurniawan","jl. Terjal dan Berliku No.9","-");
	masuk(&L,"PE3","Yohannes F Silaen","jl. Samaku jadiannya sama dia No.3","-");
	masuk(&L,"PE2","Andika Saputra 4.0 ","jl. Hidup kita berbeda No.96","-");
	masuk(&L,"PE1","Alexande Diva G Bangun","jl. Sendirian No.1","-");
	add temp=cari(L,a);
	if(temp!=NULL){
		cout<<"ID Pemasok\t: "<<temp->Kode<<endl;
		cout<<"Nama Pemasok\t: "<<temp->Nama<<endl;
		cout<<"Alamat Pemasok\t: "<<temp->Alamat<<endl;
		cout<<"Contact Person\t: "<<temp->Cp<<endl;
	}
	else{
	
	cout<<"Data Pemasok Belum Ada \n";
	}
	
	
}
