// Given an array containing duplicate elements, return a vector with only the unique elements in the same order
// T=O(n) , S=O(n)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> unique(int *arr, int size)
{
    vector<int> output;
    unordered_map<int, bool> um;
    for (int i = 0; i < size; i++)
    {
        if (um.count(arr[i]) > 0)
            continue;

        um[arr[i]] = true;
        output.push_back(arr[i]);
    }
    return output;
}

int main(int argc, char const *argv[])
{
    int input[] = {1, 55, 55, 1, 7, 2, 88, 7};
    vector<int> output;
    output = unique(input, 8);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}