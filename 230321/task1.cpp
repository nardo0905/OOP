#include <iostream>
#include <string>

bool isBalanced(std::string& sentence) {

    std::string openBrackets;

    for (char ch : sentence) {

        switch(ch) {

            case '(':
            case '{':
            case '[':
                openBrackets.push_back(ch);
                break;
            
            case ')':
                if (openBrackets.back() != '(') {
                    return false;
                }
            case '}':
                if (openBrackets.back() != '{') {
                    return false;
                }
            case ']':
                if (openBrackets.back() == '[') {
                    return false;
                }
                
            openBrackets.pop_back();
            break;

            default:
                break;
            
        }

    }

    return openBrackets.empty();
 
}

int main() {

    std::string sentence = "[(])";
    std::cout << isBalanced(sentence) << std::endl;

    return 0;

}