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
                if (openBrackets.back() == '(') {

                    openBrackets.pop_back();
                    break;

                }
                return false;
            case '}':
                if (openBrackets.back() == '{') {

                    openBrackets.pop_back();
                    break;

                }
                return false;
            case ']':
                if (openBrackets.back() == '[') {

                    openBrackets.pop_back();
                    break;

                }
                return false;

        }

    }

    return openBrackets.empty();
 
}

int main() {

    std::string sentence = "[(])";
    std::cout << isBalanced(sentence) << std::endl;

    return 0;

}