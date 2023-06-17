#include "TAKTIK.H"
Taktik taktik_Olustur(){
	Taktik this;
	this = (Taktik)malloc(sizeof(struct TAKTIK));
	this->yoket =&taktik_Sil;
	this->rastgele_taktik = &rastgele_taktik;
}
	
void rastgele_taktik(const Taktik this,Koloni koloni1,Koloni koloni2,void* x){
	if(koloni1->populasyon> 1 && koloni2->populasyon > 1 && koloni1->yemekStogu >1 && koloni2-> yemekStogu)
	{
		koloni1->taktikDegeri = this->savas(x);
		koloni2->taktikDegeri = this->savas(x);
		int sonuc = abs((koloni1->taktikDegeri) - (koloni2->taktikDegeri));
		int yuzde = sonuc/10;
		int popCikar = 0;
		if(koloni1->taktikDegeri > koloni2->taktikDegeri) {
			popCikar = ((koloni2->populasyon)*yuzde)/100;
			koloni2->populasyon = koloni2->populasyon - popCikar;
			koloni1->yemekStogu = koloni1->yemekStogu + popCikar;
			koloni2->yemekStogu = koloni2->yemekStogu - popCikar;
			koloni1->kazanma++;
			koloni2->kaybetme++;
		} else if(koloni1->taktikDegeri < koloni2->taktikDegeri){
			popCikar = ((koloni1->populasyon)*yuzde)/100;
			koloni1->populasyon = koloni1->populasyon - popCikar;
			koloni2->yemekStogu = koloni2->yemekStogu + popCikar;
			koloni1->yemekStogu = koloni1->yemekStogu - popCikar;
			koloni2->kazanma++;
			koloni1->kaybetme++;
		}
		else{
			if(koloni1->populasyon >= koloni2->populasyon){
				popCikar = ((koloni2->populasyon)*yuzde)/100;
				koloni2->populasyon = koloni2->populasyon - popCikar;
				koloni1->yemekStogu = koloni1->yemekStogu + popCikar;
				koloni2->yemekStogu = koloni2->yemekStogu - popCikar;
				koloni1->kazanma++;
				koloni2->kaybetme++;
			}
			else{
				popCikar = ((koloni1->populasyon)*yuzde)/100;
				koloni1->populasyon = koloni1->populasyon - popCikar;
				koloni2->yemekStogu = koloni2->yemekStogu + popCikar;
				koloni1->yemekStogu = koloni1->yemekStogu - popCikar;
				koloni2->kazanma++;
				koloni1->kaybetme++;
			}
		}
	}
	else{
		return;
	}
}
void taktik_Sil(const Taktik this){
	if(this == NULL) return;
	free(this);
}