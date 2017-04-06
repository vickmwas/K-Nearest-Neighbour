#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

#define SIZE 5

void printArray(float array[], int length);
int getRandomKValue();


int main(){
    cout <<"Simple K-nearest neighbour C++ implementation\n\n";
    cout <<"            Extrapolation example             \n\n";

    float xArray[] = {1, 1.2, 8.9, 10.4, 5.1};
    float yArray[] = {23, 16, 102, 27, 8};
    float distancesArray[SIZE];
    float originalDistancesArray[SIZE];
    float sortedIndices[SIZE];

    float searchValue = 6.5;
    int kValue;


    //Print X values
    cout<<"X Values = [ ";
    printArray(xArray, SIZE);
    cout<<" ] \n";


    //Print Y values
    cout<<"Y Values = [ ";
    printArray(yArray, SIZE);
    cout<<" ] \n";

    cout<<"\n   We will now try extrapolate the Y value of " << searchValue <<"\n\n";
    kValue = getRandomKValue();
    cout <<"\n  Randomly Selected K Value = " << kValue<<"\n\n";


    /**
    *   find the | distance | between the search query
    */
    for(int i = 0; i < SIZE; i++){
        if(searchValue > xArray[i]){
            distancesArray[i] = searchValue - xArray[i];
        }else{
            distancesArray[i] =  xArray[i] - searchValue;
        }
    }


    cout<<"Difference between search value (" <<searchValue << " ) and X array elements\n";
    cout<<"[ ";
    printArray(distancesArray, SIZE);
    cout<<"] \n";

    //Create a copy of distances array
    for(int i = 0; i < SIZE; i++){
        originalDistancesArray[i] = distancesArray[i];
    }



    /**
    *   Sort the distance array
    */
    for(int i = 1; i <= SIZE; i++){
        sortedIndices[i] = i;
    }


    /**
    * Simple bubble sort code to order the array in ascending order
    */
    bool isSorted = false;
    float temp, temp2;
    while(!isSorted){
        isSorted = true;
        for(int i = 0; i < SIZE; i++){
            if(distancesArray[i] > distancesArray[i+1]){
                temp = sortedIndices[i];
                sortedIndices[i] = sortedIndices[i+1];
                sortedIndices[i+1] = temp;

                temp2 = distancesArray[i];
                distancesArray[i] = distancesArray[i+1];
                distancesArray[i+1] = temp2;

                isSorted = false;
            }
        }
    }


    cout<<"\nElement  |   Sorted Index   |   N. Neighbour   |   Y Value\n";
    cout<<"---------------------------------------------------\n";
     for(int i = 0; i < SIZE; i++){
        cout<<"  "<<originalDistancesArray[i]<<"    |             "<<sortedIndices[i]<<"    |";
        if(sortedIndices[i] <= kValue){
            cout<<"       yes        |   "<<yArray[i];
        }
        cout <<"\n";

    }

    float sum = 0;
    cout<<"\n\nKNN Prediction for ( X = "<<searchValue<<" ) = \n    AVERAGE(";
    for(int i = 0; i < SIZE; i++){
        if(sortedIndices[i] <= kValue){
            cout<<yArray[i]<<" , ";
            sum += yArray[i];
        }
    }
    cout<<" ) = "<<sum / kValue<<"\n\n";






    






}





/**
* Function to return random K value 
*/
int getRandomKValue(){
    /* initialize random seed: */
  srand (time(NULL));
  return rand() % 4 + 1;
}



/**
*Function to print an array
*/
void printArray(float array[], int length){
    // int size = sizeof(array) / sizeof(array[0]);
    
    for(int i = 0; i < length; i++){
        cout << array[i] << " , ";    
    }
}