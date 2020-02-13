#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

#include <iostream>

int main1()
{
    std::cout << "==========================================================" << std::endl;
    std::srand(time(NULL)); //initialize the random number generator

    // Define input file locations and name.

    std::string input_file_name = "dice.txt";

    // Define output file location and name
    std::string output_file_name = "result.txt";

    // Open the input file 
    std::ifstream input;

    // Good to check if the input file exists and complain if it doesn't.
    try {
        input.open(input_file_name);
        if (!input.good()) {
            std::cout << "Stream is not good :( " << input_file_name << ".\n";
            return 99;
        }
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
        std::cout << "File manipulation failed. Exiting..." << std::endl;
        return 99;
    }

    //Create output file with the given name
    std::ofstream output = std::ofstream(output_file_name);

    if (!output.good()) {
        std::cout << "Stream is not good :( " << std::endl;
        return 99;
    }

    // Loop through to the end of the input file
    std::string line;
    std::string delimiter = "d";
    int index = 0;
    int diceID = 0;
    int rollCount = 0;
    int sum = 0;
    int DEBUG_line_counter = 0;
    int randomNum = 0;

    while (!input.eof()) {
        DEBUG_line_counter++;
        // For each line
        input >> line; //load one line from input to dice string

        std::cout << "Observe Line: " << DEBUG_line_counter << std::endl;
        std::cout << line << std::endl;

        // copy from start to d where d not included to a variable
        index = 0;
        sum = 0;
        // copy from d to the end (d is not included) to a variable
        if ((index = line.find(delimiter)) != std::string::npos){
            // convert it to integer and assign it as the count
            try{
                // convert it to integer and assign it as the number of faces
                rollCount = std::stoi(line.substr(0, index));
                diceID = std::stoi(line.substr(index+delimiter.length(), line.length()));
            }
            catch (std::exception & e) {
                std::cout << e.what() << std::endl;
                std::cout << "String Manipulation Failed! Cannot convert to Int!" << std::endl;
                return 98;
            }
            std::cout << "Dice: " << diceID << " faces    Roll: " << rollCount << " times." << std::endl;
            std::cout << "Random Number:  ";
            // loop over count
            for (int i = 0; i < rollCount; i++) {
                randomNum = 0;
                // create random number using: ( std::rand() % number of faces ) + 1; )

                randomNum = std::rand() % diceID + 1;
                std::cout << randomNum << "  ";
                 // sum all the random numbers
                sum += randomNum;
            }
            std::cout << std::endl;
            std::cout << "Current total after line is: " << sum;
        }
        std::cout << std::endl;
        // Convert the sum into string
        // Write the string into output file
        try {
            output << std::to_string(sum)<<"\n";
            std::cout << "Write Success!" << std::endl;
        }
        catch(std::exception & e){
            std::cout << e.what() << std::endl;
            std::cout << "Write file failed..." << std::endl;
            return 97;
        }
        std::cout<< std::endl;
    }
    // loop shoud end here
    //close input file
    input.close();
    //close output file
    output.close();
    std::cout << "==========================================================";
}
