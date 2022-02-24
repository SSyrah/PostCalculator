#include "Stack.h"

int main(int argc, char* argv[]) {
    /*
Post: The program has executed simple arithmetic
      commands entered by the user.
Uses: The class Stack and the functions
      introduction, instructions, do_command, and get_command.
*/
        std::cout << argc << std::endl;
        std::cout << argv[1] << std::endl;
       

        std::stringstream ss;
        Stack stored_numbers;
        std::string line = "-p";
        if (argv[1] == line) { 
            introduction();
            instructions();
            while (stored_numbers.do_command(stored_numbers.get_command(), stored_numbers));
        }
        else if (argc == 2){
            int number;
            char command;
            ss << argv[1];
            while (!ss.eof()){
                if (ss >> number){ std::cout << number << " ";}
                else {
                
                ss >> command;
                std::cout << "ollaan elsessa : ";
                std::cout << command << " ";}
            }

        }

    return 0;
}
