#include <iostream>
#include <string>
using namespace std;

// Function to perform XOR
string xorOperation(string a, string b)
{
    string result = "";

    for (int i = 1; i < b.length(); i++)
    {
        if (a[i] == b[i])
            result += '0';
        else
            result += '1';
    }

    return result;
}

// Function to calculate CRC
string calculateCRC(string data, string generator)
{
    int genLength = generator.length();

    string temp = data.substr(0, genLength);

    for (int i = genLength; i < data.length(); i++)
    {
        if (temp[0] == '1')
            temp = xorOperation(temp, generator);
        else
            temp = xorOperation(temp, string(genLength, '0'));

        temp += data[i];
    }

    // Final XOR
    if (temp[0] == '1')
        temp = xorOperation(temp, generator);
    else
        temp = xorOperation(temp, string(genLength, '0'));

    return temp;
}

int main()
{
    string data, generator;

    cout << "========== SENDER SIDE ==========\n\n";

    cout << "Enter Data Bits: ";
    cin >> data;

    cout << "Enter Generator: ";
    cin >> generator;

    // Number of extra zero bits
    int extraZeros = generator.length() - 1;

    // Add extra zeros
    string dataWithZeros = data + string(extraZeros, '0');

    // Calculate CRC
    string crc = calculateCRC(dataWithZeros, generator);

    // Create transmitted data
    string transmittedData = data + crc;

    cout << "\n----------- OUTPUT -----------\n";

    cout << "Data Bits              : " << data << endl;
    cout << "Generator              : " << generator << endl;

    cout << "Number of Extra 0 Bits : "
         << extraZeros << endl;

    cout << "Data + Extra 0 Bits    : "
         << dataWithZeros << endl;

    cout << "CRC Remainder          : "
         << crc << endl;

    cout << "Transmitted Data       : "
         << transmittedData << endl;

    cout << "\n=================================\n";

    return 0;
}