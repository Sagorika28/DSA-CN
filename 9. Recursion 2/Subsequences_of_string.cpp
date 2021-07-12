// Print all the subsequences of a string (including the null character)
// T=O(2^n), S=O(2^n)

#include <iostream>
using namespace std;

int subsq(string input, string *output)
{
    // base case
    if (input.empty())
    {
        output[0] = "";
        return 1; // null character's length is returned
    }

    // recursive call
    string ros = input.substr(1);
    int ros_size = subsq(ros, output);

    // calculation - concatenate the first letter with the returned substrings
    for (int i = 0; i < ros_size; i++)
        output[i + ros_size] = input[0] + output[i];

    return 2 * ros_size; // since after copying the strings with the 1st letter, size would be twice the original
}

int main(int argc, char const *argv[])
{
    string input;
    cin >> input;
    string *output = new string[1000000]; // creating a string array
    int count = subsq(input, output);
    for (int i = 0; i < count; i++)
        cout << output[i] << endl;
    return 0;
}