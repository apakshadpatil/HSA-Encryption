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
    file = fopen("input.txt","r");
    char a[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
        {
            a[i][j]=(ch=fgetc(file));
            if(ch == EOF){
                break;
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<hex<<setw(2)<<setfill('0')<<"["<<static_cast<int>(a[i][j])<<"]\t";
        }
        cout<<"\n";
    }
    return 0;
}
