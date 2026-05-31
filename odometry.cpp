#include <iostream>

int operations(float totalDistance, float outerArc, float innerArc, float angle, float width){
    totalDistance = (outerArc + innerArc )/2;
    angle = (outerArc - innerArc )/width;
    std::cout << "Total Distance travelled:" << totalDistance<< "\n";
    std::cout << "With an angle of:"<< angle<<"\n";
    return 0;
}
int main() {
    float wheelRadius{20};
    float width{100};
    float outerArc{};
    float innerArc{};
    float angle{};
    float leftSensorTicks{};
    float rightSensorTicks{};
    float sensorResolution{360};
    float resolution{};
    float leftRotation{};
    float leftRotationCount{};
    float rightRotation{};
    float rightRotationCount{};
    float totalDistance{};

    std::cout << "Enter Tick of left wheel:";
    std::cin >> leftSensorTicks;
    std::cout << "Enter Tick of right wheel:";
    std::cin >> rightSensorTicks;

    resolution = 360/sensorResolution;
    leftRotation = leftSensorTicks*resolution;
    rightRotation = rightSensorTicks*resolution;

    if(leftRotation>rightRotation){
        outerArc = wheelRadius * ((leftRotation * 3.141)/180);
        innerArc = wheelRadius * ((rightRotation * 3.141)/180);
        operations(totalDistance, outerArc, innerArc, angle, width);
    }
    else if (leftRotation<rightRotation){
        outerArc = wheelRadius * ((rightRotation * 3.141)/180);
        innerArc = wheelRadius * ((leftRotation * 3.141)/180);
        operations(totalDistance, outerArc, innerArc, angle, width);
    }
    else{
        outerArc = wheelRadius * ((rightRotation * 3.141)/180);
        std::cout << "Total Distance travelled:" << outerArc<< "\n";
        std::cout << "With an angle of:"<< 0 <<"\n";
    }
    return 0;
}
