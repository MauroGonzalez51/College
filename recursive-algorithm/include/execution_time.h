#ifndef EXECUTION_TIME
#define EXECUTION_TIME
#include <chrono>

/**
 * ! Utility Class
 * 
 * Just for testing, and make the meassure of time more easier
 * 
 * 
 * 
 * 
 * 
 * 
*/

class ExecutionTime {
    private:
        std::chrono::high_resolution_clock::time_point start_time_;
        std::chrono::high_resolution_clock::time_point end_time_;
        bool is_active = false;

    public:
        void start();
        void end();
        std::chrono::duration <double> getTimeInSeconds();
};

#endif