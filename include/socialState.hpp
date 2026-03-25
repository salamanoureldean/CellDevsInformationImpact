#ifndef SOCIAL_STATE_HPP_
#define SOCIAL_STATE_HPP_

#include <iostream>
#include <nlohmann/json.hpp>

struct socialState {
    // 0: Not Receive, 1: Receive, 2: Agree
    int value; 
    socialState() : value(0) {}
    socialState(int v) : value(v) {}
};

inline std::ostream& operator<<(std::ostream& os, const socialState& x) {
    os << "<" << x.value << ">";
    return os;
}

inline bool operator!=(const socialState& x, const socialState& y) {
    return x.value != y.value;
}

void from_json(const nlohmann::json& j, socialState& s) {
    j.at("value").get_to(s.value);
}

#endif