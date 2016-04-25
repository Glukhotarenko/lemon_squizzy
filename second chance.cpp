// second chance.cpp: ���������� ����� ����� ��� ����������� ����������.
#include "stdafx.h"
#include<stdio.h>
#include <conio.h>
#include <iostream>
#include <sstream>
#define FN 4 //frame number
#define RB 0 //reference bit
#define PN 1 //page number
int main(void)
{
	//hp = hand pointer, in = input, pt = page table
	int rgPT[FN][2] = {0}, nHP = 3, nIn, iPT;
 
	printf("Enter: ");

	while ( scanf("%d", &nIn) )
	{
		getchar();
 
		//search page table
		for (iPT = 0; rgPT[iPT][PN] != nIn && iPT < FN; iPT++);
 
		//failed to retrieve
		if (rgPT[iPT][PN] != nIn)
		{
			//search for a victim
			do {
				nHP = (nHP + 1) % FN;
			} while ( !( rgPT[nHP][RB] == 1 ? rgPT[nHP][RB] = 0 : 1 ) );
			//update the page table
			rgPT[nHP][RB] = 1;
			rgPT[nHP][PN] = nIn;
		}
 
		//retrieved
		else
			rgPT[iPT][RB] = 1;
 
		//show page table state
		puts("page table:");
		for (iPT = 0; iPT < FN; iPT++)
			printf("%s %d, %d.\n", iPT == (nHP + 1) % 4 ? ">": " ", rgPT[iPT][RB], rgPT[iPT][PN]);
		putchar('\n');
 
		printf("Enter: ");
	}
	puts("May the Roses bloom upon your Cross. ");
 
	return 0;
}