#include "messageQueue.h"
#include <algorithm>

namespace Lab2 {

    bool messageQueue::isEmpty() const {
        return messages.empty();
    }

    void messageQueue::enqueue(const Message &msg) {
        messages.push(msg);
        increaseSize();
    }

    Message messageQueue::dequeue() {
        decreaseSize();
        if (!messages.empty()) {
            Message frontMessage = messages.front();
            messages.pop();
            return frontMessage;
        } else {
            throw std::out_of_range("Queue is empty");
        }
    }

//    messageQueue messageQueue::createWithMessages(const std::vector<Message>& messageArray) {
//        messageQueue newQueue;
//        for (const auto& msg : messageArray) {
//            newQueue.enqueue(msg);
//        }
//        return newQueue;
//    }

    messageQueue::QueueState messageQueue::checkState() const {
        if (messages.empty()) {
            return QueueState::empty;
        } else if (messages.size() < 3) {
            return QueueState::partially_full;
        } else {
            return QueueState::full;
        }
    }

    void messageQueue::mergeAdjacentMessages() {
        messageQueue tempQueue;
        while (!messages.empty()) {
            Message currentMessage = dequeue();
            while (!messages.empty() && messages.front().getChatName() == currentMessage.getChatName()) {
                currentMessage = Message::mergeMessages(currentMessage, dequeue());
            }
            tempQueue.enqueue(currentMessage);
        }
        messages = tempQueue.messages;
    }

    messageQueue messageQueue::allocateMessagesToNewQueue(const std::string& chatName) {
        messageQueue newQueue;
        messageQueue tempQueue;
        while (!messages.empty()) {
            Message currentMessage = dequeue();
            if (currentMessage.getChatName() == chatName) {
                newQueue.enqueue(currentMessage);
            } else {
                tempQueue.enqueue(currentMessage);
            }
        }
        messages = tempQueue.messages;
        return newQueue;
    }

    Message messageQueue::findNearestMessageWithWord(const std::string& word) const {
        messageQueue tempQueue = *this;  // Create a copy to avoid modifying the original
        while (!tempQueue.isEmpty()) {
            Message currentMessage = tempQueue.dequeue();
            if (currentMessage.findWord(word) != std::string::npos) {
                return currentMessage;
            }
        }
        throw std::out_of_range("Word not found in any message.");
    }

    void messageQueue::organizeQueue() {
        std::vector<Message> tempVector;
        while (!messages.empty()) {
            tempVector.push_back(dequeue());
        }

        std::sort(tempVector.begin(), tempVector.end(), [](Message& a, Message& b) {
            if (a.getChatName() == b.getChatName()) {
                return a.getTime() < b.getTime();
            }
            return a.getChatName() < b.getChatName();
        });

        for (const auto& msg : tempVector) {
            enqueue(msg);
        }
    }

    messageQueue& messageQueue::operator+=(const Message& msg) {
        enqueue(msg);
        return *this;
    }
    messageQueue messageQueue::operator[](const std::string& chatName) {
        return allocateMessagesToNewQueue(chatName);
    }
}