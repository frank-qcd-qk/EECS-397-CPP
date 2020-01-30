#include <iostream>
using namespace std;

/*
Begin
   x := number
   y := 1
   precision := 0.000001
   while relative error of x and y > precision, do
      x := (x+y) / 2
      y := number / x
   done
   return x
End
*/


float babylonian(float num,float accuracy) {
    float x = num;
    float y = 1;
    float precision = accuracy;
    float valDiff = x - y;
    while (valDiff > precision){
        x = (x + y) / 2;
        y = num / x;
        valDiff = x - y;
    }
    return x;
}

float stupid(float num, int loopCount) {
    float x = num;
    float guess = num / 2;
    float r = x / guess;
    int counter = 0;
    while (counter<loopCount) {
        guess = (guess + r) / 2;
        r = x / guess;
        counter++;
    }
    return guess;
}

int main()
{
    float number;
    float accuracy;
    float result;
    char quiter[1];
    cout << "Please input the number you want to square root with: ";
    bool gotVal = false;
    while (!gotVal) {
        try {
            try{
                cin >> number;
            }
            catch (...) {
                cin.get(quiter, 1);
                cout << endl;
                cout << endl;
                cout << endl;
                cout << quiter;
                if (quiter[0] == 'q') {
                    return 99;
                }
            }
        }
        catch (const std::exception & e) {
            cout << "Observed Error: \n" << e.what() << "\n"; // information from length_error printed
            cout << "Input should be number, for quitting use # sign";
        }
        catch (...) {
            cout << "Unknown error happened, try again";
        }
        gotVal = true;
    }
    gotVal = false;
    cout << "Please input the accuracy: ";
    while (!gotVal) {
        try {
            cin >> accuracy;
        }
        catch (const std::exception & e) {
            cout << "Observed Error: \n" << e.what() << "\n"; // information from length_error printed
            cout << "Input should be number, for quitting use # sign";
        }
        catch (...) {
            cout << "Unknown error happened, try again";
        }
        gotVal = true;
    }
    result = stupid(number,accuracy);
    cout << "Done!, Value is: " << result;
}