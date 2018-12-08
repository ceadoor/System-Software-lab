/* 
    title: Absolute Loader
    Created on : 08 Dec 18, 10:49
*/

#include <stdio.h>
#include <string.h>
char input[10], label[10], ch1, ch2;
int addr, w = 0, start, ptaddr, l, length = 0, end, count = 0, k, taddr, address, i = 0;
FILE *fp1, *fp2;
void check();
void main()
{
	fp1 = fopen("input.txt", "r");
	fp2 = fopen("output.txt", "w");
	fscanf(fp1, "%s", input);
	printf("\n\nABSOLUTE LOADER\n");
	fprintf(fp2, "\n-------------------------------------------------------\n");
	fprintf(fp2, "MEMORY ADDRESS\t\t\tCONTENTS");
	fprintf(fp2, "\n-------------------------------------------------------\n");
	while (strcmp(input, "E") != 0)
	{
		if (strcmp(input, "H") == 0)
		{
			fscanf(fp1, "%s %x %x %s", label, &start, &end, input);
			address = start;
		}
		else if (strcmp(input, "T") == 0)
		{
			l = length;
			ptaddr = addr;
			fscanf(fp1, "%x %x %s", &taddr, &length, input);
			addr = taddr;
			if (w == 0)
			{
				ptaddr = address;
				w = 1;
			}
			for (k = 0; k < (taddr - (ptaddr + l)); k++)
			{
				address = address + 1;
				fprintf(fp2, "xx");
				count++;
				if (count == 4)
				{
					fprintf(fp2, "  ");
					i++;
					if (i == 4)
					{
						fprintf(fp2, "\n\n%x\t\t", address);
						i = 0;
					}
					count = 0;
				}
			}
			if (taddr == start)
				fprintf(fp2, "\n\n%x\t\t", taddr);
			fprintf(fp2, "%c%c", input[0], input[1]);
			check();
			fprintf(fp2, "%c%c", input[2], input[3]);
			check();
			fprintf(fp2, "%c%c", input[4], input[5]);
			check();
			fscanf(fp1, "%s", input);
		}
		else
		{
			fprintf(fp2, "%c%c", input[0], input[1]);
			check();
			fprintf(fp2, "%c%c", input[2], input[3]);
			check();
			fprintf(fp2, "%c%c", input[4], input[5]);
			check();
			fscanf(fp1, "%s", input);
		}
	}
	fprintf(fp2, "\n-------------------------------------------------------\n");
	fclose(fp1);
	fclose(fp2);
	printf("\n\n The contents of output file:\n");
	fp2 = fopen("output.txt", "r");
	ch2 = fgetc(fp2);
	while (ch2 != EOF)
	{
		printf("%c", ch2);
		ch2 = fgetc(fp2);
	}
	fclose(fp2);
}
void check()
{
	count++;
	address++;
	taddr = taddr + 1;
	if (count == 4)
	{
		fprintf(fp2, "  ");
		i++;
		if (i == 4)
		{
			fprintf(fp2, "\n\n%x\t\t", taddr);
			i = 0;
		}
		count = 0;
	}
}

/* 

input.txt
---------

H COPY 001000 00107A
T 001000 1E 141033 482039 001036 281030 301015 482061 3C1003 00102A 0C1039 00102D
T 00101E 15 0C1036 482061 081033 4C0000 454F46 000003 000000
T 001047 1E 041030 001030 E0205D 30203F D8205D 281030 302057 549039 2C205E 38203F
T 001077 1C 101036 4C0000 000000 001000 041030 E02079 302064 509039 DC2079 2C1036
E 001000

OUTPUT
------

ABSOLUTE LOADER

The contents of output file:

-------------------------------------------------------
MEMORY ADDRESS                  CONTENTS
-------------------------------------------------------


1000            14103348  20390010  36281030  30101548

1010            20613C10  0300102A  0C103900  102D0C10

1020            36482061  0810334C  0000454F  46000003

1030            000000xx  xxxxxxxx  xxxxxxxx  xxxxxxxx

1040            xxxxxxxx  xxxxxx04  10300010  30E0205D

1050            30203FD8  205D2810  30302057  5490392C

1060            205E3820  3Fxxxxxx  xxxxxxxx  xxxxxxxx

1070            xxxxxxxx  xxxxxx10  10364C00  00000000

1080            00100004  1030E020  79302064  509039DC

1090            20792C10  36
-------------------------------------------------------

*/	