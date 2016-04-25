// редактор.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
void search(int input, int  P_list[], bool  R_bit[], int & victim);
int main()
{
//Basic initilization
int victim = 0;
bool R_bit [10];
int P_list [10];

 for(int i = 0; i <10;  i++)
 {
    //Sets one array to all false
    R_bit [i] = false;
    //Sets every integer in the other array to -1
    P_list [i] = -1;
 }

 int input;


 ifstream inFile;

 //Opens up the text file "requests.txt"
 inFile.open("requests.txt");
 //If It is not able to open the file
 if (!inFile)
 {
     //Display error message
    cout << "Unable to open specified file";
    //Exit with an error(1)
      exit(1);
 }

 while(inFile >> input )
 {
    if(input < 0)
    {
        cout << "invalid input ";
        exit(1);
    }
    else if(input > 99) 
    {
        cout << "invalid input ";
        exit(1);
    }
  //search array 2, replace and end
    search(input, P_list, R_bit, victim);



}       return 0;
}



void search(int input, int  P_list[], bool  R_bit[], int &victim)
{

//local var only unless you pass them  input is the only thing you passed
for(int i = 0; i <10; i++)
{

    if(input == P_list [i])
    {//Output if it is a hit

        cout << input << ": page hit, " << input << "is in frame " << i << endl;
        R_bit [i] = 1;

        return;
    }
    int oldpage;
    //Sets up a bool to end the while loop
    bool flag = true;
    //While true
    while(flag){
    //looks for the first 0 in the R-Bit array
    if (R_bit [victim] == 0)
    {
        //If it is zero
        flag = false;
            //Recording previous page for output 
    oldpage = P_list [victim];
    //Replaces with input 
    P_list [victim] = input;
        victim = victim + 1;


    }
    else
    {   //Makes the R-Bit zero
        R_bit [victim] = 0;
        //Increments, makes it zero
        ++victim;

    }
        //If the victim is going to go out of bounds
    if(victim > 9)
    {
        //Set to zero 
        victim = 0;
    }
    }

    //output if it misses and the frame it is in
    cout << input << ": page miss, page " << input << " replaces page " << oldpage << " in frame " << (victim - 1) << endl;

}
system("pause");
}