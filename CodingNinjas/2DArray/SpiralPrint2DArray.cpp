#include <iostream>
using namespace std;
#include <climits>

void spiralPrint(int input[][100], int nRows, int mCols)
{
    int totalelem = 0 , RowStart = 0, RowEnd = nRows - 1 , ColStart = 0, ColEnd = mCols - 1 ;
    while (totalelem < nRows * mCols){
                
        // Spiral Print continues from Top , Right , Bottom , Left Side of the Box while the Start and End elements keep on changing.

        // 1st Part is top ; Row Start ++ Col Varying 
        for (int i = ColStart ; i <= ColEnd ; i++){
            cout << input[RowStart][i] << " ";
            totalelem ++ ;
        }
        RowStart++ ; // All the 1st Row elements are printed and there is no need to print anymore

        // Print the elements of the Right most coloums ; From RowStart -> Row End ;; ColEnd is constant
        for (int i = RowStart ; i <= RowEnd ; i++){
            cout << input[i][ColEnd] << " ";
            totalelem ++ ;
        }
        ColEnd-- ; // All the elements of the Last Column is done and need to change the Last Col

        if (totalelem >= nRows * mCols) {
            break ;
        }


        // Print the bottom elements now from ColEnd to ColStart
        for (int i = ColEnd ; i >= ColStart ; i--){
            cout << input[RowEnd][i] << " ";
            totalelem ++ ;
        }
        RowEnd-- ; // All the Last Row elements are printed and there is no need to print anymore

        // Print the elements of the Left most coloums ; From RowEnd -> RowStart ;; ColStart is constant
        for (int i = RowEnd ; i >= RowStart ; i--){
            cout << input[i][ColStart] << " ";
            totalelem ++ ;
        }
        ColStart++; ; // All the elements of the Last Column is done and need to change the Last Col

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
        spiralPrint(myArray, row , column ) ;
        cout << endl ;
    }
}