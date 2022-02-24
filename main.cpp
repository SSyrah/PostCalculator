#include "Stack.h"

int main(int argc, char* argv[]) {
    /*
Post: The program has executed simple arithmetic
      commands entered by the user.
Uses: The class Stack and the functions
      introduction, instructions, do_command, and get_command.
*/


        Stack stored_numbers;
        std::string line = "-p";
        if (argv[1] == line) {
            introduction();
            instructions();
            while (stored_numbers.do_command(stored_numbers.get_command(), stored_numbers));
        }

    return 0;
}
