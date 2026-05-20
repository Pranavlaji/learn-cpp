#include <iostream>
#include <random>

int sensorOutput(int mainData,int error,int errorRate){
    int output{};
    if(errorRate > 9){
        output = error;
    }
    else{
        output = mainData;
    }
    return output;
}

int main(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distMain(1,20);
    std::uniform_int_distribution<> distError(50,100);
    std::uniform_int_distribution<> distErrorRate(0,10);

    std::vector<int> readings{};
    int sensorReadingOutput{20};
    int window{3};
    std::vector<int> finalOutput{};

    std::cout << "Raw Sensor Reading\n";
    for(int i{0}; i<sensorReadingOutput; ++i){
        readings.push_back(sensorOutput(distMain(gen), distError(gen), distErrorRate(gen)));
        std::cout << readings[i] << "\n";
    }

    for(int i{0}; i<sensorReadingOutput;++i){
        int tempSensor{0};
        int windowChecker{0};
        for(int j{i};j<i+window && j < sensorReadingOutput;j++){
            tempSensor = tempSensor + readings[j];
            windowChecker++;
        }
        if(windowChecker == window){
            finalOutput.push_back(tempSensor/window);
        }
    }
    std::cout << "Output Reading\n";
    
    for(std::size_t i{0}; i < finalOutput.size(); ++i){
        std::cout << finalOutput[i] << "\n";
    }
    
}
