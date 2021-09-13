
#include <iostream>
#include <chrono>
#include <random>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "введите размер массива\n";
    srand(time(0));
    int N;
    cin >> N;
    int i, j,sumG=0,sumP=0;
    int** arr = new int* [N];
    for (i = 0;i < N;i++) {
        arr[i] = new int[N];
        for (j = 0;j < N;j++) {
            arr[i][j] = 0 + rand() % 10;
            if (i == j)
                sumG += arr[i][j];
            cout << arr[i][j] << "  ";
            if (j == (N - 1))
                cout << endl;
        }
    }
    for (i = 0;i < N;i++) {
        sumP += arr[i][N - 1 - i];
    }
    cout << "главная:" << sumG << endl;
    cout << "побочная:" << sumP << endl;
    if (sumG > sumP) {
        cout << "сумма главной диагонали больше"<< endl;
        for (i = 0;i < N;i++) {
            for (j = 0;j < N;j++) {
                arr[i][j] *= 2;
            }
        }
    }
    else {
        cout << "сумма побочной диагонали больше" << endl;
        for (i = 0;i < N;i++) {
            for (j = 0;j < N;j++) {
                arr[i][j] %=6 ;
            }
        }
    }
    for (i = 0;i < N;i++) {
        for (j = 0;j < N;j++) {
            cout << setw(4) << arr[i][j] ;
               
        }
        cout << endl;
    }
    for (i = 0;i < N;i++) {
        delete[]arr[i];
    }
    return 0;
}
/*    cout << "введите размер массива\n";
    int N;
    cin >> N;
    int i,j;
    int** arr = new int* [N];
    for (i = 0;i < N;i++) {
        arr[i] = new int[i];
    }
    for (i = 0;i < N;i++) {
        delete[]arr[i];
    }*/
