#include "YouTubeChannel.hpp"

YouTubeChannel::YouTubeChannel(const std::string& channelName) : name(channelName) {}

const std::string& YouTubeChannel::getName() const {
    return name;
}

void YouTubeChannel::subscribe(YouTubeObserver* observer) {
    // check if the observer is already subscribed
    if (std::find(observers.begin(), observers.end(), observer) != observers.end())
        return;
    observers.push_back(observer);
    std::cout << observer->getName() << " 訂閱了 " << name << "。"  << std::endl;
}

void YouTubeChannel::unsubscribe(YouTubeObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    std::cout << observer->getName() << " 取消訂閱了 " << name << "。" << std::endl;
}

void YouTubeChannel::upload(const Video& video) {
    videos.push_back(video);
    std::cout << "頻道 " << name << " 上架了一則新影片 " << video.getTitle() << "。" << std::endl;
    notify(*this, video);
}

void YouTubeChannel::notify(YouTubeChannel& sender, const Video& video) {
    for (YouTubeObserver* observer : observers) {
        observer->update(*this, video);
    }
}