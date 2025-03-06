// Created by Satwik on 3/4/25.
#include <SFML/Graphics.hpp>
#include <cstdlib> 
#include <ctime>    
using namespace sf;

int main() {
    RenderWindow window(VideoMode(1920, 1080), "Timber");

   
    Texture backgroundTexture, treeTexture, beeTexture, cloudTexture;
    backgroundTexture.loadFromFile("graphics/background.png");    
    treeTexture.loadFromFile("graphics/tree.png");    
    beeTexture.loadFromFile("graphics/bee.png");
    cloudTexture.loadFromFile("graphics/cloud.png");

   
    Sprite backgroundSprite(backgroundTexture);
    Sprite treeSprite(treeTexture);
    Sprite beeSprite(beeTexture);
    Sprite cloudSprite1(cloudTexture), cloudSprite2(cloudTexture), cloudSprite3(cloudTexture), cloudSprite4(cloudTexture), cloudSprite5(cloudTexture), cloudSprite6(cloudTexture);

   
    backgroundSprite.setPosition(0, 0);
    treeSprite.setPosition(900, 0);
    cloudSprite1.setPosition(100, 0);
    cloudSprite2.setPosition(500, 0);
    cloudSprite3.setPosition(800, 0);
    cloudSprite4.setPosition(900, 0);
    cloudSprite5.setPosition(1000, 0);
    cloudSprite6.setPosition(1200, 0);
    
    beeSprite.setPosition(1920, 500);

    
    std::srand(static_cast<unsigned>(std::time(nullptr)));  

    float beeSpeedX = -(200 + std::rand() % 100); 
    float beeSpeedY = (std::rand() % 100) - 50;    
    float cloud1SpeedX = (2 + std::rand() % 100); 
    float cloud1SpeedY = (std::rand() % 100) - 90;    
    float cloud2SpeedX = (2 + std::rand() % 100); 
    float cloud2SpeedY = (std::rand() % 100) - 90;    
    float cloud3SpeedX = (2 + std::rand() % 100); 
    float cloud3SpeedY = (std::rand() % 100) - 90;    
    float cloud4SpeedX = (2 + std::rand() % 100); 
    float cloud4SpeedY = (std::rand() % 100) - 90;   
    float cloud5SpeedX = (2 + std::rand() % 100); 
    float cloud5SpeedY = (std::rand() % 100) - 90;   
    float cloud6SpeedX = (2 + std::rand() % 100); 
    float cloud6SpeedY = (std::rand() % 100) - 90;   
    Clock clock;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

       
        float deltaTime = clock.restart().asSeconds();
      
        beeSprite.move(beeSpeedX * deltaTime, beeSpeedY * deltaTime);
        cloudSprite1.move(cloud1SpeedX*deltaTime,0);
        cloudSprite2.move(cloud2SpeedX*deltaTime,0);
        cloudSprite3.move(cloud3SpeedX*deltaTime,0);
        cloudSprite4.move(cloud4SpeedX*deltaTime,0);
        cloudSprite5.move(cloud5SpeedX*deltaTime,0);
        cloudSprite6.move(cloud6SpeedX*deltaTime,0);

        
        if (beeSprite.getPosition().x < -100) {
            float newY = 300 + (std::rand() % 400);
            beeSprite.setPosition(1920, newY);
            beeSpeedX = -(200 + std::rand() % 100); 
            beeSpeedY = (std::rand() % 100) - 50;    
        }
        if(cloudSprite1.getPosition().x>window.getSize().x){
            cloudSprite1.setPosition(-300,0);
        }
        if(cloudSprite2.getPosition().x>window.getSize().x){
            cloudSprite2.setPosition(-300,0);
        }
        if(cloudSprite3.getPosition().x>window.getSize().x){
            cloudSprite3.setPosition(-300,0);
        }
        if(cloudSprite4.getPosition().x>window.getSize().x){
            cloudSprite4.setPosition(-300,0);
        }
        if(cloudSprite5.getPosition().x>window.getSize().x){
            cloudSprite5.setPosition(-300,0);
        }
        if(cloudSprite6.getPosition().x>window.getSize().x){
            cloudSprite6.setPosition(-300,0);
        }

        // Render
        window.clear();
        window.draw(backgroundSprite);
        window.draw(treeSprite);
        window.draw(cloudSprite1);
        window.draw(cloudSprite2);
        window.draw(cloudSprite3);
        window.draw(cloudSprite4);

        window.draw(cloudSprite5);

        window.draw(cloudSprite6);

        window.draw(beeSprite);
        window.display();
    }

    return 0;
}
