#include "YouTubeChannel.hpp"
#include "YouTubeSubscriber.hpp"
#include "Video.hpp"
#include <iostream>

int main() {
    // Create a YouTube channel
    YouTubeChannel waterBallChannel("水球軟體學院");
    YouTubeChannel pewDiePieChannel("PewDiePie");

    // Create a subscriber with a callback function
    YouTubeSubscriber waterball("水球", [](YouTubeChannel& sender, const Video& video) {
        if (video.getLength() >= 180) {
            std::cout << "水球 對影片 " << video.getTitle() << " 按讚。" << std::endl;
        }
    });
    YouTubeSubscriber fireball("火球", nullptr);
    fireball.setCallback([&fireball](YouTubeChannel& sender, const Video& video) {
        if (video.getLength() <= 60) {
            sender.unsubscribe(&fireball);
        }
    });

    // Subscribe to the channel
    waterBallChannel.subscribe(&waterball);
    pewDiePieChannel.subscribe(&waterball);
    waterBallChannel.subscribe(&fireball);
    pewDiePieChannel.subscribe(&fireball);


    // Upload a video
    Video video("C1M1S2", "這個世界正是物件導向的呢！", 240);
    waterBallChannel.upload(video);

    Video video2("Hello guys", "Clickbait", 30);
    pewDiePieChannel.upload(video2);

    Video video3("C1M1S3", "物件 vs. 類別", 60);
    waterBallChannel.upload(video3);

    Video video4("Minecraft", "Let’s play Minecraft", 30 * 60);
    pewDiePieChannel.upload(video4);

    return 0;
}