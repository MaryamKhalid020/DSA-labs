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
#include <string>
using namespace std;

class myStack {
    char arr[100] = {};
    int top;

public:
    myStack() : top(-1) {}

    void push(char c) {
        arr[++top] = c;
    }

    char pop() {
        return arr[top--];
    }

    char peek() {
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(const string& infix) {
    myStack s;
    string postfix;

    for (char ch : infix) {
        // Operand: directly append to postfix
        if (isalpha(ch) || isdigit(ch)) {
            postfix += ch;
        }
        // Open parenthesis: push to stack
        else if (ch == '(') {
            s.push(ch);
        }
        // Close parenthesis: pop until '(' is found
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            if (!s.isEmpty() && s.peek() == '(') {
                s.pop(); // Remove '(' from stack
            }
        }
        // Operator: pop operators with higher or equal precedence
        else {
            while (!s.isEmpty() && s.peek() != '(' && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }

    // Pop all remaining operators from stack
    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter a valid infix expression: ";
    cin >> infix;

    cout << "Postfix expression: " << infixToPostfix(infix) << endl;

    return 0;
}*/


//PART C
/*#include <iostream>
#include <string>
using namespace std;

class Stack {
    int arr[100];
    int top;

public:
    Stack() : top(-1) {}

    void push(int val) {
        arr[++top] = val;
    }

    int pop() {
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int evaluatePostfix(const string& postfix) {
    Stack s;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0'); // Convert character to integer
        }
        else {
            int val2 = s.pop();
            int val1 = s.pop();

            switch (ch) {
            case '+': s.push(val1 + val2); break;
            case '-': s.push(val1 - val2); break;
            case '*': s.push(val1 * val2); break;
            case '/': s.push(val1 / val2); break;
            }
        }
    }

    return s.pop();
}

int main() {
    string postfix;
    cout << "Enter a valid postfix expression: ";
    cin >> postfix;

    cout << "Result: " << evaluatePostfix(postfix) << endl;

    return 0;
}
*/
