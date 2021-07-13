// Print all the subsequences of a string (including the null character)
// T=O(2^n), S=O(2^n)
#include <iostream>
using namespace std;

void print_subsq(string input, string output)
{
    if (input.empty()) // base case
    {
        cout << output << endl;
        return;
    }

    print_subsq(input.substr(1), output);            // don't pass the first character
    print_subsq(input.substr(1), output + input[0]); // pass the first character
}

int main(int argc, char const *argv[])
{
    string input;
    cin >> input;
    string output = "";
    print_subsq(input, output);
    return 0;
}