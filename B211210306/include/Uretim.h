#ifndef URETIM_H
#define URETIM_H
#include "Koloni.h"
struct URETIM{
	int (*uretim)();
	void (*uretimyoket)(struct URETIM*);
	void(*rastgele_uretim)(struct URETIM*,struct KOLONI*,void*);
};
typedef struct URETIM* Uretim;
Uretim uretim_Olustur();
void uretimyoket(const Uretim);
void rastgele_uretim(const Uretim,Koloni,void*);
#endif