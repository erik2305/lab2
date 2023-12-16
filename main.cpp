#include <iostream>
#include <ctime>

int main() {
    time_t messageTime = std::time(0);
    tm* localtm = localtime(&messageTime);
    std::cout << asctime(localtm)<< std::endl;
    return 0;
}
