// Created by Satwik on 3/4/25.
#include <SFML/Graphics.hpp>
#include <cstdlib> 
#include <ctime>   
#include <iostream> 
using namespace sf;

int main() {
    RenderWindow window(VideoMode(1920, 1080), "Timber");

   
    Texture backgroundTexture, treeTexture, beeTexture, cloudTexture,playerTexture,axeTexture;
    backgroundTexture.loadFromFile("graphics/background.png");    
    treeTexture.loadFromFile("graphics/tree.png");    
    beeTexture.loadFromFile("graphics/bee.png");
    cloudTexture.loadFromFile("graphics/cloud.png");
    playerTexture.loadFromFile("graphics/player.png");
    axeTexture.loadFromFile("graphics/axe.png");

    Sprite backgroundSprite(backgroundTexture);
    Sprite treeSprite(treeTexture);
    Sprite beeSprite(beeTexture);
    Sprite cloudSprite1(cloudTexture), cloudSprite2(cloudTexture), cloudSprite3(cloudTexture), cloudSprite4(cloudTexture), cloudSprite5(cloudTexture), cloudSprite6(cloudTexture);
    Sprite playerSprite(playerTexture);
    Sprite axeSprite(axeTexture);

    backgroundSprite.setPosition(0, 0);
    treeSprite.setPosition(900, 0);
    cloudSprite1.setPosition(100, 0);
    cloudSprite2.setPosition(500, 0);
    cloudSprite3.setPosition(800, 0);
    cloudSprite4.setPosition(900, 0);
    cloudSprite5.setPosition(1000, 0);
    cloudSprite6.setPosition(1200, 0);
    
    beeSprite.setPosition(1920, 500);

    playerSprite.setPosition(1200,700);
    axeSprite.setPosition(1100,800);
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
    float treeScaleY = 1;
    //jump
    float playerVelocityY = 0;  
    bool isJumping = false;  
    const float gravity = 980.0f;   
    const float jumpStrength = -600.0f;  
    const float groundY = 700;  
    const float playerSpeed = 400.0f; // Speed for left/right movement
    Keyboard k;
     axeSprite.setOrigin(120,0);
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed){
                window.close();
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space && !isJumping) {
                playerVelocityY = jumpStrength;   
                isJumping = true;   
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::LControl) {
                axeSprite.setRotation(-40);
            }
            if (event.type == Event::KeyReleased && event.key.code == Keyboard::LControl) {
                axeSprite.setRotation(40);
            }
        }
        
        // Player movement left/right
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            playerSprite.setScale(1,1);
            playerSprite.move(-playerSpeed * deltaTime, 0);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            playerSprite.setScale(-1,1);
            playerSprite.move(playerSpeed * deltaTime, 0);
        }
        
        beeSprite.move(beeSpeedX * deltaTime, beeSpeedY * deltaTime);
        cloudSprite1.move(cloud1SpeedX*deltaTime,0);
        cloudSprite2.move(cloud2SpeedX*deltaTime,0);
        cloudSprite3.move(cloud3SpeedX*deltaTime,0);
        cloudSprite4.move(cloud4SpeedX*deltaTime,0);
        cloudSprite5.move(cloud5SpeedX*deltaTime,0);
        cloudSprite6.move(cloud6SpeedX*deltaTime,0);
        treeSprite.setScale(1,treeScaleY);
        
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
        playerVelocityY += gravity * deltaTime;
        playerSprite.move(0, playerVelocityY * deltaTime);

        if (playerSprite.getPosition().y >= groundY) {
            playerSprite.setPosition(playerSprite.getPosition().x, groundY);
            isJumping = false;
            playerVelocityY = 0;
        }
        axeSprite.setPosition(playerSprite.getPosition().x,playerSprite.getPosition().y+105);
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
        window.draw(playerSprite);
        window.draw(axeSprite);
        window.draw(beeSprite);
        window.display();
    }

    return 0;
}
