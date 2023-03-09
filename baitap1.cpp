#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

//mang bat ky vd arr[] = {1, 7, 8, 2, 3, 8, 3, 7, 6, 7, 8, 8, 2}
// sap xep mang theo thu tu tang dan
// liet ke cac phan tu co so lan xuat hien vd: 1 xuat hien 1 lan
//                                             7 xuat hien 2 lan
//                                             8 xuat hien 3 lan

typedef struct{
    uint8_t size;
    uint8_t *firstAdd;
}typeArray;

int randomA(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}

void randomArray(typeArray *value, uint8_t length){
    srand((int)time(0));

    value->size = length;

    value->firstAdd = (uint8_t *)malloc(sizeof(uint8_t)*value->size);
    int r;
    for(int i = 0; i < value->size; ++i){
        value->firstAdd[i] = randomA(1,10);
    }    
}
void shortarray (typeArray *value)
{
    
    uint8_t tem ;
    for(int i = 0; i < (value->size) - 1; i++){
        for(int j = i + 1; j < value ->size; j++){
            if(value->firstAdd[i] > value->firstAdd[j])
            {
                tem = value->firstAdd[i];
                value->firstAdd[i] = value->firstAdd[j];
                value->firstAdd[j] = tem;
      
            }
        }
    } 
               for(int i = 0; i < value->size; i++)
    {
         printf("arr[%d] = %d\n",i, value ->firstAdd[i]);
    }
   

}
void coutarray1(typeArray *value)
{
    uint8_t dem =1;
    for(int i = 0; i < value->size; i++)
    {
        
        if(value->firstAdd[i] == value->firstAdd[i+1])
        {
            dem = dem + 1;
        }
        else 
        {
            
            printf ("\nvalue[%d] xuat hien %d lan!",value->firstAdd[i] , dem);
            dem = 1;
        }
    }

}
void coutarry2(typeArray *value)
{
    uint8_t dem =1;
    for(int i = 0; i < value->size; i++)
    {
        if(value->firstAdd[i] == 0)
        {
            dem++;
        }
        
    }
    printf("\nvalue[0] xuat hien %d lan!", dem);
            dem = 1;
    
    for(int i = 0; i < value->size; i++)
    {
         for(int j = i + 1; j < value ->size; j++)
         {
            if(value->firstAdd[i] == value->firstAdd[j] && value->firstAdd[j] != 0 )
            {
                dem++;
                value->firstAdd[j] = 0; 
               
               
            }
             

         }
         printf("\nvalue [%d] xuat hien %d lan!",value->firstAdd[i],dem );
                dem = 1;

    }
    
}
int main(int argc, char const *argv[])
{
    typeArray arr;

    randomArray(&arr, 20);

    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d\n",i, arr.firstAdd[i]);
    }
   printf("\n--------------------------\n");
   shortarray(&arr);
   printf("\nliet ke gia tri xuat hien trong mang theo cach 1: ");
   coutarray1(&arr);
   printf("\n");
   printf("\nliet ke gia tri xuat hien trong mang theo cach 2: ");
   coutarry2(&arr);

    
    
    return 0;
}
