#include "utils/count_digits.cpp"

int countDigits(long long n) {
    if (n == 0)
        return 1;

    return static_cast<int>(log10(std::abs(n))) + 1;
}