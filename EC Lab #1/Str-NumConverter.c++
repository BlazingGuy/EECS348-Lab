#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double extractNumeric(const string& str)
{
    int length = str.length(); //Initializes length of string
    bool hasDecimalPoint = false;  // Tracks if there's more than one '.'
    bool hasSign = false;          // Tracks if there's a sign (+/-)
    bool hasDigits = false;        // Ensures there are digits in the number
    int i = 0; //Initializes index to through string's length

    // Empty string or exceeds the max length
    if (length == 0 || length > 20) 
    {
        return -999999.99; // Error signal
    }

    // Check for optional sign at the beginning
    if (str[i] == '+' || str[i] == '-') 
    {
        hasSign = true;
        i++;
    }

    // Parse the rest of the string
    double result = 0.0;
    double decimalMultiplier = 0.1;

    for (;i < length; ++i) 
    {
        char c = str[i];

        if (c >= '0' && c <= '9') //Checks if characters in the string are in the range of numeric digits
        { // Manual digit check
            hasDigits = true;
            if (!hasDecimalPoint) {
                result = result * 10 + (c - '0');
            } else {
                result += (c - '0') * decimalMultiplier;
                decimalMultiplier *= 0.1;
            }
        } 
        else if (c == '.') 
        {
            // Handle multiple decimal points
            if (hasDecimalPoint) {
                return -999999.99; // Error: multiple '.'
            }
            hasDecimalPoint = true;
        } 
        else 
        {
            // Invalid character found
            return -999999.99;
        }
    }

    if (!hasDigits) {
        return -999999.99; // Error: no digits
    }

    // If the string starts with '-', negate the result
    if (!str.empty() && str[0] == '-') {
        result = -result;
    }

    return result;
}




int main()
{
    string input;
    while (true)
    {
        std::string input;
        cout << "Enter a string (or 'END' to quit): ";
        std::cin >> input;
        
        //Length initialized for debugging
        int length = input.length();
        
        if (input == "END")
        {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99)
        {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        }
        else
        {
            cout << "The input is invalid." << endl;
        }
    }
    return 0;
}