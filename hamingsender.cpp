#include <iostream>
#include <string>
using namespace std;

int main()
{
    int m, r = 0;

    cout << "Enter number of data bits: ";
    cin >> m;

    // Calculate number of parity bits
    while ((1 << r) < (m + r + 1))
    {
        r++;
    }

    int n = m + r;
    string data;

    cout << "Enter data bits: ";
    cin >> data;

    char code[100];
    int j = 0;

    // Place data bits and parity bits
    for (int i = 1; i <= n; i++)
    {
        if ((i & (i - 1)) == 0)
            code[n - i] = '0'; // Parity bit
        else
            code[n - i] = data[m - 1 - j++];
    }

    // Calculate Even Parity Bits
    for (int p = 1; p <= n; p *= 2)
    {
        int count = 0;

        for (int i = 1; i <= n; i++)
        {
            if ((i & p) && code[n - i] == '1')
                count++;
        }

        if (count % 2 == 0)
            code[n - p] = '0';
        else
            code[n - p] = '1';
    }

    cout << "\nGenerated Hamming Code: ";

    for (int i = 0; i < n; i++)
        cout << code[i];

    cout << endl;

    return 0;
}