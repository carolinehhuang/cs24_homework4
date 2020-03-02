#include <iostream>
#include <stack>     // STL stack class
#include <string> 
using namespace std;

bool isPalindrome(string& input){
	stack <char> s;
    for( int i =0; i < input.length(); i++){
	    s.push(input[i]);
    }
    for(int i = 0; i < input.length(); i++){
	    if(s.top() == input[i]){
		    s.pop();
	    }
	    else{
		    return false;
	    }
    }
    return true;
    
}

// main gets string from user
// do not modify main function, otherwise you will get zero score
int main() {
    string input;

    cout << "enter string: ";
    cin >> input;

    bool result = isPalindrome(input);

    if (result == true) {
        cout << "Palindrome" << endl;
    }
    else {
        cout << "Not palindrome" << endl;
    }

    return 0;
}
