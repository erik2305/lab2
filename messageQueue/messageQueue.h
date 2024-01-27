#ifndef UNTITLED_MESSAGEQUEUE_H
#define UNTITLED_MESSAGEQUEUE_H

#include <iostream>
#include <queue>
#include "../message/message.h"

namespace Lab2 {
    class messageQueue {
    private:
        std::queue<Message> messages;
        int size;

    public:
        messageQueue(){
            size = 2;
        }

         int getSize() const {
            return size;
        }

        messageQueue &setsize(int size) {
            this->size = size;
            return *this;
        }

        void increaseSize() {
            size++;
        }
        void decreaseSize() {
            size--;
        }

        void enqueue(const Message& msg);
        Message dequeue();
        enum QueueState { empty, partially_full, full };
        QueueState checkState() const;
        void mergeAdjacentMessages();
        messageQueue allocateMessagesToNewQueue(const std::string& chatName);
        Message findNearestMessageWithWord(const std::string& word) const;
        void organizeQueue();
        bool isEmpty() const;

        messageQueue& operator+=(const Message& msg);
        messageQueue operator[](const std::string& chatName);
    };
}


#endif //UNTITLED_MESSAGEQUEUE_H
