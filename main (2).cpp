/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size)
{
    #pragma omp parallel
    for(int i=0; i<size; i++)
    {
        #pragma omp for
        for(int j=0; j<size-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}


void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int  arr[] = {2,7,9,45,1,0,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    printArray(arr,size);
    cout<<endl;
    bubbleSort(arr,size);
    cout<<endl;
    printArray(arr,size);
    return 0;
}
