#include "Oyun.h"
oyun oyun_Olustur(){
	oyun this;
	this = (oyun)malloc(sizeof(struct OYUN));
	this->tur_islemleri = &tur_islemleri;
	this->oyunyoket = &oyunyoket;
}
void tur_islemleri(struct KOLONI* koloni){
	koloni->populasyon = koloni->populasyon*1.2;
	koloni->yemekStogu = koloni->yemekStogu - 2*koloni->populasyon;
}
void oyunyoket(const oyun this){
	if(this == NULL) return;
	free(this);
}