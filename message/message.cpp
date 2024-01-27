#include "message.h"

namespace Lab2 {
    Message Message::mergeMessages(const Message &msg1, const Message &msg2) {
        if (msg1.chatName != msg2.chatName) {
            throw std::invalid_argument( "Messages are from different chats.");
        }
        if (msg1.messageTime < msg2.messageTime) {
            return Message(msg1.text + " " + msg2.text,
                           msg1.chatName, msg2.messageTime);
        } else {
            return Message(msg2.text + " " + msg1.text,
                           msg1.chatName, msg1.messageTime);
        }
    }

    void Lab2::Message::display() const {
        std::cout << "Message: " << text << std::endl;
        std::cout << "Chat: " << chatName << std::endl;
        std::cout << "Sending Time: " << ctime(&messageTime) << std::endl;
    }

    std::size_t Message::findWord(const std::string& word) const {

        return text.find(word);
    }

    std::strong_ordering Message::operator<=>(const Message& other) const {
        if (chatName != other.chatName) {
            return chatName <=> other.chatName;
        }
        return messageTime <=> other.messageTime;
    }
    Message Message::operator+(const Message& other) const {
        if (chatName != other.chatName) {
            throw std::invalid_argument("Messages are from different chats.");
        }
        if (messageTime < other.messageTime) {
            return Message(text + " " + other.text,
                           chatName, other.messageTime);
        } else {
            return Message(other.text + " " + text,
                           chatName, messageTime);
        }
    }
}