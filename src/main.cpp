#include <fstream>
#include <iostream>

using namespace std;

// Write a program with three separate modules: main(), countLine(), countChar(). Both countLine() and countChar() should take a parameter pName of type string or “char *” (your choice) as the parameter. One prints out “XXX Lines”. The other prints out “XXX Characters". These functions return the number of lines or characters in the parameter. Their return types are int or an integer type of your choice. When no command line parameters are specified, the main function invokes the first function with a parameter “Ohio University", then the second function with a parameter “Athens”. When one command line parameter is specified, it will be considered as a file name. The main function reads in the file content. It then invokes the first function countLine() and then countChar() with the same parameter, which points to the file content in memory. You are free to use code segments from any existing open source code for this program, including open source code for “wc” that you can find anywhere. (Just FYI, https://www.dropbox.com/s/9000njf4b903vth/wc.cc?dl=0)

int countLine(string pName);
int countChar(string pName);

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

int countLine(string pName) {
    int count = 0;
    for (string::iterator it = pName.begin(); it != pName.end(); it++) {
        if (*it == '\n') count++;
    }
    cout << count << " Lines" << endl;
    return count;
}

int countChar(string pName) {
    int count = pName.size();
    cout << count << " Characters" << endl;
    return count;
}
