#include <ctime>
#include <iomanip>
#include "Timestamp.h"

auto createTimestamp() -> std::string {
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%c");
    return oss.str();
}