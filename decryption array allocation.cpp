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
	ofstream MyEnfile("decrypt.txt");
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
                cout<<"["<<static_cast<char>(hexv)<<"] ";
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }
}
int main()
{
    decrypt();
    return 0;
}
