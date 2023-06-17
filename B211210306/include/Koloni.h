#ifndef KOLONI_H
#define KOLONI_H
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"
struct KOLONI{
	int populasyon;
	int yemekStogu;
	int kazanma;
	int kaybetme;
	int taktikDegeri;
	char sembol;
	int oyunBitsin;
	void (*Koloni_sil)(struct KOLONI*);
	char *(*yazdir)(struct KOLONI*);
};
typedef struct KOLONI *Koloni;
Koloni koloni_Olustur(int,int);
void koloni_Sil(const Koloni);
char *toString(const Koloni);
#endif