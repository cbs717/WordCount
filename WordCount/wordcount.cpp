#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int count_char(char* name)
{
	FILE* fp;
	int num = 0;
	char find;
	if ((fp = fopen(name, "r")) == NULL)
	{
		printf("File open failed\n");
		return -1;
	}
	while ((find = getc(fp)) != EOF)
	{
		num++;
	}
	fclose(fp);
	return num;
}

int count_word(char* name)
{
	FILE* fp;
	int num = 0;
	int word = 0;
	int t_word = 0;
	char find;
	if ((fp = fopen(name, "r")) == NULL)
	{
		printf("File open failed\n");
		return -1;
	}
	while ((find = getc(fp)) != EOF)
	{
		num++;
		if ((find >= 'A' && find <= 'Z') || (find >= 'a' && find <= 'z'))
		{
			t_word++;
		}
	}
	fclose(fp);
	return num;
		
}
int main(int argc, char* argv[])
{
	if (strcmp(argv[1], "-c") == 0)
	{
		printf("character %d\n", count_char(argv[2]));
	}
	else if (strcmp(argv[1], "-w") == 0)
	{
		printf("word %d\n", count_word(argv[2]));
	}
	else
	{
		printf("²ÎÊýÊäÈë´íÎó\n");
	}
	return 0;

}
