#include<stdio.h>
#include<stdlib.h>

struct dugum{
    int veri;
    struct dugum *sonraki;
};
struct dugum *start = NULL;

void goruntule(struct dugum *);
void ara(struct dugum *);
void dugumsay(struct dugum *);
void dugum_tekrarlari_sil(struct dugum *);
struct dugum *ekle_bas(struct dugum *);
struct dugum *ekle_son(struct dugum *);
struct dugum *ekle_once(struct dugum *);
struct dugum *ekle_sonra(struct dugum *);
struct dugum *sil_bas(struct dugum *);
struct dugum *sil_son(struct dugum *);
struct dugum *sil_sonra(struct dugum *);
struct dugum *sil_once(struct dugum *);
struct dugum *liste_olustur(struct dugum *);
struct dugum *sil_tum(struct dugum *);
struct dugum *sirala_kucukten_buyuge(struct dugum *);
struct dugum *sirala_buyukten_kucuge(struct dugum *);
struct dugum *listeyi_ters_cevir(struct dugum *);

void menu()
{
    int choice,devam;
    while (1)
    {
        printf("\n****** ANA MENU ******\n");
        printf(" 1: Liste oluştur\n");
        printf(" 2: Listeyi görüntüle\n");
        printf(" 3: Düğümlerde ara\n");
        printf(" 4: Düğümleri say\n");
        printf(" 5: En başa bir düğüm ekle\n");
        printf(" 6: En sona bir düğüm ekle\n");
        printf(" 7: Belirli bir düğümden öncesine düğüm ekle\n");
        printf(" 8: Belirli bir düğümden sonrasına düğüm ekle\n");
        printf(" 9: En baştaki düğümü sil\n");
        printf("10: En sondaki düğümü sil\n");
        printf("11: Belirli bir düğümden sonraki düğümü sil\n");
        printf("12: Belirli bir düğümden önceki düğümü sil\n");
        printf("13: Düğümlerin hepsini sil\n");
        printf("14: Düğümleri küçükten büyüğe sırala\n");
        printf("15: Düğümleri büyükten küçüğe sırala\n");
        printf("16: Listeyi tersine çevir\n");
        printf("17: Tekrar eden düğümleri sil\n");
        printf("18: Çıkış\n");
        printf("Seçiminizi yapın: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nBagli Liste Olusturuluyor...\n");
            start = liste_olustur(start);
            printf("\nBagli Liste Olusturuldu!\n");
            goruntule(start);
            printf("\n");
            break;

        case 2:
            printf("\nBagli Liste Goruntuleniyor...\n");
            goruntule(start);
            printf("\n");
            break;

        case 3:
            ara(start);
            printf("\n");
            break;

        case 4:
            printf("\nBagli listedeki dügümler sayiliyor...\n");
            dugumsay(start);
            break;

        case 5:
            start = ekle_bas(start);
            printf("Düğüm en başa eklendi.\n");
            break;

        case 6:
            start = ekle_son(start);
            printf("Düğüm en sona eklendi.\n");
            break;

        case 7:
            start = ekle_once(start);
            printf("Düğüm başarıyla eklendi.\n");
            break;

        case 8:
            start = ekle_sonra(start);
            printf("Düğüm başarıyla eklendi.\n");
            break;

        case 9:
            start = sil_bas(start);
            printf("\nEn baştaki düğüm silindi\n");
            break;

        case 10:
            start = sil_son(start);
            printf("\nEn sondaki düğüm silindi\n");
            break;

        case 11:
            start = sil_sonra(start);
            printf("Düğüm başarıyla silindi.\n");
            break;

        case 12:
            start = sil_once(start);
            printf("Düğüm başarıyla silindi.\n");
            break;

        case 13:
            start = sil_tum(start);
            printf("Bağlı listenin tamamen silindi.\n");
            break;

        case 14:
            start = sirala_kucukten_buyuge(start);
            printf("Bağlı liste küçükten büyüğe sıralandı.\n");
            break;

        case 15:
            start = sirala_buyukten_kucuge(start);
            printf("Bağlı liste büyükten küçüğe sıralandı.\n");
            break;

        case 16:
            start = listeyi_ters_cevir(start);
            printf("Bağlı liste ters çevirildi.\n");
            break;
        
        case 17:
            dugum_tekrarlari_sil(start);
            printf("Tekrar eden bağlı liste elemanları silindi\n");
            break;

        case 18:
            printf("Çıkış yapılıyor...\n");
            return; 
            break;

        default:
            printf("Geçersiz seçim, tekrar deneyin.\n");
            break;
        }}}

