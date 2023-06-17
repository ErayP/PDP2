#ifndef ATAKTIK_H
#define ATAKTIK_H
#include "Taktik.h"
struct ATAKTIK{
	Taktik super;
	void (*yoketA)(struct ATAKTIK*);
	int (*savas)();
};
typedef struct ATAKTIK* ataktik;
ataktik ataktik_Olustur();
int savas ();
void ayoket(const ataktik);
#endif