//exercise 2.2
// PART A
#include <iostream>
#include <string>
using namespace std;

class mystack {
private:
    char arr[100];
    int top;

public:
    mystack() : top(-1) {}

    void push(char c) {
        arr[++top] = c;
    }

    char pop() {
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    char peek() {
        return arr[top];
    }
};

bool isValidParentheses(const string& expr) {
    mystack s;
    for (char ch : expr) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.isEmpty()) return false;
            char top = s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }
    return s.isEmpty();
}

int main() {
    string expr;
    cout << "Enter a fully parenthesized expression: ";
    cin >> expr;

    if (isValidParentheses(expr))
        cout << "The expression is valid.\n";
    else
        cout << "The expression is invalid.\n";

    return 0;
}


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