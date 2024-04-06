#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void assign(){
    FILE *file;
    file=fopen("sample.txt","r");
    int count=0;
    char ch;
    while((ch=fgetc(file))!=EOF)
	{
        count++;
    }
    cout<<count<<endl;
    fclose(file);
    int m=count/16;
    cout<<m<<endl;
    //------------------------------------------------------------------------------------
    char a[m][4][4],b[m][4][4];
    file=fopen("sample.txt", "r");
    int i,j,k,l;
	for(k=0;k<m;k++)
	{
        for(i=0;i<4;i++)
		{
            for(j=0;j<4;j++)
			{
                int ch=fgetc(file);
                if(ch==EOF)
				{
                    a[k][i][j]=0;
                }
				 else 
				{
                    a[k][i][j]=static_cast<char>(ch);//i have done here type castin coz ch is int type so it is  taking hex of int ha ha ha 
                }     
            }
        }
        
	    for(i=0;i<=3;i++)
    	{
	    	for(j=0;j<=3;j++)
	    	{
	    		b[k][i][j]=a[k][j][i];
	    	}
	    }
	    for(i=0;i<=3;i++)
	    {
		    for(j=0;j<=3;j++)
		    {
			    a[k][i][j]=b[k][i][j];
		    }
	    }
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
    	for(i=0;i<=3;i++)
    	{
    		for(j=0;j<=3;j++)
    		{			
			    a[k][i][j]=b[k][i][j];
		    }
	    }
	    for(i=0;i<=3;i++)
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
	    for(i=0;i<=3;i++)
	    {
	    	for(j=0;j<=3;j++)
	    	{
			
	    		b[k][i][j]=a[k][i][j];
	    	}
	    }
	    for(int z=0,j=4;z<=3;z++)
	    {
	    	j--;
	    	for(l=0,i=4;l<=3;l++)
	    	{
	    		i--;
	    		b[k][z][l]=a[k][i][j];
	    	}
	    }
        for(i=0;i<=3;i++)
        {
            for(j=0;j<=3;j++)
            {
               a[k][i][j] = b[k][i][j];
            }
        }
        
        for(i=0;i<4;i++)
        {
        	for(j=0;j<4;j++)
        	{
        		cout<<hex<<setw(2)<<setfill('0')<<"["<<static_cast<int>(a[k][i][j])<<"]\t";
			}
			cout<<"\n";
		}
		cout<<"\n";
		
	}
	}
		int main()
		{
    	assign();
    	return 0;
		}
