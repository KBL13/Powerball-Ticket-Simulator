#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main() {
    int NormalFrequency [69] = {38,38,46,31,39,39,38,40,38,41,33,45,32,43,38,43,43,40,37,42,46,34,56,32,38,32,44,45,38,35,35,55,38,27,28,42,38,31,36,40,44,40,36,39,38,28,39,33,33,39,30,39,48,40,34,44,45,34,45,37,49,46,44,49,32,38,39,44,50};
    int PowerFrequency [26] = {17,19,23,22,18,23,17,21,22,22,21,17,25,18,17,14,17,28,22,20,28,19,17,30,22,23};

  //initialize number for size
    int frequenciesArraySize = 0;
    int count = 0;
    
    //random number seed
    srand (time(NULL));
    //initialized selected number array to all 0
    int NumbersPicked[6] = {0,0,0,0,0,0};
    int iSecret;
    int flag = 0;
    int powerballArraySize = 0;
    int countPower = 0;
    int run_count = 0;
    int ticket_count = 0;
    
    cout << "Please enter in desired simulation iterations: ";
    cin >> run_count;
    cout << "Please enter in desired amount of tickets printed: ";
    cin >> ticket_count;
    
    for(int h = 0; h < run_count; h++)
    {
        cout <<"Iteration: " << h+1 << endl;
        //Initalize variables to 0 as a reset for loop usage
        frequenciesArraySize = 0;
        
        //count tracker for results iteration to correctly add numbers to array sequentially
        count = 0;
        
        //flag for duplicates, 0 for no dupe, 1 for dupe found
        flag = 0;
        
        //Powerball selection variables
        powerballArraySize = 0;
        countPower = 0;
        
        //generate size of array
        for (int i = 0; i < 69; i++)
        {
            frequenciesArraySize+=NormalFrequency[i];
        }
        //dynamically sized array, size based off of sum of frequencies
        int *results = new int[frequenciesArraySize];
        
        //
        for (int j = 0; j < 69; j++)
        {
            for (int k = 0; k < NormalFrequency[j]; k++)
            {
                results[count] = j+1;
                count++;
            }
        }
        
        //numbers are in order in results [1,1,1,2,2,3,...] so we need to random shuffle for more accurate results
        random_shuffle(results, results+frequenciesArraySize);
        
        //reset array just in case and for reusage in loop
        for (int x = 0; x < 6; x++)
        {
            NumbersPicked[x] = 0;
        }
        
        //Random number selection portion of code
        for (int y = 0; y < 6; y++)
        {
            //generate random index to pick a random number based off weighted number array
            iSecret = rand() % frequenciesArraySize + 0;
            
            //if random number picked matches any of the current numbers inside of number picked array, then thats a dupe and needs to be reran, else add number to array.
            for (int z = 0; z < 6; z++)
            {
                //if a number in the array matched the number already picked, it's a dupe
                if(NumbersPicked[z] == results[iSecret])
                {
                    flag = 1;
                    
                    //debug statement to print the duplicate number
                    //cout <<"Dupe: " << results[iSecret] << endl;
                }
            }
            if (flag == 0)
            {
                //if flag was unchanged, no dupes found and safe to add to number's picked
                NumbersPicked[y] = results[iSecret];
            }
            //if flag was changed, restart loop and rerun where it lefted off
            else
            {
                y = y-1;
            }
            //reset flag
            flag = 0;
        }
        
        //sort number from smallest to largest as how it would appear on a ticket, useful when printing out actual ticket but kept here for object orientated function later
        sort(NumbersPicked,NumbersPicked + 6);
        
        //Add to seed for sample size to be increased by w, (Ex. If 54 was selected, add 1 to NormalFrequency[53])
        for (int a = 0; a < 6; a++)
        {
            NormalFrequency[(NumbersPicked[a]-1)]++;
        }
        
        //Powerball Simulation portion
        //generate size of powerball array
        for (int b = 0; b < 26; b++)
        {
            powerballArraySize += PowerFrequency[b];
        }
        
        //initalize powerball results array
        int *resultsPower = new int[powerballArraySize];
        
        //generate powerball number array based on frequency, [1,1,2,3,3,4,...]
        for (int c = 0; c < 26; c++)
        {
            for (int d = 0; d < PowerFrequency[c]; d++)
            {
                resultsPower[countPower] = c+1;
                countPower++;
            }
        }
        //shuffle powerball number array for accuracy
        random_shuffle(resultsPower, resultsPower+countPower);
        //generate random index 0-25
        iSecret = rand() % powerballArraySize + 0;
        //since there is only 1 powerball per ticket or set, only need to run once and add to the seed.
        PowerFrequency[resultsPower[iSecret]]++;
        
        //delete arrays so that it can be re-initialized in loop for reusage
        delete [] results;
        delete [] resultsPower;
    }
    
    //Printing Ticket Portion (almost same process as simulation) - at this point we ran the simulation based on input of w and have a larger sample sized to pick the actual numbers.
    cout << endl;
    cout << "Printing Ticket Numbers" << endl << endl;
    for (int h = 0; h < ticket_count; h++)
    {
        frequenciesArraySize = 0;
        count = 0;
        flag = 0;
        powerballArraySize = 0;
        countPower = 0;
        
        for (int i = 0; i < 69; i++)
        {
            frequenciesArraySize+=NormalFrequency[i];
        }
        //int *array = new int[size];
        
        //delete [] array;
        int *results = new int[frequenciesArraySize];
        for (int j = 0; j < 69; j++)
        {
            for (int k = 0; k < NormalFrequency[j]; k++)
            {
                results[count] = j+1;
                count++;
            }
        }
        
        random_shuffle(results, results+frequenciesArraySize);
        
        for (int x = 0; x < 6; x++)
        {
            NumbersPicked[x] = 0;
        }
        
        for (int y = 0; y < 6; y++)
        {
            iSecret = rand() % frequenciesArraySize + 0;
            //cout << "Index: " << iSecret << endl;
            for (int z = 0; z < 6; z++)
            {
                if(NumbersPicked[z] == results[iSecret])
                {
                    flag = 1;
                    //cout <<"Dupe: " << results[iSecret] << endl;
                }
            }
            if (flag == 0)
            {
                NumbersPicked[y] = results[iSecret];
            }
            else
            {
                y = y-1;
            }
            flag = 0;
        }
        
        
        sort(NumbersPicked,NumbersPicked + 6);
        for (int a = 0; a < 6; a++)
        {
            cout << NumbersPicked[a] << endl;
        }
        
        
        for (int b = 0; b < 26; b++)
        {
            powerballArraySize += PowerFrequency[b];
        }
        int *resultsPower = new int[powerballArraySize];
        for (int j = 0; j < 26; j++)
        {
            for (int k = 0; k < PowerFrequency[j]; k++)
            {
                resultsPower[countPower] = j+1;
                countPower++;
            }
        }
        random_shuffle(resultsPower, resultsPower+countPower);
        iSecret = rand() % powerballArraySize + 0;
        
        cout << "Powerball: " << resultsPower[iSecret] << endl << endl;
        
        delete [] results;
        delete [] resultsPower;
    }
    
    /* Debugging
    //Check number frequencies to see end results of simulation and spread of number weights.
    for (int e = 0; e < 69; e++)
    {
        cout << NormalFrequency[e] << ",";
    }*/
    return 0;
}
