#ifndef YOUTUBEOBSERVER_HPP
#define YOUTUBEOBSERVER_HPP

#include "Video.hpp"

class YouTubeChannel; // Forward declaration

class YouTubeObserver {
protected:
    std::string name;
public:
    YouTubeObserver(const std::string& observerName) : name(observerName) {}
    const std::string& getName() const {
        return name;
    }
    virtual void update(YouTubeChannel& sender, const Video& video) = 0;
};

#endif // YOUTUBEOBSERVER_HPP