#include<iostream>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
int main()
{
    FILE *file;
    char ch;
    char ab;
    char main_matrix[4][4];
char temporary_matrix[4][4];
char final_matrix_select[4][4];
    file = fopen("input.txt","r");

float a;
int count=0;
int finalINTcount;
while((ab=fgetc(file))!= EOF)
{
    count++;
}
fclose(file);
a=(count/16);
finalINTcount=a;
FILE *f;
f=fopen("input.txt","r");
for(int e=0;e<=finalINTcount;e++)
{



    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
        {
            main_matrix[i][j]=(ch=fgetc(f));
            if(ch == EOF){
                break;
            }
        }
    }



















        int i,j,m,l;
	    for(i=0;i<=3;i++)
    	{
	    	for(j=0;j<=3;j++)
	    	{
	    		temporary_matrix[i][j]=main_matrix[j][i];
	    	}
	    }
	    for(i=0;i<=3;i++)
	    {
		    for(j=0;j<=3;j++)
		    {
			    main_matrix[i][j]=temporary_matrix[i][j];
		    }
	    }
	    for(i=0;i<=3;i++)
	    {
    		for(j=0;j<=3;j++)
    		{
    			if(j==0)
    			{
    				temporary_matrix[i][j]=main_matrix[i][j+2];
    			}			
    			if(j==2)
    			{
    				temporary_matrix[i][j]=main_matrix[i][j-2];
    			}
    		}
    	}
    	for(i=0;i<=3;i++)
    	{
    		for(j=0;j<=3;j++)
    		{			
			    main_matrix[i][j]=temporary_matrix[i][j];
		    }
	    }
	    for(i=0;i<=3;i++)
	    {
	    	for(j=0;j<=3;j++)
	    	{
	    		if(i==1)
	    		{
	    			main_matrix[i][j]=temporary_matrix[i+1][j];		
	    		}
	    		if(i==2)
	    		{
	    			main_matrix[i][j]=temporary_matrix[i-1][j];
	    		}
	    	}
	    }
	    for(i=0;i<=3;i++)
	    {
	    	for(j=0;j<=3;j++)
	    	{
			
	    		temporary_matrix[i][j]=main_matrix[i][j];
	    	}
	    }
	    for(m=0,j=4;m<=3;m++)
	    {
	    	j--;
	    	for(l=0,i=4;l<=3;l++)
	    	{
	    		i--;
	    		temporary_matrix[m][l]=main_matrix[i][j];
	    	}
	    }
        for(i=0;i<=3;i++)
        {
            for(j=0;j<=3;j++)
            {
                final_matrix_select[i][j] = temporary_matrix[i][j];
            }
        }
        for(i=0;i<=3;i++)
        {
            for(j=0;j<=3;j++)
            {
                cout<<hex<<setw(2)<<setfill('0')<<"["<<static_cast<int>(final_matrix_select[i][j])<<"]\t";
            }
            cout<<"\n";
        }

}

















    return 0;
}
