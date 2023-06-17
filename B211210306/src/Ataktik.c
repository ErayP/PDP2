#include "Ataktik.h"
#include "stdlib.h"
#include "time.h"
ataktik ataktik_Olustur(){
	ataktik this;
	this = (ataktik)malloc(sizeof(struct ATAKTIK));
	this->super = taktik_Olustur();
	this->super->savas=&savas;
	this->yoketA=&ayoket;
	return this;
}
int savas(const ataktik this) {
    static int srand_called = 0;
    if (!srand_called) {
        srand(time(0));
        srand_called = 1;
    }
    
    int savaspuani = rand() % 1001;
    return savaspuani;
}
void ayoket(const ataktik this){
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}