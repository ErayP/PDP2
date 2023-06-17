#include "Btaktik.h"
#include "stdlib.h"
#include "time.h"
Btaktik btaktik_Olustur(){
	Btaktik this;
	this = (Btaktik)malloc(sizeof(struct BTAKTIK));
	this->super = taktik_Olustur();
	this->super->savas = &savasB;
	this->yoketb = &yoketB;
	return this;
}
int savasB(const Btaktik this) {
    static int srand_called = 0;
    if (!srand_called) {
        srand(time(0));
        srand_called = 1;
    }
    
    int savaspuani = rand() % 1001+500;
    return savaspuani;
}
void yoketB(const Btaktik this){
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}