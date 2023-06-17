#ifndef OYUN_H
#define OYUN_H
#include "Koloni.h"
struct OYUN{
	void (*tur_islemleri)(struct KOLONI*);
	void (*oyunyoket)(struct OYUN*);
};
typedef struct OYUN* oyun;
oyun oyun_Olustur();
void tur_islemleri(struct KOLONI*);
void oyunyoket(const oyun);
#endif