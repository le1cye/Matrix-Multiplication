#include <stdio.h>
#include <stdlib.h>
#include "Initialization.h"
#include "PrintToFile.h"
#include"Matrix Operation.h"


int main(int argc,char *argv[])
{
	//************基本变量***********//
	//声明//
	//char *aaa = "hahahaha";
	//char *bbb = "国庆节！";
	//double pi = 3.14159265358;
	//int c = 10;
	//int i,j;
	//
	//printf("Hello World.\n\n");
	//printf("%s, %s\n\n",aaa,bbb);
	//printf("%-16.11lf,%16.11lf\n",pi,pi);
	//printf("%f,%20e\n",pi,pi);
	//printf("%d,%10d\n",c,c);

	//************静态数组***********//
	//声明//
	//int Array1[10];
	//float Array2[10];
	//double Array3[10];
	////初始化//
	//for(i=0;i<10;i++)
	//{
	//	Array1[i] = 0;
	//	Array2[i] = 0.0;
	//	Array3[i] = (double)i;
	//}
	////声明//
	//double Matrix[5][5];
	////初始化//
	//for(i=0;i<5;i++)
	//{
	//	for(j=0;j<5;j++)
	//	{
	//		Matrix[i][j] = 0.0;
	//	}
	//}

	int i,j,k,Bandwidth;
	char *Directory1,*Directory2;
	Directory1 = "C:\\Users\\Administrator\\Desktop\\Array.txt";
	Directory2 = "C:\\Users\\Administrator\\Desktop\\Matrix.txt";



	//************动态数组（二维）***********//
	double **Matrix;
	int m = 10,n = 10;

	Matrix = (double**)malloc(m*sizeof(double*));
	for(i=0;i<m;i++)
	{
		*(Matrix+i) = (double*)malloc(n*sizeof(double));
	}

	InitializeMatrix(Matrix,m,n,0.0);
	Bandwidth=5;

	for(i=0;i<m;i++)
	{
		Matrix[i][i]=(double)Bandwidth;
		if(i<=m-Bandwidth)
		{
			k=Bandwidth;
		}
		else
		{
			k=m-i;
		}
		for(j=1;j<k;j++)
		{
			Matrix[i][i+j]=Bandwidth-j;
			Matrix[i+j][j]=Bandwidth-j;
		}
	}

	PrintMatrix(Matrix,Directory2,"BBB",m,n);

	system("pause");

	//************从文件读取***********//
	//FILE *fp;
	/*double x,y,z;
	for(j=0;j<i;j++)
	{
		fscanf(fp,"%lf %lf %lf",&x,&y,&z);
		CoordX[j] = x;
		CoordY[j] = y;
		CoordZ[j] = z;
	}
	fclose(fp);

	printf("Which row would you like to check?\n");
	scanf("%d",&i);
	printf("%lf %lf %lf\n",CoordX[i],CoordY[i],CoordZ[i]);

	system("pause");*/

	//************条件判断***********//
	//If Else//
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i == j)
			{
				Matrix[i][j] = 1.0;
			}
			else if(i < j)
			{
				Matrix[i][j] = 0.0;
			}
			else
			{
				Matrix[i][j] = 2.0;
			}
			printf("%6.2lf ",Matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//Switch//
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			switch (i)
			{
			case 0:
				Matrix[i][j] = 0.0;
				break;
			case 1:
				Matrix[i][j] = 1.0;
				break;
			case 2:
				Matrix[i][j] = 2.0;
				break;
			case 3:
				Matrix[i][j] = 3.0;
				break;
			case 4:
				Matrix[i][j] = 4.0;
				break;
			}
			printf("%6.2lf ",Matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//************循环结构***********//
	double error = 10.0;
	int num = 0;
	while(error > 1.0)
	{
		error -= 1.0;
		num++;
	}
	printf("%d\n",num);

	system("pause");
	return 0;
}