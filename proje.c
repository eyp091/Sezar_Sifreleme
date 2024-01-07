#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

char ogrAd[10];
int anahtar;
char sifreliMetin[20];
char sifreCozumu[20];
int max;
int ogrno;

struct ogrbilgi{
    char ogrSoyad[10];
};

int sifreleme()
{
    struct ogrbilgi ogrb;

    printf("Ogrenci Adi: ");
    scanf("%s",ogrAd);

    printf("Ogrenci Soyadi: ");
    scanf("%s",ogrb.ogrSoyad);

    while(1==1)
    {
        printf("\nOgrenci Numaranizi Girin: ");
        scanf("%d",&ogrno);

        printf("Anahtar olarak ogrenci numaranizin son basamagini girin.\n");
        printf("Eger ogrenci numaranizin son basamagi 0 ise 0 olmayan son basamagi girin: ");
        scanf("%d",&anahtar);
        if((ogrno%10) == anahtar)
        {
            break;
        }
        else
        {
            printf("\nAnahtari ya da ogrenci numarasini yanlis girdiniz!\n");
            printf("Tekrar deneyin.\n\n");
        }
    }


    printf("\n");
    strcat(ogrAd,ogrb.ogrSoyad);

    int i;
    for(i = 0;ogrAd[i] != '\0';++i)
    {
        sifreliMetin[i] = ogrAd[i];
        if(sifreliMetin[i] >= 'a' && sifreliMetin[i] <= 'z')
        {
            sifreliMetin[i] = sifreliMetin[i] + anahtar;
            if(sifreliMetin[i] > 'z')
            {
                sifreliMetin[i] = sifreliMetin[i] - 'z' + 'a' -1;
            }
            ogrAd[i] = sifreliMetin[i];
        }
        else if(sifreliMetin[i] >= 'A' && sifreliMetin[i] <= 'Z')
        {
            sifreliMetin[i] = sifreliMetin[i] + anahtar;
            if(sifreliMetin[i] > 'Z')
            {
                sifreliMetin[i] = sifreliMetin[i] - 'Z' + 'A' -1;
            }
            ogrAd[i] = sifreliMetin[i];
        }
    }

}

void DosyayaEkleme()
{
    FILE *fp;
    fp = fopen("C:\\Users\\escan\\Desktop\\Projeler\\sifrelimetin.txt","w+");

    if(fp == NULL)
    {
        printf("Dosya acilamadi!");
        exit(1);
    }

    fputs(sifreliMetin,fp);
    fclose(fp);
}

int asalCarpanBulma()
{


    int k ;
    max = -1;
    while(ogrno%2 == 0)
    {
        max = 2;
        ogrno = ogrno/2;
    }
    for(k = 3;k <= sqrt(ogrno);k = k+2)
    {
        while(ogrno%k == 0)
        {
            max = k;
            ogrno = ogrno/k;
        }
    }
    if(ogrno>2)
    {
        max = ogrno;
    }

    return max;
}

int sifrelemCozumu()
{
    int j;
    for (j = 0; sifreliMetin[j] != '\0'; ++j)
    {
        sifreCozumu[j] = sifreliMetin[j];
        if(sifreCozumu[j] >= 'a' && sifreCozumu[j] <= 'z')
        {
            sifreCozumu[j] = sifreCozumu[j] - anahtar;
            if(sifreCozumu[j] < 'a')
            {
                sifreCozumu[j] = sifreCozumu[j] + 'z' - 'a' +1;
            }
            sifreliMetin[j] = sifreCozumu[j];
        }
        else if(sifreCozumu[j] >= 'A' && sifreCozumu[j] <= 'Z')
        {
            sifreCozumu[j] = sifreCozumu[j] - anahtar;
            if(sifreCozumu[j] < 'A')
            {
                sifreCozumu[j] = sifreCozumu[j] + 'Z' - 'A' +1;
            }
            sifreliMetin[j] = sifreCozumu[j];
        }
    }
}

int main() {

    printf("*****-----SEZAR SIFRELEME PROGRAMI-----*****\n");

    sifreleme();
    DosyayaEkleme();
    asalCarpanBulma();
    sifrelemCozumu();


    int cevap;


    FILE *fpp;
    fpp = fopen("C:\\Users\\escan\\Desktop\\Projeler\\sifrelimetin.txt","r+");

    if(fpp == NULL)
    {
        printf("Dosya acilamadi!!");
    }
    char dosya[20];
    fgets(dosya,20,fpp);

    while(1==1)
    {
        printf("Sifrenizi Girin: ");
        scanf("%d",&cevap);
        if(cevap == max)
        {
            printf("Sifre kontrol ediliyor.....\n");
            sleep(1);
            printf("\nSifreli Metin: %s\n",dosya);
            printf("Cozulmus Metin: %s",sifreCozumu);
            break;
        }
        else
        {
            printf("Hatali Sifre Girdiniz!\n");
            printf("Tekrar Deneyin.\n");
        }
    }
    printf("\n**********----------**********");

    return 0;
}
