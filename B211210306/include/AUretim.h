#ifndef AURETIM_H
#define AURETIM_H
#include "Uretim.h"
struct AURETIM{
	Uretim super;
	void (*yoketuretimA)(struct AURETIM*);
	int (*uretim)();
};
typedef struct AURETIM* Auretim;
Auretim Auretim_Olustur();
int uretim();
void yoketuretimA(const Auretim);
#endif