/* 
Given a sentence contained in string S. Write a function which will replace all the words within the sentence whose length is even and 
>= 4 with a space between the 2 equal halves of the word.
Don't use extra space.
I/P: Helloo world good
O/P: Hel loo world go od 
*/
// T=O(n) , S=O(1)
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    string str, word = "";
    int size = 0, start = 0, end = 0, mid;
    getline(cin, str);
    for (int i = 0; i <= str.length(); i++)
    {
        // print string if space encountered
        if (str[i] == ' ' or str[i] == '\0')
        {
            size = end - start;
            if (size >= 4 and size % 2 == 0)
            {
                mid = (start + end) / 2;
                for (int k = 0; k < size; k++)  // put a space at the middle of the word
                {
                    if ((k + start) == mid)
                        cout << " ";
                    cout << str[start + k];
                }
            }
            else
            {
                for (int k = 0; k < size; k++)
                {
                    cout << str[start + k];
                }
            }

            // update start and end
            start = i + 1;
            end = i + 1;
            cout << " ";
        }

        else
        {
            end++;
        }
    }
    return 0;
}