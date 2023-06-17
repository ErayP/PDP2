#include "Koloni.h"
#include "Taktik.h"
#include "Ataktik.h"
#include "Btaktik.h"
#include "Uretim.h"
#include "AUretim.h"
#include "BUretim.h"
#include "Oyun.h"
int main(){
    int sayilar[100];
    int adet = 0;
    int num;
	int sums = 0;
    printf("Sayilari girin (girmeyi bitirmek icin Enter'a basin):\n");
	ataktik taktik1 = ataktik_Olustur();
	Btaktik taktik2 = btaktik_Olustur();
	Auretim uretim1 = Auretim_Olustur();
	Buretim uretim2 = Buretim_Olustur();
	oyun Oyun = oyun_Olustur();
    while (1) {
        char karakter = getchar();
        if (karakter == '\n') {
            break;
        }
        ungetc(karakter, stdin);
        scanf("%d", &num);
        sayilar[adet] = num;
        adet++;
    }
	Koloni koloniler[adet];
	char *str[adet];
	for(int i = 0;i<adet;i++){
		koloniler[i] = koloni_Olustur(sayilar[i],21+i);
	}
	int tur_sayisi=1;
	while(1){
		static int srand_called = 0;
		if (!srand_called) {
			srand(time(0));
			srand_called = 1;
		}
    
		int rastgeleSayi = rand();
		system("CLS");
		sums = 0;
		for(int j = 0;j<adet;j++){
			sums += koloniler[j]->oyunBitsin;
		}
		printf("Tur sayisi : %d \n",tur_sayisi);
		printf("Sembol  Populasyon  Yemek Stogu  Kazanma Kaybetme \n");
		printf("------------------------------------------------- \n");
		for(int i = 0;i<adet;i++){
			str[i]=koloniler[i]->yazdir(koloniler[i]);
			printf("%s",str[i]);
		}
		printf("------------------------------------------------- \n");
		for(int a = 0;a < adet-1;a++){
			for(int b = 0; b < adet;b++){
				if(rastgeleSayi%2==0){
					taktik1->super->rastgele_taktik(taktik1->super,koloniler[a],koloniler[b],taktik1);
				}
				else{
					taktik2->super->rastgele_taktik(taktik2->super,koloniler[a],koloniler[b],taktik2);
				}
			}
		}
		for(int a = 0; a < adet;a++){
			if(rastgeleSayi%2==0){
				uretim2->super->rastgele_uretim(uretim2->super,koloniler[a],uretim2);
			}
			else{
				uretim1->super->rastgele_uretim(uretim1->super,koloniler[a],uretim1);
			}
		}
		for(int a = 0; a < adet;a++){
			Oyun->tur_islemleri(koloniler[a]);
		}
		tur_sayisi++;
		if(sums == 1){
			break;
		}
	}
	for(int x = 0;x<adet;x++){
		koloniler[x]->Koloni_sil(koloniler[x]);
		free(str[x]);
	}
	taktik1->yoketA(taktik1);
	taktik2->yoketb(taktik2);
	uretim1->yoketuretimA(uretim1);
	uretim2->yoketuretimB(uretim2);
	Oyun->oyunyoket(Oyun);
	return 0;
}