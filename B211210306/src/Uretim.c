#include "Uretim.h"
Uretim uretim_Olustur(){
	Uretim this;
	this = (Uretim)malloc(sizeof(struct URETIM));
	this->uretimyoket = &uretimyoket;
	this->rastgele_uretim = &rastgele_uretim;
}
void uretimyoket(const Uretim this){
	if(this == NULL) return;
	free(this);
}
void rastgele_uretim(struct URETIM* this,struct KOLONI* koloni,void* x){
	if(koloni->populasyon > 1 && koloni->yemekStogu > 1){
		
		int uretilenYemek = this->uretim(x);
		koloni->yemekStogu = koloni->yemekStogu + uretilenYemek;
	}
	else{
		return;
	}
}