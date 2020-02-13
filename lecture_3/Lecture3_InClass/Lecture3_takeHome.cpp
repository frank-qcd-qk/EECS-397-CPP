#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>
#include <iostream>
#include <regex>

std::vector<std::string> parseDice(const std::string& s, std::string rgx_id){

	std::vector<std::string> elements;
	std::regex rgx (rgx_id);

	std::sregex_token_iterator iter(s.begin(), s.end(), rgx, -1);
	std::sregex_token_iterator end;

	while (iter != end) {
		elements.push_back(*iter);
		++iter;
	}
	return elements;
}

void parseSentence(std::vector<std::string>& sentenceInfo, const std::string& s, std::string rgx_id, std::vector<std::string>& diceInfo) {

    std::regex rgx(rgx_id);
    std::smatch m;
    std::sregex_token_iterator iter(s.begin(), s.end(), rgx, -1);
    std::sregex_token_iterator end;

    while (iter != end) {
        sentenceInfo.push_back(*iter);
        ++iter;
    }

    while (std::regex_search(s, m, rgx)) {
        for (auto x : m) diceInfo.push_back(x);
    }

}

void parseTokens(const std::string line, std::vector<std::string>& information, int& rollCount, int& diceID, int& mutiplier, int& offsetter) {
    rollCount = 0;
    diceID = 0;
    mutiplier = 1;
    offsetter = 0;
    // convert it to integer and assign it as the count
    // convert it to integer and assign it as the number of faces
    if (information.size() == 2) {
        mutiplier = 0;
        offsetter = 0;
        diceID = std::stoi(information.back());
        information.pop_back();
        rollCount = std::stoi(information.back());
        information.pop_back();
    }
    else if (information.size() == 4) {

        offsetter = (line.find("+") != std::string::npos) ? std::stoi(information.back()) : std::stoi(information.back()) * -1;
        information.pop_back();
        diceID = std::stoi(information.back());
        information.pop_back();
        rollCount = std::stoi(information.back());
        information.pop_back();
        mutiplier = std::stoi(information.back());
        information.pop_back();
    }
    else if (information.size() == 3) {
        if (line.find("*") != std::string::npos) {
            diceID = std::stoi(information.back());
            information.pop_back();
            rollCount = std::stoi(information.back());
            information.pop_back();
            mutiplier = std::stoi(information.back());
            information.pop_back();
        }
        else {
            offsetter = (line.find("+") != std::string::npos) ? std::stoi(information.back()) : std::stoi(information.back()) * -1;
            information.pop_back();
            diceID = std::stoi(information.back());
            information.pop_back();
            rollCount = std::stoi(information.back());
            information.pop_back();
        }

    }
    else {
        throw std::string("Error: Parse failed!");
    }
}

int rollDice(const int rollCount, const int diceID) {
    std::cout << "Random Number:  ";
    // loop over count
    int randomNum = 0;
    int sum = 0;
    for (int i = 0; i < rollCount; i++) {
        // create random number using: ( std::rand() % number of faces ) + 1; )

        randomNum = std::rand() % diceID + 1;
        std::cout << randomNum << "  ";
        // sum all the random numbers
        sum += randomNum;
    }
    std::cout << std::endl;
    std::cout << "Sum of this dice and roll combo is: " << sum << std::endl;
    return sum;
}

int main_part1() {
    std::cout << "==========================================================" << std::endl;
    std::srand(time(NULL)); //initialize the random number generator

    // Define input file locations and name.

    std::string input_file_name = "dice_part_1.txt";

    // Define output file location and name
    std::string output_file_name = "result_part_1.txt";

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
    std::string frontBullShit;
    std::string backBullShit;
    int DEBUG_line_counter = 0;
    int rollCount = 0;
    int diceID = 0;
    int mutiplier = 0;
    int offsetter = 0;

    while (!input.eof()) {
        // reset!

        DEBUG_line_counter++;
        // For each line
        input >> line; //load one line from input to dice string
        std::cout << "Observe Line: " << DEBUG_line_counter << std::endl;
        std::cout << line << std::endl;
        // copy from start to d where d not included to a variable
        // copy from d to the end (d is not included) to a variable

        std::vector<std::string> information = parseDice(line, "[*+-/d]");
        
        try {
            parseTokens(line, information, rollCount, diceID, mutiplier, offsetter);
        }
        catch (...) {
            std::cout << "Parse Failed!" << std::endl;
            exit(80);
        }

        std::cout << "Dice: " << diceID << " faces    Roll: " << rollCount << " times    Mutiplier: " << mutiplier <<"        Offset: " << offsetter << std::endl;
        int sum = mutiplier * rollDice(rollCount, diceID) + offsetter;

        // Convert the sum into string
        // Write the string into output file
        try {
            std::cout << "Write value: " << sum << std::endl;
            output << std::to_string(sum) << "\n";
            std::cout << "Write Success!" << std::endl;
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
            std::cout << "Write file failed..." << std::endl;
            return 97;
        }
        std::cout << std::endl;
    }
    // loop shoud end here
    //close input file
    input.close();
    //close output file
    output.close();
    std::cout << "==========================================================";
}

int main_part2() {
    std::cout << "==========================================================" << std::endl;
    std::srand(time(NULL)); //initialize the random number generator

    // Define input file locations and name.

    std::string input_file_name = "dice_part_2.txt";

    // Define output file location and name
    std::string output_file_name = "result_part_2.txt";

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
    std::string frontBullShit;
    std::string backBullShit;
    int DEBUG_line_counter = 0;
    int rollCount = 0;
    int diceID = 0;
    int mutiplier = 0;
    int offsetter = 0;

    while (!input.eof()) {
        // reset!

        DEBUG_line_counter++;
        // For each line
        input >> line; //load one line from input to dice string
        std::cout << "Observe Line: " << DEBUG_line_counter << std::endl;
        std::cout << line << std::endl;
        // copy from start to d where d not included to a variable
        // copy from d to the end (d is not included) to a variable
        std::vector<std::string> diceInfo,sentenceinfo,processedDiceInfo;

        parseSentence(sentenceinfo, line, "(\d+)d(\d+)",diceInfo);
        std::cout << "sentenceinfo length: " << sentenceinfo.size() << "     DiceINFO Length: " << diceInfo.size() << std::endl;
        /*
        for (auto x : diceInfo) {
            try {
                parseTokens(line, diceInfo, rollCount, diceID, mutiplier, offsetter);
            }
            catch (...) {
                std::cout << "Parse Failed!" << std::endl;
                exit(80);
            }
            std::cout << "Dice: " << diceID << " faces    Roll: " << rollCount << " times    Mutiplier: " << mutiplier << "        Offset: " << offsetter << std::endl;
            int sum = mutiplier * rollDice(rollCount, diceID) + offsetter;
            processedDiceInfo.push_back(std::to_string(sum));
        }
        */
        /*
        // Convert the sum into string
        // Write the string into output file
        try {
            std::cout << "Write value: " << sum << std::endl;
            output << std::to_string(sum) << "\n";
            std::cout << "Write Success!" << std::endl;
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
            std::cout << "Write file failed..." << std::endl;
            return 97;
        }
        std::cout << std::endl;
        */
    }
    // loop shoud end here
    //close input file
    input.close();
    //close output file
    output.close();
    std::cout << "==========================================================";
}

int main() {
    //main_part1();
    main_part2();
}