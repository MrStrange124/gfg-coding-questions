#include <bits/stdc++.h>
#define ll long long
using namespace std;
void printSubsequence(string input, string output)
{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }
    printSubsequence(input.substr(1), output + input[0]);
    printSubsequence(input.substr(1), output);
}
unordered_set<string> st;
void subsequence(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = s.length(); j > i; j--)
        {
            string str = s.substr(i, j);
            st.insert(str);
            for (int k = 1; k < str.length(); k++)
            {
                string sb = str;
                sb.erase(sb.begin() + k);
                subsequence(sb);
            }
        }
    }
}
void printSubSeqRec(string str, int n, int index = -1,
                    string curr = "")
{
    // base case
    if (index == n)
        return;

    if (!curr.empty())
    {
        cout << curr << "\n";
    }

    for (int i = index + 1; i < n; i++)
    {

        curr += str[i];
        printSubSeqRec(str, n, i, curr);

        // backtracking
        curr = curr.erase(curr.size() - 1);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string output = "";
    string input = "abcd";
    // printSubsequence(input, output);
    // subsequence(input);
    // for (auto i : st)
    //     cout << i << endl;
    printSubSeqRec(input, input.length());
    return 0;
}