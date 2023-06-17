#include "BUretim.h"
#include "stdlib.h"
#include "time.h"
Buretim Buretim_Olustur(){
	Buretim this;
	this = (Buretim)malloc(sizeof(struct BURETIM));
	this->super = uretim_Olustur();
	this->super->uretim = &uretimB;
	this->yoketuretimB = &yoketuretimB;
}
int uretimB(){
		static int srand_called = 0;
    if (!srand_called) {
        srand(time(0));
        srand_called = 1;
    }
    int yemekUret = rand() % 11+5;
    return yemekUret;
}
void yoketuretimB(const Buretim this){
	if(this == NULL) return;
	this->super->uretimyoket(this->super);
	free(this);
}