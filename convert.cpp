// NAME(S), DATE

#include <cstdlib>   // for atof function
#include <cstdio>    // for sscanf
#include <cstring>   // for strcmp and strtok
#include <iostream>
#include <stack>     // STL stack class
#include <string>    // for throwing string exceptions
using namespace std;

// constants used to identify a token - DO NOT CHANGE
enum TokenType {LEFT, RIGHT, ADD, SUBTRACT, MULTIPLY,
                DIVIDE, NUMBER, OTHER, VARIABLE};
TokenType identify(char *t);


// utility function returns one of those constants
TokenType identify(char *t) {
    if (strcmp(t, "(") == 0)
        return LEFT; 
    if (strcmp(t, ")") == 0)
        return RIGHT;
    if (strcmp(t, "+") == 0)
        return ADD;
    if (strcmp(t, "-") == 0)
        return SUBTRACT;
    if (strcmp(t, "*") == 0)
        return MULTIPLY;
    if (strcmp(t, "/") == 0)
        return DIVIDE;
    double value;
    if (sscanf(t, "%g", &value) == 1)
        return NUMBER;
    return VARIABLE;
}

string infixToPostfix(char *expression[], int numTokens) {
	stack<char*> ops;
	string output = "";
	TokenType type;
	for( int i = 0; i < numTokens; i++){
		type = identify(expression[i]);
		switch(type){
			case LEFT:
				break;
			case NUMBER: case VARIABLE:
				output += expression[i] + " ";
				break;
			case ADD: case SUBTRACT: case MULTIPLY: case DIVIDE:
				ops.push(expression[i]);
				break;
			case RIGHT:
				output += ops.top() + " ";
				ops.pop();
				break;
		}
	}
	return output;
				
    // Your code here

}


#define MAXLEN 100


// do not modify the main function when submiting, otherwise you will get zero score
int main() {
    char input[MAXLEN], *tokens[MAXLEN/2];

    cout << "enter expression: ";
    cin.getline(input, MAXLEN);



    // strtok splits the string (first parameter) with given delimiters (second parameter)
    // A sequence of calls to this function split str into tokens,
    // which are sequences of contiguous characters separated by
    // any of the characters that are part of delimiters.
    // The first call takes the string to be splitted as first parameter
    char *ptr = strtok(input, " ");

    int count = 0;
    while (ptr != 0) {
        tokens[count] = ptr;
        ++count;

        // Latter calls to strtok use a NULL as the first parameter
        ptr = strtok(0, " ");
    }

    try {
        string result = infixToPostfix(tokens, count);
        cout << "result: " << result << endl;
    }
    catch(string error) {
        cerr << "bad expression: " << error << endl;
        return 1;
    }

    return 0;
}
