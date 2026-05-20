#include <iostream>
#include <cmath>

int main(){
    float finalState{};
    float currentState{};
    float error{};
    float change{};
    float totalError{0};
    float prevError{0};
    float tol{0.01};
    float P{};
    float kp{1.025};
    float I{};
    float ki{0};
    float D{};
    float kd{0.00001};

    std::cout << "Enter Final State:";
    std::cin >> finalState;
    std::cout << "Enter Current State:";
    std::cin >> currentState;
    error = finalState - currentState;

    while(std::abs(error)>tol){


        totalError += error;
        P = kp * error;
        I = ki * totalError;
        D = kd * (error - prevError);

        change = P + I + D;
        currentState += change;
        prevError = error;
        error = finalState - currentState;
            
        std::cout << "New change:"<< change << "\n";
        std::cout << "Current error:"<< error << "\n";
        std::cout << "Current state:"<< currentState << "\n";

    } 
    std::cout << "System has reached state:" << currentState;
}
