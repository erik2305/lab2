#ifndef UNTITLED_MESSAGE_H
#define UNTITLED_MESSAGE_H

#include <iostream>
#include <ctime>

namespace Lab2 {
    class Message {
    private:
        std::string text;
        std::string chatName;
        time_t messageTime;
    public:
        Message(std::string text, std::string chatName, time_t messageTime) :
                text(text), chatName(chatName), messageTime(messageTime) {
        }
        Message(std::string text = "", std::string chatName = "") :
                text(text), chatName(chatName) {
            messageTime = std::time(nullptr);
        }
//        Message(){
//            text = "";
//            chatName = "";
//            messageTime = std::time(0);
//        }

        Message &setText(std::string text) {
            this->text = text;
            return *this;
        }
        Message &setChatName(std::string chatName) {
            this->chatName = chatName;
            return *this;
        }
        Message &setTime(time_t messageTime) {
            this->messageTime = messageTime;
            return *this;
        }

        std::string getText() const {
            return text;
        }
        std::string getChatName() const {
            return chatName;
        }
        time_t getTime() {
            return messageTime;
        }

        static Message mergeMessages(const Message& msg1, const Message& msg2);
        void display() const;
        std::size_t findWord(const std::string& word) const;

        std::strong_ordering operator<=>(const Message& other) const;
        Message operator+(const Message& other) const;
    };
}


#endif //UNTITLED_MESSAGE_H
