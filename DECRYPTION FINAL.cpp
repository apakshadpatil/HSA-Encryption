#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include<sstream>
#include <stdlib.h>
#include<string.h>
using namespace std;
void decrypt()
{
    FILE *file;
    file=fopen("encrypt.txt","r");
    int count=0;
    char ch;
    while((ch=fgetc(file))!=EOF)
    {
        count++;
    }
    fclose(file);
    int m=(count/16)/2;
    string a[m][4][4],b[m][4][4];
    file=fopen("encrypt.txt","r");
    int i,j,k,l;
	ofstream MyDCfile("decrypt.txt");
    string var[2];
    string ch2;
    for(int k=0;k<m;k++)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                for(int l=0;l<2;l++)
                {
                    ch2=fgetc(file);
                    var[l]=ch2;
                }
                string item;
                item=var[0] + var[1];
                a[k][i][j]=item;
            }
        }
    for	(int p=0,j=4;p<=3;p++)
	{
		j--;
		for(l=0,i=4;l<=3;l++)
		{
			i--;
			b[k][p][l]=a[k][i][j];
		}
	}
	//6
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			
			a[k][i][j]=b[k][i][j];

		}

	}
	//5
	for	(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			if(i==1)
			{
				a[k][i][j]=b[k][i+1][j];		
			}
			if(i==2)
			{
				a[k][i][j]=b[k][i-1][j];
			}	
			

		}

	}
	//4
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			
			b[k][i][j]=a[k][i][j];

		}

	}
	//3
    for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			if(j==0)
			{
				b[k][i][j]=a[k][i][j+2];
			}
			
			if(j==2)
			{
				b[k][i][j]=a[k][i][j-2];
			}
	
		}

	}
	//2
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			
			a[k][i][j]=b[k][i][j];

		}

	}
	//1
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			b[k][i][j]=a[k][j][i];

		}

	}
	//0
    for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			
			a[k][i][j]=b[k][i][j];
		}
	}

    }
    for(int k=0;k<m;k++)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                stringstream ss;
                ss<<hex<<a[k][i][j];
                unsigned int hexv;
                ss>>hexv;
                MyDCfile<<static_cast<char>(hexv);
            }
        }
    }
    MyDCfile.close();
}
int main()
{
    decrypt();
    return 0;
}
