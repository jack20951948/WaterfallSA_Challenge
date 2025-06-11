#ifndef YOUTUBESUBSCRIBER_HPP
#define YOUTUBESUBSCRIBER_HPP

#include <iostream>
#include <string>
#include "YouTubeObserver.hpp"

class YouTubeSubscriber : public YouTubeObserver {
private:
    // callback function
    std::function<void(YouTubeChannel&, const Video&)> callback;
public:
    YouTubeSubscriber(const std::string& observerName, 
                        std::function<void(YouTubeChannel&, const Video&)> callbackFunc = nullptr);
    void update(YouTubeChannel& sender, const Video& video) override;
    void setCallback(std::function<void(YouTubeChannel&, const Video&)> callbackFunc);
};

#endif // YOUTUBESUBSCRIBER_HPP