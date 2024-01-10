#include <iostream>

int main() {
    int choice;
    while (true) {

        std::cout << "Enter a number (1-3) or 0 to exit: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "You selected 1" << std::endl;
                break;
            case 2:
                std::cout << "You selected 2" << std::endl;
                break;
            case 3:
                std::cout << "You selected 3" << std::endl;
                break;
            case 0:
                std::cout << "Exiting the loop." << std::endl;
                // Use break to exit the while loop
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }

        // Continue with the next iteration of the while loop
    }

    return 0;
}

