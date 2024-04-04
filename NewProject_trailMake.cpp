#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
char main_matrix[4][4];
char temporary_matrix[4][4];
char final_matrix_select[4][4];
char ch;
void assign()
{
    FILE *file;
    file=fopen("sample.txt","r");
    int count=0;
    while ((ch=fgetc(file))!=EOF)
    {
        count++;
    }
    //------------------------------------
    cout<<count;
    //------------------------------------
    float noOFmainLOOP = (count/16);
    int WholeINTnoOFloop = noOFmainLOOP;
    //------------------------------------
    cout<<endl<<WholeINTnoOFloop<<endl;
    //------------------------------------
    for(int k=0;k<WholeINTnoOFloop;k++)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                main_matrix[i][j]=(ch=fgetc(file));
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
	    		temporary_matrix[k][l]=main_matrix[i][j];
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
                cout<<"["<<final_matrix_select[i][j]<<"]";
            }
            cout<<"\n";
        }
    }
}
int main()
{
    assign();
}
