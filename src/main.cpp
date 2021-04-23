/**
 * @file main.cpp
 * @author Dakota Taylor
 * @brief This program reads in a files from the command line and outputs its number of lines and characters.
 * @version 0.1
 * @date 2021-04-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <fstream>
#include <iostream>

using namespace std;

// Write a program with three separate modules: main(), countLine(), countChar(). Both countLine() and countChar() should take a parameter pName of type string or “char *” (your choice) as the parameter. One prints out “XXX Lines”. The other prints out “XXX Characters". These functions return the number of lines or characters in the parameter. Their return types are int or an integer type of your choice. When no command line parameters are specified, the main function invokes the first function with a parameter “Ohio University", then the second function with a parameter “Athens”. When one command line parameter is specified, it will be considered as a file name. The main function reads in the file content. It then invokes the first function countLine() and then countChar() with the same parameter, which points to the file content in memory. You are free to use code segments from any existing open source code for this program, including open source code for “wc” that you can find anywhere. (Just FYI, https://www.dropbox.com/s/9000njf4b903vth/wc.cc?dl=0)

int countLine(string pName);
int countChar(string pName);

/**
 * @brief Attempts to read a file from the command line into a string and then outputs its number of lines and characters.
 * 
 * @param argc the number of command line options
 * @param argv the command line options
 * @return int the exit code
 */
int main(int argc, char const *argv[]) {
    if (argc > 1) {
        std::ifstream input(argv[1]);
        if (input.fail()) {
            cout << "Failed to open '" << argv[1] << "'!" << endl;
            return EXIT_FAILURE;
        }

        string text;
        text.assign(istreambuf_iterator<char>(input), istreambuf_iterator<char>());
        input.close();

        countLine(text);
        countChar(text);
    } else {
        countLine("Ohio University");
        countChar("Athens");
    }

    return EXIT_SUCCESS;
}

/**
 * @brief Counts and outputs the total number of new lines in the string.
 * 
 * @param pName the string
 * @return int  number of lines
 */
int countLine(string pName) {
    int count = 0;
    for (string::iterator it = pName.begin(); it != pName.end(); ++it) {
        if (*it == '\n') count++;
    }
    cout << count << " Lines" << endl;
    return count;
}

/**
 * @brief Counts and outputs the total number of characters in the string.
 * 
 * @param pName the string
 * @return int number of character
 */
int countChar(string pName) {
    int count = pName.size();
    cout << count << " Characters" << endl;
    return count;
}
