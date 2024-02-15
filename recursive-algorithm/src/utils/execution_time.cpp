#include "../../include/execution_time.h"

void ExecutionTime::start() {
    if (!this -> is_active) {
        this -> start_time_ = std::chrono::high_resolution_clock::now();
        this -> is_active = !this -> is_active;
    }
}

void ExecutionTime::end() {
    if (this -> is_active) {
        this -> end_time_ = std::chrono::high_resolution_clock::now();
        this -> is_active = !this -> is_active;
    }
}

std::chrono::duration <double> ExecutionTime::getTimeInSeconds() {
    return this -> end_time_ - this -> start_time_;
}