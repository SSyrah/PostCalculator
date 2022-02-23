#include "Stack.h"

char Stack::get_command()
{
    char command;
    bool waiting = true;
    cout << "Select command and press <Enter>: ";

    while (waiting) {
        cin >> command;
        command = tolower(command);
        if (command == '?' || command == '=' || command == '+' ||
            command == '-' || command == '*' || command == '/' ||
            command == 'q' || command == 'x' || command == 's' ||
            command == 'h' || command == 'a') waiting = false;


        else {
            cout << "Please enter a valid command:"   << endl
                    << "[?] push to stack   [=] print top value" << endl
                    << "[+] [-] [*] [/]  are arithmetic operations" << endl
                    << "[s] gives sum from all values  [h] instructions" << endl
                    << "[x] exchanges the place for last two values" << endl
                    << "[a] gives average from all values" << endl
                    << "[Q]uit." << endl;
        }
    }
    return command;
}

bool Stack::do_command(char command, Stack &numbers)
/*
Pre:  The first parameter specifies a valid calculator command.
Post: The command specified by the first parameter
      has been applied to the Stack of numbers given by the second parameter.
      A result of true is returned unless command == 'q'.
Uses: The class Stack.
*/

{
    double p, q, r, s;
    switch (command) {
        case '?':
            cout << "Enter a real number: " << flush;
            cin >> p;
            if (numbers.push(p) == overflow)
                cout << "Warning: Stack full, lost number" << endl;
            break;

        case '=':
            if (numbers.top(p) == underflow)
                cout << "Stack empty" << endl;
            else
                cout << p << endl;
            break;

        case '+':
            if (numbers.top(p) == underflow)
                cout << "Stack empty" << endl;
            else {
                // numbers.pop();
                if (numbers.size() == 1) {
                    cout << "Stack has just one entry" << endl;
                    // numbers.push(p);
                }

                else {
                    numbers.pop();
                    numbers.top(q);
                    if (numbers.push(q + p) == overflow)
                        cout << "Warning: Stack full, lost result" << endl;
                    else{
                        numbers.pop();
                    cout << "The results is for " << p << " + " << q << "= " << p + q << endl;
                        numbers.pop();
                    }
                }
            }
            break;

        case '-':
            if (numbers.top(p) == underflow)
                cout << "Stack empty" << endl;
            else {
                // numbers.pop();
                if (numbers.size() == 1) {
                    cout << "Stack has just one entry" << endl;
                    // numbers.push(p);
                }

                else {
                    numbers.pop();
                    numbers.top(q);
                    if (numbers.push(q + p) == overflow)
                        cout << "Warning: Stack full, lost result" << endl;
                    else{
                        numbers.pop();
                        cout << "The results is for " << p << " - " << q << "= " << p - q << endl;
                        numbers.pop();
                    }
                }
            }
            break;

            //   Add options for further user commands.
        case 'x':
            if (numbers.top(p) == underflow)
                cout << "Stack empty" << endl;
            else {
                // numbers.pop();
                if (numbers.size() == 1) {
                    cout << "Stack has just one entry" << endl;
                    // numbers.push(p);
                }

                else {
                    // numbers.pop();
                    if (numbers.push(q + p) == overflow)
                        cout << "Warning: Stack full, lost result" << endl;
                    else{
                        numbers.pop();
                        double temp = 0;
                        numbers.top(r);
                        numbers.pop();
                        numbers.top(s);
                        numbers.pop();
                        cout << "Numbers first: " << r << " + " << s << endl;
                        temp = r;
                        r = s;
                        s = temp;
                        numbers.push(s);
                        numbers.push(r);
                        cout << "Numbers last: " << r << " + " << s << endl;
                    }
                }
            }
            break;

        case 's':
            numbers.sum(numbers);
            numbers.top(p);
            cout << "Sum =  " << p << "\n";
            break;

        case 'a':
            numbers.average(numbers);
            numbers.top(p);
            cout << "Average =  " << p << "\n";

        case '/':
            if (numbers.top(p) == underflow)
                cout << "Stack empty" << endl;
            else {
                // numbers.pop();
                if (numbers.size() == 1) {
                    cout << "Stack has just one entry" << endl;
                    // numbers.push(p);
                }

                else {
                    numbers.pop();
                    numbers.top(q);
                    if (numbers.push(q + p) == overflow)
                        cout << "Warning: Stack full, lost result" << endl;
                    else{
                        numbers.pop();
                        cout << "The results is for " << p << " / " << q << "= " << p / q << endl;
                        numbers.pop();
                    }
                }
            }
            break;

        case '*':
            if (numbers.top(p) == underflow)
                cout << "Stack empty" << endl;
            else {
                // numbers.pop();
                if (numbers.size() == 1) {
                    cout << "Stack has just one entry" << endl;
                    // numbers.push(p);
                }

                else {
                    numbers.pop();
                    numbers.top(q);
                    if (numbers.push(q + p) == overflow)
                        cout << "Warning: Stack full, lost result" << endl;
                    else{
                        numbers.pop();
                        cout << "The results is for " << p << " * " << q << "= " << p * q << endl;
                        numbers.pop();
                    }
                }
            }
            break;

        case 'h':
            instructions();
            break;

        case 'q':
            cout << "Calculation finished.\n";
            return false;
    }
    return true;
}

void introduction() {
    cout << "\t --------------------------------------\n";
    cout << "\t | Welcome to use PostFix-Calculator! | \n";
    cout << "\t --------------------------------------\n\n";
}

void instructions(){
    cout << "How to use this calculator:"   << endl
         << "[?] push to stack   [=] print top value" << endl
         << "[+] [-] [*] [/]  are arithmetic operations" << endl
         << "[s] gives sum from all values  [h] instructions" << endl
         << "[x] exchanges the place for last two values" << endl
         << "[a] gives average from all values" << endl
         << "[Q]uit." << endl;
}
