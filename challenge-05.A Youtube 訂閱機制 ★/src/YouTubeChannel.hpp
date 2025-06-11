#ifndef YOUTUBECHANNEL_HPP
#define YOUTUBECHANNEL_HPP

#include <string>
#include <vector>
#include <iostream>
#include "YouTubeObserver.hpp"
#include "Video.hpp"

class YouTubeChannel {
private:
    std::string name;
    std::vector<YouTubeObserver*> observers;
    std::vector<Video> videos;
public:
    YouTubeChannel(const std::string& channelName);
    const std::string& getName() const;
    void subscribe(YouTubeObserver* observer);
    void unsubscribe(YouTubeObserver* observer);
    void upload(const Video& video);
    void notify(YouTubeChannel& sender, const Video& video);
};

#endif // YOUTUBECHANNEL_HPP