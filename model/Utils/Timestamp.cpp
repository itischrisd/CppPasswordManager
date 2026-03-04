#include "Timestamp.h"

#include <ctime>
#include <iomanip>

auto createTimestamp() -> std::string {
    const std::time_t t = std::time(nullptr);
    const std::tm tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%c");
    return oss.str();
}
