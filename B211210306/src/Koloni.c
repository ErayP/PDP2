#include "Koloni.h"
Koloni koloni_Olustur(int deger,int sembol){
	Koloni this;
	this = (Koloni)malloc(sizeof(struct KOLONI));
	this->populasyon = deger;
	this->yemekStogu = deger*deger;
	this->kazanma = 0;
	this->kaybetme = 0;
	this->sembol = (char)sembol;
	this->yazdir = &toString;
	this->Koloni_sil = &koloni_Sil;
	this->taktikDegeri = 0;
	this->oyunBitsin = 1;
	
	return this;
}
void koloni_Sil(const Koloni this){
	if(this == NULL) return;
	free(this);
}
int uzunlukGetir(int val){
	char str[50];
	sprintf(str,"%d",val);
	int uzunluk = strlen(str);
	return uzunluk;
}
char *toString(const Koloni this){
	int toplamUzunluk = 1;
	toplamUzunluk += uzunlukGetir(this->populasyon);
	toplamUzunluk += uzunlukGetir(this->yemekStogu);
	toplamUzunluk += uzunlukGetir(this->kaybetme);
	toplamUzunluk += uzunlukGetir(this->kazanma);
	char *str = (char*)malloc(sizeof(char)*toplamUzunluk+55);
	if(this->yemekStogu > 1 && this->populasyon > 1){
		sprintf(str,"  %c       %d           %d          %d        %d\n",this->sembol,this->populasyon,this->yemekStogu,this->kazanma,this->kaybetme);
	}
	else{
		str = "  --      --           --          --        --\n";
		this->oyunBitsin = 0;
	}
	return str;
}