#include <iostream>
#include <string>
#include <cctype>
using namespace std;
// 1️⃣ Check Numeric Constant
void checkNumeric(string input) {
   bool isNumeric = true;
   for (int i = 0; i < input.length(); i++) {
       if (!isdigit(input[i])) {
           isNumeric = false;
           break;
       }
   }
   if (isNumeric)
       cout << "It is a numeric constant." << endl;
   else
       cout << "It is not numeric." << endl;
}
// 2️⃣ Check Operators
void checkOperator(string input) {
   bool found = false;
   for (int i = 0; i < input.length(); i++) {
       if (input[i] == '+' || input[i] == '-' || input[i] == '*' ||
           input[i] == '/' || input[i] == '%' || input[i] == '=') {
           cout << "Operator found: " << input[i] << endl;
           found = true;
       }
   }
   if (!found)
       cout << "No operator found." << endl;
}
// 3️⃣ Check Comment Line
void checkComment(string input) {
   if (input.substr(0, 2) == "//")
       cout << "It is a single-line comment." << endl;
   else if (input.substr(0, 2) == "/*" && input.substr(input.length() - 2, 2) == "*/")
       cout << "It is a multi-line comment." << endl;
   else
       cout << "It is not a comment." << endl;
}
// 4️⃣ Check Identifier
void checkIdentifier(string input) {
   bool valid = true;
   if (!((input[0] >= 'A' && input[0] <= 'Z') ||
         (input[0] >= 'a' && input[0] <= 'z') ||
         (input[0] == '_'))) {
       valid = false;
   }
   for (int i = 1; i < input.length(); i++) {
       if (!((input[i] >= 'A' && input[i] <= 'Z') ||
             (input[i] >= 'a' && input[i] <= 'z') ||
             (input[i] >= '0' && input[i] <= '9') ||
             (input[i] == '_'))) {
           valid = false;
           break;
       }
   }
   if (valid)
       cout << "It is a valid identifier." << endl;
   else
       cout << "It is not a valid identifier." << endl;
}
// 5️⃣ Find Average
void findAverage() {
   int n;
   cout << "Enter number of elements: ";
   cin >> n;
   int arr[n];
   cout << "Enter " << n << " elements: ";
   for (int i = 0; i < n; i++)
       cin >> arr[i];
   int sum = 0;
   for (int i = 0; i < n; i++)
       sum += arr[i];
   float avg = (float)sum / n;
   cout << "Average value = " << avg << endl;
}
// 6️⃣ Find Minimum and Maximum
void findMinMax() {
   int n;
   cout << "Enter number of elements: ";
   cin >> n;
   int arr[n];
   cout << "Enter " << n << " elements: ";
   for (int i = 0; i < n; i++)
       cin >> arr[i];
   int min = arr[0], max = arr[0];
   for (int i = 1; i < n; i++) {
       if (arr[i] < min)
           min = arr[i];
       if (arr[i] > max)
           max = arr[i];
   }
   cout << "Minimum value = " << min << endl;
   cout << "Maximum value = " << max << endl;
}
// 7️⃣ Concatenate Name
void concatName() {
   string first, last;
   cout << "Enter first name: ";
   cin >> first;
   cout << "Enter last name: ";
   cin >> last;
   string full = first + " " + last;
   cout << "Full name = " << full << endl;
}
// 🧭 MAIN PROGRAM MENU
int main() {
   int choice;
   string input;
   do {
       cout << endl;
       cout << "Press 1 to Check Numeric." << endl;
       cout << "Press 2 to Check Operator." << endl;
       cout << "Press 3 to Check Comment Line." << endl;
       cout << "Press 4 to Check Identifier." << endl;
       cout << "Press 5 to Find Average." << endl;
       cout << "Press 6 to Find Minimum and Maximum." << endl;
       cout << "Press 7 to Concatenate Name." << endl;
       cout << "Press 0 to Exit!" << endl;
       cout << "Enter Key: ";
       cin >> choice;
       cout << endl;
       switch (choice) {
       case 1:
           cout << "Enter input: ";
           cin >> input;
           checkNumeric(input);
           break;
       case 2:
           cout << "Enter input: ";
           cin >> input;
           checkOperator(input);
           break;
       case 3:
           cin.ignore(); // clear buffer for getline
           cout << "Enter line: ";
           getline(cin, input);
           checkComment(input);
           break;
       case 4:
           cout << "Enter input: ";
           cin >> input;
           checkIdentifier(input);
           break;
       case 5:
           findAverage();
           break;
       case 6:
           findMinMax();
           break;
       case 7:
           concatName();
           break;
       case 0:
           cout << "Exiting program..." << endl;
           break;
       default:
           cout << "Invalid choice! Try again." << endl;
       }
   } while (choice != 0);
   return 0;
}
