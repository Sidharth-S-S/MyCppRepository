#include <iostream>
using namespace std;
#include <climits>

void wavePrint(int input[][100], int nRows, int mCols)
{
    //Write your code here
    for(int j = 0; j < mCols; j++){
        if (j % 2 == 0){
            for(int i = 0; i < nRows ; i++){
                cout << input[i][j] << " " ;
            }
        } else {
            for(int i = nRows-1; i >= 0 ; i--){
                cout << input[i][j] << " " ;
            }
        }
    }
}

int main(){
    int myArray[100][100] , row , column , T;
    cin >> T ;

    while(T--){
        cin >> row >> column;

        for(int i = 0; i < row ; i++){
            for(int j = 0; j < column ; j++){
                cin >> myArray[i][j] ;
            }
        }
        wavePrint(myArray, row , column ) ;
        cout << endl ;
    }
}