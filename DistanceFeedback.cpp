#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <string_view>

const char* RED = "\033[31m";
const char* GREEN = "\033[32m";
const char* YELLOW = "\033[33m";
const char* RESET = "\033[0m";

int main(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1,100);



    while(true){
        int sensorOutput {dist(gen)};
        if(sensorOutput<=25){
            std::cout << "Distance is:" << sensorOutput << "->" << RED << "DANGER\n" << RESET;
        }
        else if(sensorOutput>25 && sensorOutput<=50){
            std::cout << "Distance is:" << sensorOutput << "->" << YELLOW << "WARNING\n" << RESET;
        }
        else{
            std::cout << "Distance is:" << sensorOutput << "->" << GREEN << "SAFE\n" << RESET;
        }
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    return 0;
}