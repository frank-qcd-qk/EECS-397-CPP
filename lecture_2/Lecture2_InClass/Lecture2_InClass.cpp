#include <iostream>
#include<string> 
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
/*
float babylonian(float num, float accuracy) {
    float x = num;
    float y = 1;
    float precision = accuracy;
    float valDiff = x - y;
    while (valDiff > precision) {
        x = (x + y) / 2;
        y = num / x;
        valDiff = x - y;
    }
    return x;
}
*/

float inClassWork(float num, int loopCount) {
    float x = num;
    float guess = num / 2;
    float r = x / guess;
    int counter = 0;
    while (counter < loopCount) {
        guess = (guess + r) / 2;
        r = x / guess;
        counter++;
    }
    return guess;
}

float babylonian(float num,float accuracy) {
    float x = num;
    float guess = num / 2;
    float r = x / guess;
    float lastGuess = INFINITY;
    float diff = abs(lastGuess - guess);
    while (diff > accuracy) {
        guess = (guess + r) / 2;
        r = x / guess;
        diff = abs(lastGuess - guess);
        lastGuess = guess;
    }
    cout << "babylonian done!" << endl;
    return guess;
}

float newton(float num, float accuracy) {
    float guess = 2 / num;
    float lastGuess = INFINITY;
    float diff = abs(lastGuess - guess);
    float divergeCount = 0;
    float lastDiff = INFINITY;
    float a, b;
    int counter = 0;
    while (diff > accuracy) {
        counter++;
        a = guess / 2;
        b = 3 - num * guess * guess;
        guess = a * b;
        diff = abs(lastGuess - guess);
        if (lastDiff - diff < 0) {
            divergeCount++;
            //cout << "Divergence Warning!" << endl;
            if ((divergeCount >= 2)|| (counter >1000)) {
                throw "Exception: Diverged!";
            }
        }
        else
        {
            divergeCount = 0;
            //cout << "Divergence Reset!" << endl;

        }
        lastDiff = diff;
        lastGuess = guess;
    }
    cout << "newton done!" << endl;
    return num * guess;
}

float getVal(string prompt) {
    string user_input;
    cout << prompt;
    bool valGet = false;
    bool initial = true;
    cin >> user_input;
    while (!valGet||initial) {
        valGet = true;
        for (int i = 0; i < user_input.size(); i++) {
            if ((!isdigit(user_input[i])) ) {
                if (user_input.size() == 1 && (user_input[0] == 'q' || user_input[0] == 'Q')) {
                    exit(99);
                }
                if (user_input[i] != '.') {
                    cout << "Your input is not valid, try again! Your input: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cin >> user_input;
                    valGet = false;
                    break;
                }
            }
        }
        try {
            stof(user_input);
        }
        catch (std::exception & e) {
            cout << "Your input is not valid, try again! Your input: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> user_input;
            valGet = false;
        }
        initial = false;
    }
    return stof(user_input);

}

int main()
{
    float number;
    float accuracy;
    float result_bab,result_newton;

    string get_number_prompt = "Please input the number you want to square root with: ";
    number = getVal(get_number_prompt);
    cout << "Your number is: " << number << endl;
    string get_accuracy_prompt = "Please input the accuracy you desired: ";
    accuracy = getVal(get_accuracy_prompt);
    cout << "Your accuracy is: " << accuracy<<endl;
    cout << endl;
    result_bab = babylonian(number,accuracy);
    try {
        result_newton = newton(number, accuracy);
    }
    catch(...){
        cout << "Divergence Detected! No result!" << endl;
        result_newton = NULL;
    }
    cout << endl;
    cout << "Done!, Bab Value is: " << result_bab << "    Newton Value is : " << result_newton;
    cout << endl << endl;
}