#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main() {
    int frequency [69] = {38,38,46,31,39,39,38,40,38,41,33,45,32,43,38,43,43,40,37,42,46,34,56,32,38,32,44,45,38,35,35,55,38,27,28,42,38,31,36,40,44,40,36,39,38,28,39,33,33,39,30,39,48,40,34,44,45,34,45,37,49,46,44,49,32,38,39,44,50};
    int powerball [26] = {17,19,23,22,18,23,17,21,22,22,21,17,25,18,17,14,17,28,22,20,28,19,17,30,22,23};

  //initialize number for size
    int fixedArraySize = 0;
    int count = 0;
    srand (time(NULL));
    int number[6] = {0,0,0,0,0,0};
    int iSecret;
    int flag = 0;
    int powerballArray = 0;
    int countA = 0;
    int run_count = 0;
    int ticket_count = 0;
    
    cout << "Please enter in desired simulation iterations: ";
    cin >> run_count;
    cout << "Please enter in desired amount of tickets printed: ";
    cin >> ticket_count;
    
    for(int w = 0; w < run_count; w++)
    {
        cout <<"Iteration: " << w+1 << endl;
        //generate size of array
        fixedArraySize = 0;
        count = 0;
        flag = 0;
        powerballArray = 0;
        countA = 0;
        
        for (int i = 0; i < 69; i++)
        {
            fixedArraySize+=frequency[i];
        }
        
        //int *array = new int[size];
        
        //delete [] array;
        int *results = new int[fixedArraySize];
        for (int j = 0; j < 69; j++)
        {
            for (int k = 0; k < frequency[j]; k++)
            {
                results[count] = j+1;
                count++;
            }
        }
        
        random_shuffle(results, results+fixedArraySize);
        
        for (int i = 0; i < 6; i++)
        {
            number[i] = 0;
        }
        
        for (int y = 0; y < 6; y++)
        {
            iSecret = rand() % fixedArraySize + 0;
            //cout << "Index: " << iSecret << endl;
            for (int z = 0; z < 6; z++)
            {
                if(number[z] == results[iSecret])
                {
                    flag = 1;
                    //cout <<"Dupe: " << results[iSecret] << endl;
                }
            }
            if (flag == 0)
            {
                number[y] = results[iSecret];
            }
            else
            {
                y = y-1;
            }
            flag = 0;
        }
        
        
        sort(number,number + 6);
        for (int a = 0; a < 6; a++)
        {
            frequency[(number[a]-1)]++;
        }
        
        
        for (int b = 0; b < 26; b++)
        {
            powerballArray += powerball[b];
        }
        int *resultsA = new int[powerballArray];
        for (int j = 0; j < 26; j++)
        {
            for (int k = 0; k < powerball[j]; k++)
            {
                resultsA[countA] = j+1;
                countA++;
            }
        }
        random_shuffle(resultsA, resultsA+countA);
        iSecret = rand() % powerballArray + 0;
        
        powerball[resultsA[iSecret]]++;
        
        delete [] results;
        delete [] resultsA;
    }
    
    
    cout << endl;
    cout << "Printing Numbers" << endl;
    for (int v = 0; v < ticket_count; v++)
    {
        fixedArraySize = 0;
        count = 0;
        flag = 0;
        powerballArray = 0;
        countA = 0;
        
        for (int i = 0; i < 69; i++)
        {
            fixedArraySize+=frequency[i];
        }
        //int *array = new int[size];
        
        //delete [] array;
        int *results = new int[fixedArraySize];
        for (int j = 0; j < 69; j++)
        {
            for (int k = 0; k < frequency[j]; k++)
            {
                results[count] = j+1;
                count++;
            }
        }
        
        random_shuffle(results, results+fixedArraySize);
        
        for (int i = 0; i < 6; i++)
        {
            number[i] = 0;
        }
        
        for (int y = 0; y < 6; y++)
        {
            iSecret = rand() % fixedArraySize + 0;
            //cout << "Index: " << iSecret << endl;
            for (int z = 0; z < 6; z++)
            {
                if(number[z] == results[iSecret])
                {
                    flag = 1;
                    //cout <<"Dupe: " << results[iSecret] << endl;
                }
            }
            if (flag == 0)
            {
                number[y] = results[iSecret];
            }
            else
            {
                y = y-1;
            }
            flag = 0;
        }
        
        
        sort(number,number + 6);
        for (int a = 0; a < 6; a++)
        {
            cout << number[a] << endl;
        }
        
        
        for (int b = 0; b < 26; b++)
        {
            powerballArray += powerball[b];
        }
        int *resultsA = new int[powerballArray];
        for (int j = 0; j < 26; j++)
        {
            for (int k = 0; k < powerball[j]; k++)
            {
                resultsA[countA] = j+1;
                countA++;
            }
        }
        random_shuffle(resultsA, resultsA+countA);
        iSecret = rand() % powerballArray + 0;
        
        cout << "Powerball: " << resultsA[iSecret] << endl;
        
        delete [] results;
        delete [] resultsA;
    }
    
    /* Debugging
    //Check number_frequencies
    for (int e = 0; e < 69; e++)
    {
        cout << frequency[e] << ",";
    }*/
    return 0;
}