int main()
{
    menu();
    return 0;
}

struct dugum *liste_olustur(struct dugum *start) //=> 1
{
    struct dugum *yeni_dugum, *ptr;
    int sayi;
    printf("\nSonlandirmak icin -1 girin");
    printf("\nVeriyi girin: ");
    scanf("%d", &sayi);
    
    while(sayi != -1)
    {
        yeni_dugum = (struct dugum *)malloc(sizeof(struct dugum));
        yeni_dugum->veri = sayi;
        
        if(start == NULL)
        {
            yeni_dugum->sonraki = NULL;
            start = yeni_dugum;
        }
        else
        {
            ptr = start;
            
            while(ptr->sonraki != NULL)
                ptr = ptr->sonraki;
            
            ptr->sonraki = yeni_dugum;
            yeni_dugum->sonraki = NULL;
        }
        printf("Veriyi girin: ");
        scanf("%d", &sayi);
    }
    return start;
}

void goruntule(struct dugum *start) //=> 2
{
    struct dugum *ptr;
    ptr = start;
    while(ptr != NULL)
    {
        printf(" %d\t",ptr->veri);
        ptr = ptr->sonraki;
    }
}

void ara(struct dugum *start) //=> 3
{
    struct dugum *ptr;
    ptr = start;
    int deger;
    printf("\nAranacak değeri gir: ");
    scanf("%d",&deger);
    while(ptr != NULL)
    {
        if(deger == ptr->veri)
        {
            printf("Aranan değer \"%d\" listede bulundu.",deger);
            break;
        }
        else
         ptr = ptr->sonraki;
    }
    if(ptr == NULL)
    {
        printf("Aranan değer \"%d\" listede bulunamadı.",deger);
    }
}

void dugumsay(struct dugum *start) //=> 4
{
    struct dugum *ptr;
    ptr = start;
    int sayac = 0;
    while(ptr != NULL)
    {
        sayac++;
        ptr = ptr->sonraki;
    }
    printf("Düğüm sayısı = %d\n",sayac);
}

struct dugum *ekle_bas(struct dugum *start) //=> 5
{
    struct dugum *ptr;
    int veri;
    printf("\nVeriyi gir: ");
    scanf("%d",&veri);

    ptr = (struct dugum *)malloc(sizeof(struct dugum));
    ptr->veri = veri;
    ptr->sonraki = start;
    start = ptr;
    return start;
}

struct dugum *ekle_son(struct dugum *start) //=> 6
{
    struct dugum *yeni_dugum, *ptr;
    int sayi;
    printf("\nVeriyi girin: ");
    scanf("%d", &sayi);
    
    yeni_dugum = (struct dugum *)malloc(sizeof(struct dugum));
    yeni_dugum->veri = sayi;
    yeni_dugum->sonraki = NULL;
    
    ptr = start;
    while(ptr->sonraki != NULL)
        ptr = ptr->sonraki;
    
    ptr->sonraki = yeni_dugum;
    return start;
}

struct dugum *ekle_once(struct dugum *start) //=> 7
{
    struct dugum *yeni_dugum, *ptr, *preptr;
    int sayi, deger;
    printf("\nVeriyi girin: ");
    scanf("%d", &sayi);    
    printf("\nHangi degerden once eklemek istiyorsunuz: ");
    scanf("%d", &deger);
    
    yeni_dugum = (struct dugum *)malloc(sizeof(struct dugum));
    yeni_dugum->veri = sayi;
    ptr = start;   
    preptr = ptr;
    
    while(ptr->veri != deger)
    {
        preptr = ptr;        
        ptr = ptr->sonraki;
    }    
    preptr->sonraki = yeni_dugum;
    yeni_dugum->sonraki = ptr;    
    return start;
}

struct dugum *ekle_sonra(struct dugum *start) //=> 8
{
    struct dugum *yeni_dugum, *ptr, *preptr;
    int sayi, deger;
    printf("\nVeriyi girin: ");
    scanf("%d", &sayi);
    printf("\nHangi degerden sonra eklemek istiyorsunuz: ");    
    scanf("%d", &deger);
    
    yeni_dugum = (struct dugum *)malloc(sizeof(struct dugum));
    yeni_dugum->veri = sayi;
    ptr = start;    
	preptr = ptr;
    
