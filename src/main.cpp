#include <iostream>
#include <string>

using namespace std;

bool validate(string userInput) {
    return userInput == "icecream";
}

int main()
{
    cout << "input secret" << endl;
    string userInput;
    getline(std::cin, userInput);
    if (validate(userInput)) {
        cout << "welcome" << endl;
    } else {
        cout << "sorry" << endl;
    }
    cin.get();
    return 0;
}