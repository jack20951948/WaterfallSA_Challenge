#include "YouTubeSubscriber.hpp"

YouTubeSubscriber::YouTubeSubscriber(const std::string& observerName, 
                                        std::function<void(YouTubeChannel&, const Video&)> callbackFunc)
    : YouTubeObserver(observerName), callback(callbackFunc) {
    // Constructor implementation
}

void YouTubeSubscriber::update(YouTubeChannel& sender, const Video& video) {
    // Call the callback function if it's set
    if (callback) {
        callback(sender, video);
    } else {
        throw std::runtime_error("Callback function not set.");
    }
}

void YouTubeSubscriber::setCallback(std::function<void(YouTubeChannel&, const Video&)> callbackFunc) {
    callback = callbackFunc;
}