#ifndef UNTITLED_MESSAGE_H
#define UNTITLED_MESSAGE_H
#include <iostream>
#include <ctime>


class Message {
private:
    std::string text;
    std::string chatName;
    time_t messageTime;
public:
    Message(std::string text = "", std::string chatName = "", time_t messageTime = time(nullptr)):
    text(text), chatName(chatName), messageTime(messageTime){

    }
    Message(std::string text = "", std::string chatName = ""):
    text(text), chatName(chatName){
        messageTime = std::time(0);
    }

    Message setText(std::string text){
        this -> text = text;
    }
    Message setChatName(std::string chatName){
        this -> chatName = chatName;
    }
    Message setTime(time_t messageTime){
        this -> messageTime = messageTime;
    }

    std::string getText() const{
        return text;
    }
    std::string getChatName() const{
        return chatName;
    }
    time_t getTime(){
        return messageTime;
    }


};


#endif //UNTITLED_MESSAGE_H
