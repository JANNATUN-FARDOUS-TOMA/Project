#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void checkNumeric()
{
    char str[50];
    bool flag = true;
    cout << "Enter input: ";
    cin >> str;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(!isdigit(str[i]))
        {
            flag = false;
            break;
        }
    }

    if(flag)
        cout << "Numeric Constant\n";
    else
        cout << "Not Numeric\n";
}

void checkOperator()
{
    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='=')
        cout << "Operator\n";
    else
        cout << "Not Operator\n";
}

void checkComment()
{
    char str[100];
    cin.ignore();
    cout << "Enter a line: ";
    cin.getline(str, 100);

    if(str[0]=='/' && str[1]=='/')
        cout << "Single Line Comment\n";
    else if(str[0]=='/' && str[1]=='*')
        cout << "Multi Line Comment\n";
    else
        cout << "Not a Comment\n";
}

void checkIdentifier()
{
    char str[50];
    bool flag = true;
    cout << "Enter input: ";
    cin >> str;

    if(!(isalpha(str[0]) || str[0]=='_'))
        flag = false;

    for(int i = 1; str[i] != '\0'; i++)
    {
        if(!(isalnum(str[i]) || str[i]=='_'))
        {
            flag = false;
            break;
        }
    }

    if(flag)
        cout << "Valid Identifier\n";
    else
        cout << "Invalid Identifier\n";
}

void findAverage()
{
    int n;
    float sum = 0;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    cout << "Average = " << sum/n << endl;
}

void findMinMax()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int min = a[0], max = a[0];
    for(int i = 1; i < n; i++)
    {
        if(a[i] < min) min = a[i];
        if(a[i] > max) max = a[i];
    }

    cout << "Minimum = " << min << "\nMaximum = " << max << endl;
}

void fullName()
{
    char first[50], last[50], full[100];
    cout << "Enter First Name: ";
    cin >> first;
    cout << "Enter Last Name: ";
    cin >> last;

    strcpy(full, first);
    strcat(full, " ");
    strcat(full, last);

    cout << "Full Name: " << full << endl;
}

int main()
{
    int choice;

    while(true)
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Check Numeric Constant\n";
        cout << "2. Check Operator\n";
        cout << "3. Check Comment\n";
        cout << "4. Check Valid Identifier\n";
        cout << "5. Find Average of Array\n";
        cout << "6. Find Min & Max of Array\n";
        cout << "7. Full Name Concatenation\n";
        cout << "8. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            checkNumeric();
            break;
        case 2:
            checkOperator();
            break;
        case 3:
            checkComment();
            break;
        case 4:
            checkIdentifier();
            break;
        case 5:
            findAverage();
            break;
        case 6:
            findMinMax();
            break;
        case 7:
            fullName();
            break;
        case 8:
            return 0;
        default:
            cout << "Invalid Choice!\n";
        }
    }
}