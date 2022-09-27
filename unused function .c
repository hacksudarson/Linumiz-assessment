#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int findfunction(char *fname, char *str)// formal args
{
	FILE *fp;//file pointer
	char temp[512];//to declare the string size
	char *p;
	if((fp = fopen(fname, "r")) == NULL)// to read the fname then store fp
    {
		return(-1);
	}

	while(fgets(temp, 512, fp) != NULL)//
    {
		if((p=strstr(temp, str)) != NULL)//str str sub string
        {
		     for(int i=5;*(p+i)!='\'';i++)//iteration text.c(5char)then intrating the text file
		     {
		         printf("%c",*(p+i));//to print the pointer value
             }
             printf("\n");//new line
		}
	}
	if(fp) {
		fclose(fp);//file closing
	}
   	return(0);
}
int main(int argc, char** argv)//
{
    char cmd[200]="gcc -ffunction-sections -Wl,--gc-sections,--print-gc-sections ";//find the function name
    strcat(cmd,argv[1]);//merge the filename and argv[1]
    strcat(cmd," 2> out.txt");//merge the file
    const char *command =cmd;//to initialize the filename to command pointer
    FILE *fptr;//to create the text file
    fptr=fopen("unused.txt","w+");//to write and read the unused text file
    system(command );//execting the command
    printf("The notused function input file:\n");
    findfunction("unused.txt","text.");// actual args to passess to the function
    return 0;
}
