#include <stdio.h>


char arr[] = "the grammy award-winning singer. who has been less active on digital platforms in recent weeks. explained her decision to distance herself from social media platforms during an appearance on the Conan OBrien Needs a Friend podcast, alongside her brother Finneas";

//Cau 1: Viet mot chuyen dao nguoc VD: "Finneas brother her alongside .... Grammy The"
//cau 2: In Hoa chu cai dau tien sau dau cham
//Cau 3: Chuyen doi tat ca doan van thanh chu thuong
//Cau 4: Chuyen doi tat ca doan van thanh chu hoa
void in_mang ()
{
	for(int i = 0; i<sizeof arr; i++)
	{
		printf("%c", arr[i]);
	}
}

void inhamdaonguoc(int ktt, int kts) 
{
    for (int j=ktt+1; j<kts;j++)
    {
        printf("%c",arr[j]);
    }
    printf(" ");
}
void hamdaonguoc()
{
	
	  int dem = sizeof arr;
    for(int i=sizeof arr - 1; i>0; i--)
    {
        if (arr[i]==' ')
        {
        inhamdaonguoc(i,dem);
        dem=i;
        }
}
    for(int j=0;j<dem;j++)
    { 
	 printf("%c",arr[j]);
	}
	printf("\n");

}
void inhoachucaidautien()
{
	
	for (int i=0;i<sizeof arr;i++)
	{
		if (arr[i]=='.')
		{
			arr[i+2]= (arr[i+2] - 32);
		}
	}
	in_mang();
}
		

void chuthuong()
{
	for(int i=0; i<sizeof arr;i++)
	{
		if ((arr[i]>='A')&&(arr[i]<='Z'))
		{
			arr[i]=(arr[i] + 32);
		}
	}
	in_mang();

}
void chuhoa()
{
	for(int i=0; i<sizeof arr;i++)
	{
		if ((arr[i]>='a')&&(arr[i]<='z'))
		{
			arr[i]=(arr[i] - 32);
		}
	}
	in_mang();
}

int main()
{
	in_mang();
	printf("\ncau 1 : \n");
	hamdaonguoc();
	printf("\ncau 2: \n");
    inhoachucaidautien();
	printf("\ncau 3: \n");
    chuthuong();
	printf("\ncau 4: \n");
	chuhoa();
    return 0;
}
