//exercise 2.1
//part b
#include <iostream>
#include "stack.h"

using namespace std;

string ReverseString(const string& str) {
    Stack s;
    
    // Push each character onto the stack
    for (char ch : str) {
        s.Push(ch);
    }

    // Pop characters to get the reversed string
    string reversed;
    while (!s.Isempty()) {
        reversed += s.Peek(); // Get the top character
        char temp;
        s.Pop(temp); // Remove the top character
    }

    return reversed;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string reversed = ReverseString(input);
    cout << "Reversed string: " << reversed << endl;

    return 0;
}

//exercise 2.2
// PART A
/*#include <iostream>
#include "stack.h"
using namespace std;

bool isValidExpression(const string& expr) {
    Stack s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.Push(ch);  // Push opening brackets
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.Isempty()) return false;  // More closing than opening

            char topChar;
            s.Pop(topChar);

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;  // Mismatched brackets
            }
        }
    }
    return s.Isempty();  // Stack should be empty if expression is valid
}

int main() {
    string expr;
    cout << "Enter a parenthesized expression: ";
    cin >> expr;

    if (isValidExpression(expr)) {
        cout << "Valid expression!" << endl;
    } else {
        cout << "Invalid expression!" << endl;
    }

    return 0;
}*/

//PART B
/*#include <iostream>
#include "stack.h"
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.isempty() && s.peek() != '(') {
                postfix += s.peek();
                s.pop();
            }
            s.pop();
        } else {
            while (!s.isempty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.peek();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.isempty()) {
        postfix += s.peek();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
*/


//PART C
/*#include <iostream>
#include <cctype>
#include "stack.h"

using namespace std;

int EvaluatePostfix(const string& expression) {
	Stack s;
	int op1, op2, result;

	for (char ch : expression) {
		if (isdigit(ch)) {
			s.Push(ch - '0');
		} 
		else {
			s.Pop(op2);
			s.Pop(op1);

			switch (ch) {
				case '+': result = op1 + op2; break;
				case '-': result = op1 - op2; break;
				case '*': result = op1 * op2; break;
				case '/': 
					if (op2 == 0) {
						cout << "Error: Division by zero!" << endl;
						exit(1);
					}
					result = op1 / op2; 
					break;
				default:
					cout << "Error: Invalid operator '" << ch << "'" << endl;
					exit(1);
			}
			s.Push(result);
		}
	}
	return s.Peek();
}

int main() {
	string postfixExp;
	cout << "Enter a postfix expression (e.g., 23*54*+9-): ";
	cin >> postfixExp;

	int result = EvaluatePostfix(postfixExp);
	cout << "Result: " << result << endl;

	return 0;
}

*/
