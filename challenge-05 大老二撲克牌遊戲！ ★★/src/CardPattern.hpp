#ifndef CARDPATTERN_HPP
#define CARDPATTERN_HPP

enum class CardPattern {
    SINGLE,
    PAIR,
    STRAIGHT,
    FULL_HOUSE,
    UNSUPPORTED,
};

inline std::ostream& operator<<(std::ostream& os, const CardPattern& pattern) {
    switch (pattern) {
        case CardPattern::SINGLE:
            os << "單張";
            break;
        case CardPattern::PAIR:
            os << "對子";
            break;
        case CardPattern::STRAIGHT:
            os << "順子";
            break;
        case CardPattern::FULL_HOUSE:
            os << "葫蘆";
            break;
        default:
            os << "Unsupported";
            break;
    }
    return os;
}

#endif // CARDPATTERN_HPP