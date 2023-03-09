#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

char str[8];

void donvi(char num)
{
    switch (num)
    {
    case '0':
        printf("khong");
        break;
    case '1':
        printf("mot ");
        break;
    case '2':
        printf("hai ");
        break;
    case '3':
        printf("ba ");
        break;
    case '4':
        printf("bon ");
        break;
    case '5':
        printf("nam ");
        break;
    case '6':
        printf("sau ");
        break;
    case '7':
        printf("bay ");
        break;
    case '8':
        printf("tam ");
        break;
    case '9':
        printf("chin ");
        break;
    }
}

void motchuso(int dv)
{
    donvi(str[dv]);
}
void haichuso(int chuc, int dv)
{
    if ((str[dv] == '0') && (str[chuc] != '1'))
    {
        donvi(str[chuc]);
        printf("muoi ");
    }
    else if ((str[dv] == '0') && (str[chuc] == '1'))
    {
        printf("muoi ");
    }
    else if ((str[dv] != '0') && (str[dv] != '5') && (str[chuc] != '1'))
    {
        donvi(str[chuc]);
        printf("muoi ");
        donvi(str[dv]);
    }
    else if ((str[chuc] == '1') && (str[dv] != '0') && (str[dv] != '5'))
    {
        printf("muoi ");
        donvi(str[dv]);
    }
    else if ((str[chuc] == '1') && (str[dv] == '5'))
    {
        printf("muoi lam ");
    }
    else if ((str[chuc] != '1') && (str[dv] == '5'))
    {
        donvi(str[chuc]);
        printf("muoi lam ");
    }
}
void bachuso(int tram, int chuc, int dv)
{
    if ((str[chuc] == '0') && (str[dv] == '0'))
    {
        donvi(str[tram]);
        printf("tram ");
    }
    else if ((str[chuc] == '0') && (str[dv] != '0'))
    {
        donvi(str[tram]);
        printf("tram le ");
        donvi(str[dv]);
    }
    else 
    {
        donvi(str[tram]);
        printf("tram ");
        haichuso(chuc, dv);
    }
  
}
void bonchuso(int ngan, int tram, int chuc, int dv)
{
    if ((str[tram] == '0') && (str[chuc] == '0') && (str[dv] == '0'))
    {
        donvi(str[ngan]);
        printf("ngan ");
    }
    else
    {
        donvi(str[ngan]);
        printf("ngan ");
        bachuso(tram, chuc, dv);
    }
}
void namchuso(int chucngan, int ngan, int tram, int chuc, int dv)
{
    if ((str[tram] == '0') && (str[chuc] == '0') && (str[dv] == '0'))
    {
        haichuso(chucngan, ngan);
        printf("ngan ");
    }
    else
    {
        haichuso(chucngan, ngan);
        printf("ngan ");
        bachuso(tram, chuc, dv);
    }
}
void sauchuso(int tramngan, int chucngan, int ngan, int tram, int chuc, int dv)
{
    if ((str[chucngan] == '0') && (str[ngan] == '0') && (str[tram] == '0') && (str[chuc] == '0') && (str[dv] == '0'))
    {
        bachuso(tramngan, chucngan, ngan);
        printf("ngan ");
    }
    else
    {
        bachuso(tramngan, chucngan, ngan);
        printf("ngan ");
        bachuso(tram, chuc, dv);
    }
}
void baychuso(int trieu, int tramngan, int chucngan, int ngan, int tram, int chuc, int dv)
{
    if ((str[tramngan] == '0') && (str[chucngan] == '0') && (str[ngan] == '0') && (str[tram] == '0') && (str[chuc] == '0') && (str[dv] == '0'))
    {
        donvi(str[trieu]);
        printf("trieu ");
    }
    else if (((str[tramngan] == '0') && (str[chucngan] == '0') && (str[ngan] == '0')) && ((str[tram] != '0') || (str[chuc] != '0') || (str[dv] != '0')))
    {
        donvi(str[trieu]);
        printf("trieu ");
        bachuso(tram, chuc, dv);
    }
    else
    {
        donvi(str[trieu]);
        printf("trieu ");
        sauchuso(tramngan, chucngan, ngan, tram, chuc, dv);
    }
}
int main()
{
    int a;
    printf("\nnhap so : ");
    scanf("%s", str);
    a = strlen(str); // lấy độ dài chuỗi
    printf("so %s doc la: \n", str);
    if (a == 1)
    {
        motchuso(0);
    }
    else if( (a >= 2) && (str[0] == '0') )
    {
        printf("\nso khong hop le");
    }
    else if (a == 2)
    {
        haichuso(0, 1);
    }
    else if (a == 3)
    {
        bachuso(0, 1, 2);
    }
    else if (a == 4)
    {
        bonchuso(0, 1, 2, 3);
    }
    else if (a == 5)
    {
        namchuso(0, 1, 2, 3, 4);
    }
    else if (a == 6)
    {
        sauchuso(0, 1, 2, 3, 4, 5);
    }
    else if (a == 7)
    {
        baychuso(0, 1, 2, 3, 4, 5, 6);
    }
    else printf("\nkhong doc duoc so lon hon bay chu so");
    return 0;
}