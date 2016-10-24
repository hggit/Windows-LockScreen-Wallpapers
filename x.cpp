#include<iostream>
#include<windows.h>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<sstream>
using namespace std;
int main()
{
    string source="C:/Users/Himanshu/AppData/Local/Packages/Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy/LocalState/Assets";
    string destination="X:/Himanshu/Pictures/Wallpapers/Windows";
    
    char rbc[166];
    string s="robocopy "+source+" "+destination;
    strcpy(rbc, s.c_str());
    system(rbc);

	char cd[42];
    string t="cd X:/Himanshu/Pictures/Wallpapers/Windows";
    strcpy(cd, t.c_str());
    system(cd);


    FILE *fpip;
    char *com = "for %k in (*.*) do @echo %~znk";
    char x = 0;
    string files;
    if (0 == (fpip = (FILE*)popen(com, "r")))
    {
        perror("popen() failed.");
        exit(1);
    }
    while (fread(&x, sizeof x, 1, fpip))
        files+=x;


    istringstream iss(files);
    string name1="",name2="",size="";
    do
    {
    	iss>>size;
    	iss>>name2;
    	if((name2!="x" && name2!="GetWallpapers" && atoi(size.c_str())<153600) || name1==name2)
    	{
    		char del[100];
    		string d="del /f /q "+name2;
    		strcpy(del, d.c_str());
    		system(del);
    	}
    	name1=name2;
    } while(iss);


    char ren[100];
    string r="ren *. *.jpg";
    strcpy(ren, r.c_str());
    system(ren);

    char del[100];
    string d="del /f /q *.";
    strcpy(del, d.c_str());
    system(del);

    
}