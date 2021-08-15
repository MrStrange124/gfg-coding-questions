// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;

// Function which computes the sequence
string printSequence(string arr[],
                     string input)
{
    string output = "";
    int n = input.length();
    for (int i = 0; i < n; i++)
    {
        if (input[i] == ' ')
            output.push_back('0');
        else
            output.append(arr[input[i] - 'A']);
    }
    return output;
}

// Driver function
int main()
{
    // storing the sequence in array
    string str[] = {"2", "22", "222",
                    "3", "33", "333",
                    "4", "44", "444",
                    "5", "55", "555",
                    "6", "66", "666",
                    "7", "77", "777", "7777",
                    "8", "88", "888",
                    "9", "99", "999", "9999"};

    string input = "HELLO WORLD";
    cout << printSequence(str, input);
    return 0;
}
