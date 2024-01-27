#include <iostream>
#include <string>
#include "functions.h"
#include <limits>

int menu;

int input_int(){
    int value;
    while (true) {
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;

        } else if (std::cin.eof()) {
            std::cout << "End of file (EOF) reached. The program is completed." << std::endl;
            exit(0);
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input Error. Please enter an int." << std::endl;
        }
    }
    return value;
}

Lab2::Message input_message(){
    Lab2::Message msg;
    std::string text;
    std::cout << "Input message text: \n";
    std::getline(std::cin, text);
    msg.setText(text);
    std::cout << "Input chat name: \n";
    std::getline(std::cin, text);
    msg.setChatName(text);
    return msg;
}

void print_menu() {
    std::cout  <<"\n1) messages \n";
    std::cout  << "2) messages queue \n" ;
    std::cout  << "3) Exit \n" ;
    std::cout  << "Your option: " ;
}

void print_message_menu() {
    std::cout << "1) merge messages \n";
    std::cout << "2) compare messages\n";
    std::cout << "3) search\n";
    std::cout << "4) back to main menu\n";
    std::cout << "Your option: " ;
}

void print_queue_menu() {
    std::cout << "1) New message \n";
    std::cout << "2) Remove from queue\n";
    std::cout << "3) Queue status\n";
    std::cout << "4) reorganize queue\n";
    std::cout << "5) new queue\n";
    std::cout << "6) search by word\n";
    std::cout << "7) sort queue\n";
    std::cout << "8) back to main menu\n";
    std::cout << "Your option: " ;
}

void message(){
    Lab2::Message msg1, msg2;
    msg1 = input_message();
    msg2 = input_message();
    while (true) {
        print_message_menu();
        menu = input_int();
        switch (menu) {
            case 1: {
                Lab2::Message mergedMessage = msg1 + msg2;
                mergedMessage.display();
                break;
            }
            case 2:
                if (msg1 <=> msg2 < 0) {
                    std::cout << "message 1 comes before message 2" << std::endl;
                } else if (msg1 <=> msg2 > 0) {
                    std::cout << "message 2 comes before message 1" << std::endl;
                } else {
                    std::cout << "message 1 and message 2 are equivalent" << std::endl;
                }
                break;
            case 3: {
                std::string searchWord;
                std::cout << "Enter a word to search: ";
                std::cin >> searchWord;

                size_t position = msg1.findWord(searchWord);

                if (position != std::string::npos) {
                    std::cout << "Word found at position: " << position << std::endl;
                } else {
                    std::cout << "Word not found in the message." << std::endl;
                }
                break;
            }
            case 4:
                break;
            default:
                std::cout << "Input correct value";
        }
        if(menu==4)
        {
            break;
        }
    }
}

void message_queue() {
    Lab2::Message msg1("msg1", "Chat1", time(nullptr));
    Lab2::Message msg2("msg2?", "Chat1", time(nullptr)+10);
    Lab2::Message msg3;
    Lab2::messageQueue queue;
    queue.enqueue(msg1);
    queue.enqueue(msg2);

    while (true) {
        print_queue_menu();
        menu = input_int();
        switch (menu) {
            case 1: {
                msg3 = input_message();
                queue.enqueue(msg3);
            }
                break;
            case 2:
                queue.dequeue();
                break;
            case 3: {
                Lab2::messageQueue::QueueState currentState = queue.checkState();
                switch (currentState) {
                    case Lab2::messageQueue::QueueState::empty:
                        std::cout << "The queue is empty." << std::endl;
                        break;
                    case Lab2::messageQueue::QueueState::partially_full:
                        std::cout << "The queue is partially full." << std::endl;
                        break;
                    case Lab2::messageQueue::QueueState::full:
                        std::cout << "The queue is full." << std::endl;
                        break;
                }
            }
                break;
            case 4:
                queue.mergeAdjacentMessages();
                break;
            case 5:{
                std::string chatName;
                std::cout << "Enter chat name: ";
                std::cin >> chatName;
                queue.allocateMessagesToNewQueue(chatName);
            }
                break;
            case 6: {
                std::string searchWord;
                std::cout << "Enter a word to search: ";
                std::cin >> searchWord;
                queue.findNearestMessageWithWord(searchWord);
                break;
            }
            case 7:
                queue.organizeQueue();
                break;
            case 8:
                break;
            default:
                std::cout << "Input correct value";
        }
        if (menu == 8) {
            break;
        }
    }
}