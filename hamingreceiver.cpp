#include <iostream>
#include <string>
using namespace std;

int main()
{
    int m, r = 0;

    cout << "Enter number of data bits: ";
    cin >> m;

    while ((1 << r) < (m + r + 1))
        r++;

    int n = m + r;
    char code[100];

    cout << "Enter data bits: ";
    string data;
    cin >> data;

    int j = 0;

    // Place data bits and parity bits
    for (int i = 1; i <= n; i++)
    {
        if ((i & (i - 1)) == 0)
            code[n - i] = '0'; // Parity bit
        else
            code[n - i] = data[m - 1 - j++];
    }

    // Calculate parity bits
    for (int p = 1; p <= n; p *= 2)
    {
        int parity = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i & p)
                parity ^= (code[n - i] - '0');
        }

        code[n - p] = parity + '0';
    }

    cout << "\nGenerated Hamming Code: ";

    for (int i = 0; i < n; i++)
        cout << code[i];

    cout << endl;

    return 0;
}


    