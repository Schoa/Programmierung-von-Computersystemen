#include <iostream>

int main()
{
    char input;

    std ::cout << "Character = ";
    std ::cin >> input;

    std ::cout << "ASCII Value of " << "'" << input << "'" << " is " << static_cast<int>(input) << std ::endl;

    return 0;
}