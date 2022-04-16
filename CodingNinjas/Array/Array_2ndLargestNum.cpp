#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int findSecondLargest(int *input, int n)
{
    //Write your code here
    int LargestNum = INT_MIN , SecLargestNum = INT_MIN ;
    if (n > 1 ){
        for (int i = 0; i < n ; i++){
            if (input[i] > LargestNum) {
                SecLargestNum = LargestNum;
                LargestNum = input[i]  ;
            } else if((input[i] > SecLargestNum) && (input[i] != LargestNum)){
                SecLargestNum = input[i];
            }
        }
    }
    return SecLargestNum ;
}

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
        int N ;
        cin >> N ;
        for (int j = 0;j < N ; j++){
            cin >> myArray1[j] ;
        }
        
        cout << findSecondLargest(myArray1, N) << endl;
        //printArray(myArray1,N);
    }
}