
//Lecture1_2.cpp : Program in the lecture 1
//                 Asks user to enter two integer values
//                 Then prints out the result
    


#include <iostream>

// function main begins program execution
int main()
{
    int integer1;  //First integer from the user
    int integer2;  //Second integer from the user
    int integer3;  //Third integer from the user
    int sum_i;       //Stores the sum of integers as integer
    double sum_d;    //Stores the sum of integers as double
    int avg_i;       //Average stored as integer
    double avg_d; //Average stored as double

    // int integer1, integer2, sum;
    
    std::cout << "Enter first integer: \n";           // prompt
    std::cin >> integer1;                        // read an integer
    std::cout << "Enter second integer: \n";      // prompt
    std::cin >> integer2;                        // read an integer
    std::cout << "Enter third integer: \n";      // prompt
    std::cin >> integer3;                        // read an integer
    
    sum_i = integer1 + integer2 + integer3;        // assign result to sum (integer)
    sum_d = integer1 + integer2 + integer3;      // assign result to sum (double)
    avg_i = sum_i / 3;
    avg_d = sum_d / 3;
    
    std::cout << "Sum is " << sum_i << std::endl;  // print sum
    std::cout << "Average (int) is: " << avg_i << std::endl;  // print average as integer
    std::cout << "Average (double) is: " << avg_d << std::endl;  // print average as double

    avg_d = sum_i / 3.0; // integer divided by double results in a double
    std::cout << "Average (double) is: " << avg_d << std::endl;  // print average as double

    return 0;   // indicate that program ended successfully

} // end function main