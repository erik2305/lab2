#include <iostream>
#include <ctime>
#include "functions/functions.h"
#include "message/message.h"
#include "messageQueue/messageQueue.h"

int main() {
    //Lab2::Message msg1("message1", "Chat1", time(nullptr));
    //Lab2::Message msg2("message2", "Chat2", time(nullptr) + 10);

    int menu;
    while (true) {
        try {
            print_menu();
            menu = input_int();
            switch (menu) {
                case 1:
                    message();
                    break;
                case 2:
                    message_queue();
                    break;
                case 3:
                    return 0;
                default:
                    std::cout << "Input correct value";
            }
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}
