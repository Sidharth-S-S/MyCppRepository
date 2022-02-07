#include <iostream>
#include <cmath>
#include <climits>
using namespace std;



void pushZeroesEnd(int *input, int size)
{
    int NonZeroCount = 0 ; 
    for (int i = 0; i < size; i++){
        if (input[i] != 0) {
            // Non Zero Element found and it has to be updated at the array beginning 
            // Swap the Initial Element with the found NonZero Element
            int temp = input[NonZeroCount];
            input[NonZeroCount] = input[i] ;
            input[i] = temp ;
            NonZeroCount++;
        }
    }
}

/*  
void pushZeroesEnd(int *input, int size)
{
    int NonZeroCount = 0 ; 
    //Write your code here
    for (int i = 0; i < size;i++){
        if (input[i]!=0){
            NonZeroCount++ ;
        }
    }

    // Now we have to sort the arrays and put the NonZero Elements at the beginning , we have already found the number of nonzeroe elements hence the loop would be only till that number of nonzeroe elements.
    for (int i = 0; i < NonZeroCount ; i++){
        for (int j = i; j < size; j++){
            if (input[j]!=0){
                // Non Zero Element is found and it has to be replaced at the ith idx of the array
                int temp = input[i];
                input[i] = input[j] ;
                input[j] = temp ;
                break ;
            }
        }
    }
}

Execution Time : 3053 ms   vs Current 1118ms
*/

void printArray(int *Array , int Size){
    for (int i = 0 ; i < Size;i++){
        cout << Array[i] << " " ;
    }
    cout << endl;
}

int main() {
    //     The first line contains an Integer 't' which denotes the number of test cases
    int t = 1 ,myArray1[100000];
    cin >> t ;

    for (int i = 1 ; i <= t ; i++) {
        int N  ;
        cin >> N ;
        for (int j = 0;j < N ; j++){
            cin >> myArray1[j] ;
        }

        pushZeroesEnd(myArray1, N) ;
        printArray(myArray1,N);
    }
}
