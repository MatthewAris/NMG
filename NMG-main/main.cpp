#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <Loop.h>

#include <cmath>
#include <iostream>
#include <thread>

using namespace sf;

void Print()
{
    for (int i = 0;  i < 500; i++){
        std::cout << "Good Day!!\n";
        std::this_thread::sleep_for(std::chrono::microseconds(50));
    }


}

int main()
{
    //std::thread t([]{Print();});
    //t.detatch;
    //
    //for (int i = 0; i < 500; i++){
    //    std::cout << "Hi from main: " << i << "\n";
    //    std::this_thread::sleep_for(std::chrono::microseconds(50));
    //}
    //t.join();

    srand(time(nullptr));
    Loop loop;
    std::thread lT0(&Loop::run &loop);

    std::thread lT1([&loop] {
        std::this_thread::sleep_for(std::chrono::seconds(rand() % 5));
        loop.setStop();
    });

    lT0.join();
    lT1.join();

    return 0;
}
