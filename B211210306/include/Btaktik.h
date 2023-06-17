#ifndef BTAKTIK_H
#define BTAKTIK_H
#include "Taktik.h"
struct BTAKTIK{
	Taktik super;
	void (*yoketb)(struct BTAKTIK*);
	int (*savas)();
};
typedef struct BTAKTIK* Btaktik;
Btaktik btaktik_Olustur();
int savasB();
void yoketB (const Btaktik);
#endif