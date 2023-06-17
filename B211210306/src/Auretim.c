#include "AUretim.h"
#include "stdlib.h"
#include "time.h"
Auretim Auretim_Olustur(){
	Auretim this;
	this = (Auretim)malloc(sizeof(struct AURETIM));
	this->super = uretim_Olustur();
	this->super->uretim = &uretim;
	this->yoketuretimA = &yoketuretimA;
}
int uretim(const Auretim this){
	static int srand_called = 0;
    if (!srand_called) {
        srand(time(0));
        srand_called = 1;
    }
    
    int yemekUret = rand() % 11;
    return yemekUret;
}
void yoketuretimA(const Auretim this){
	if(this == NULL) return;
	this->super->uretimyoket(this->super);
	free(this);
}