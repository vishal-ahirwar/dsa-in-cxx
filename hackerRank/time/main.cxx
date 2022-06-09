#include <iostream>
using namespace std;
string timeConversion(string s)
{
    string new_string{s};
    bool toAM{false};
    for (int i = 0; i < new_string.length(); ++i)
    {
        if (s[i] == 'P')
        {
            toAM = true;
            ((char *)new_string.c_str())[i] = ' ';
            ((char *)new_string.c_str())[i + 1] = ' ';
            break;
        }
        else if (s[i] == 'A')
        {
            toAM = false;
            ((char *)new_string.c_str())[i] = ' ';
            ((char *)new_string.c_str())[i + 1] = ' ';
            break;
        }
    };
    if (toAM)
    {
        if (new_string[0] != '1' || new_string[1] == '1')
        {

            new_string[1] = new_string[1] + 2;
            new_string[0] = new_string[0] + 1;
        }
    }
    else
    {
        if (new_string[0] == '1' && new_string[1] == '2')
        {
            new_string[1] = new_string[1] - 2;
            new_string[0] = new_string[0] - 1;
        }
    }

    return new_string;
}

int main(void)
{
    cout << timeConversion("12:05:45AM") << "\n";

    return 0;
}