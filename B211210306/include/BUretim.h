#ifndef BURETIM_H
#define BURETIM_H
#include "Uretim.h"
struct BURETIM{
	Uretim super;
	void (*yoketuretimB)(struct BURETIM*);
	int (*uretim)();
};
typedef struct BURETIM* Buretim;
Buretim Buretim_Olustur();
int uretimB();
void yoketuretimB(const Buretim);
#endif