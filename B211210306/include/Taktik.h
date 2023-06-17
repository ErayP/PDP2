#ifndef TAKTIK_H
#define TAKTIK_H
#include "Koloni.h"
struct TAKTIK{
	
	int (*savas)();
	void (*yoket)(struct TAKTIK*);
	void (*rastgele_taktik)(struct TAKTIK* this,struct KOLONI* koloni1,struct KOLONI* koloni2,void*);
};
typedef struct TAKTIK *Taktik;

Taktik taktik_Olustur();
void taktik_Sil(const Taktik);
void rastgele_taktik(const Taktik this,Koloni koloni1,Koloni koloni2,void*);

#endif