    while(preptr->veri != deger)
    {
        preptr = ptr;        
		ptr = ptr->sonraki;
    }    
    preptr->sonraki = yeni_dugum;
    yeni_dugum->sonraki = ptr;    
    return start;
}

struct dugum *sil_bas(struct dugum *start) //=> 9
{
    struct dugum *ptr;
    ptr = start;
    start = start->sonraki;
    free(ptr);
    return start;
}

struct dugum *sil_son(struct dugum *start) //=> 10
{
    struct dugum *ptr, *preptr;
    ptr = start; 
    preptr = ptr;
    
    while(ptr->sonraki != NULL)
    {
        preptr = ptr; ptr = ptr->sonraki;
    }
    preptr->sonraki = NULL;
    free(ptr);
    return start;
}

struct dugum *sil_sonra(struct dugum *start) //=> 11
{
    struct dugum *ptr, *preptr;
    int deger;
    printf("\nHangi degerden sonrasini silmek istiyorsunuz: ");
    scanf("%d", &deger);
    ptr = start;
    preptr = ptr;
    
    while(preptr->veri != deger)
    {
        preptr = ptr;
        ptr = ptr->sonraki;
    }
    preptr->sonraki = ptr->sonraki;
    free(ptr);    
    return start;
}

struct dugum *sil_once(struct dugum *start) //=> 12
{
    struct dugum *ptr = start, *preptr = NULL;
    int deger;
    printf("\nHangi degerden oncesini silmek istiyorsunuz: ");
    scanf("%d", &deger);
    while(ptr->sonraki != NULL && ptr->sonraki->veri != deger)
    {
        preptr = ptr;
        ptr = ptr->sonraki;
    }
    
    if(preptr == NULL) 
        start = ptr->sonraki;
    else
        preptr->sonraki = ptr->sonraki;
    free(ptr);
    return start;
}

struct dugum *sil_tum(struct dugum *start) //=> 13
{
    struct dugum *ptr, *next_ptr;
    ptr = start;
    while(ptr != NULL)
    {
        next_ptr = ptr->sonraki; 
        free(ptr);
        ptr = next_ptr; 
    }
    start = NULL; 
    return start;
}

struct dugum *sirala_kucukten_buyuge(struct dugum *start) //=> 14
{
    struct dugum *ptr1, *ptr2;
    int temp;
    for (ptr1 = start; ptr1->sonraki != NULL; ptr1 = ptr1->sonraki) 
    {
        for (ptr2 = start; ptr2->sonraki != NULL; ptr2 = ptr2->sonraki) 
        {
            if (ptr2->veri > ptr2->sonraki->veri) 
            { 
                temp = ptr2->veri;
                ptr2->veri = ptr2->sonraki->veri;
                ptr2->sonraki->veri = temp;
            }}}
    return start;
}

struct dugum *sirala_buyukten_kucuge(struct dugum *start) //=> 15
{
    struct dugum *ptr1, *ptr2;
    int temp;
    for (ptr1 = start; ptr1->sonraki != NULL; ptr1 = ptr1->sonraki) 
    {
        for (ptr2 = start; ptr2->sonraki != NULL; ptr2 = ptr2->sonraki) 
        {
            if (ptr2->veri < ptr2->sonraki->veri) 
            { 
                temp = ptr2->veri;
                ptr2->veri = ptr2->sonraki->veri;
                ptr2->sonraki->veri = temp;
            }}}
    return start;
}

struct dugum *listeyi_ters_cevir(struct dugum *start) //=> 16
{
    struct dugum *preptr = NULL;   
    struct dugum *ptr = start; 
    struct dugum *next_ptr = NULL;   
    while (ptr != NULL) 
    {
        next_ptr = ptr->sonraki; 
        ptr->sonraki = preptr; 
        preptr = ptr;          
        ptr = next_ptr;         
    }
    start = preptr; 
    return start;
}

void dugum_tekrarlari_sil(struct dugum *start) //=> 17
{
    struct dugum *ptr1, *ptr2, *dup;
    ptr1 = start;
    while (ptr1 != NULL && ptr1->sonraki != NULL) 
    {
        ptr2 = ptr1;
        while (ptr2->sonraki != NULL) 
        {
            if (ptr1->veri == ptr2->sonraki->veri) 
            {
                dup = ptr2->sonraki;
                ptr2->sonraki = ptr2->sonraki->sonraki;
                free(dup);
            } 
            else 
            {
                ptr2 = ptr2->sonraki;
            }
        }
        ptr1 = ptr1->sonraki;
    }
}