#include <iostream>
#include <string>
#include <algorithm>

std::string normalize(const std::string &text) {
    std::string result = text;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int main() {
    std::cout << "Simple chat bot. Type 'bye' to exit." << std::endl;
    std::string input;

    while (true) {
        std::cout << "You: ";
        if (!std::getline(std::cin, input)) {
            break;
        }

        std::string message = normalize(input);
        if (message == "bye" || message == "exit" || message == "quit") {
            std::cout << "Bot: Goodbye!" << std::endl;
            break;
        }

        if (message.find("hello") != std::string::npos || message.find("hi") != std::string::npos) {
            std::cout << "Bot: Hello! How can I help you today?" << std::endl;
        } else if (message.find("how are you") != std::string::npos) {
            std::cout << "Bot: I'm a simple chat program, so I'm always fine." << std::endl;
        } else if (message.find("name") != std::string::npos) {
            std::cout << "Bot: I'm a basic chat bot example." << std::endl;
        } else if (message.find("time") != std::string::npos) {
            std::cout << "Bot: I don't have a clock, but I can talk with you." << std::endl;
        } else {
            std::cout << "Bot: I see. Tell me more." << std::endl;
        }
    }

    return 0;
}
