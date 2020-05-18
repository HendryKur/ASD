#include <iostream>
using namespace std;

struct stok{
	string ID, jenis, kematangan, air;
};

void tunjuk(string a){
	stok kopi[5];
	kopi[0].ID = "RB01";
	kopi[0].jenis = "Robusta";
	kopi[0].kematangan = "80%";
	kopi[0].air = "20%";
	
	kopi[1].ID = "RB02";
	kopi[1].jenis = "Robusta";
	kopi[1].kematangan = "70%";
	kopi[1].air = "15%";
	
	kopi[2].ID = "AR01";
	kopi[2].jenis = "Arabika";
	kopi[2].kematangan = "95%";
	kopi[2].air = "15%";
	
	kopi[3].ID = "RB03";
	kopi[3].jenis = "Robusta";
	kopi[3].kematangan = "90%";
	kopi[3].air = "20%";
	
	kopi[4].ID = "AR02";
	kopi[4].jenis = "Arabika";
	kopi[4].kematangan = "70%";
	kopi[4].air = "15%";
	int i=0;
	while(i!=5){
		if(a==kopi[i].ID){
			cout<<"ID Kopi\t: "<<kopi[i].ID<<endl;
			cout<<"Jenis Kopi\t: "<<kopi[i].jenis<<endl;
			cout<<"Tingkat Kematangan\t: "<<kopi[i].kematangan<<endl;
			cout<<"Kadar Air\t: "<<kopi[i].air<<endl<<endl;
		}
		i++;
	}
	if(i==5){
		cout<<"Data Kopi belum Ada";
	}	
}
