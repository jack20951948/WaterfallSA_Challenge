#ifndef VIDEO_HPP
#define VIDEO_HPP

#include <string>

class Video {
private:
    std::string title;
    std::string description;
    int length; // in seconds
public:
    Video(const std::string& videoTitle, const std::string& videoDescription, int videoLength)
        : title(videoTitle), description(videoDescription), length(videoLength) {}

    const std::string& getTitle() const { return title; }
    const std::string& getDescription() const { return description; }
    int getLength() const { return length; }
};

#endif // VIDEO_HPP