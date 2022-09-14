#include <iostream>
#include "SFML/Graphics.hpp"

void aiMovement(sf::RectangleShape&, sf::Vector2f);
void ballMovement(sf::FloatRect&, sf::FloatRect&, sf::FloatRect&, sf::Vector2f&);

int main(){
    // Settings used when creating window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // Opens window with 1280 x 720 resolution titled Pong
    sf::RenderWindow mainWindow(sf::VideoMode(1280, 720), "Pong", sf::Style::Titlebar | sf::Style::Close, settings);
    mainWindow.setFramerateLimit(60);

    // Shapes used for game
    sf::RectangleShape paddle1(sf::Vector2f(40.f, 200.f));
    sf::RectangleShape paddle2 (sf::Vector2f(40.f, 200.f));
    sf::RectangleShape centerLine(sf::Vector2f(2.f, 720.f));
    sf::CircleShape ball(25.f);
    sf::Text end;

    // Data for arial font used
    sf::Font font;
    font.loadFromFile("arial.ttf");

    // Data and variables used for text at end of game
    end.setFont(font);
    end.setCharacterSize(45);
    end.setFillColor(sf::Color::Yellow);
    end.setStyle(sf::Text::Regular);

    // Default positions for game objects
    paddle1.setPosition(5, 260);
    paddle2.setPosition(1280 - 45, 260);
    ball.setPosition(1280/2 - 25, 720/2 - 25);
    centerLine.setPosition(640 - 2, 0);
    end.setPosition(1280/2 - 210, 720/2 - 200);

    // Bounding boxes for game objects
    sf::FloatRect paddleBox1 = paddle1.getGlobalBounds();
    sf::FloatRect paddleBox2 = paddle2.getGlobalBounds();
    sf::FloatRect ballBox = ball.getGlobalBounds();

    // Ball speed parameters
    sf::Vector2f ballSpeed;
    ballSpeed.x = -10.f;
    ballSpeed.y = 0.f;

    // Runs program as long as window remains open
    while(mainWindow.isOpen()){
        sf::Event event;

        // Position vectors used for game objects
        sf::Vector2f pos1 = paddle1.getPosition();
        sf::Vector2f pos2 = paddle2.getPosition();
        sf::Vector2f posBall = ball.getPosition();

        while(mainWindow.pollEvent(event)){
            // When event type = closed, window is closed and loop ends
            if(event.type == sf::Event::Closed){
                mainWindow.close();
            }
            if(pos1.y < 500){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                    paddle1.move(0.f, 20.f);
                }
            }
            if(pos1.y > 20){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                    paddle1.move(0.f, -20.f);
                }
            }
<<<<<<< HEAD
            if(paddleBox1.intersects(ballBox)){
                ballSpeed.x = -ballSpeed.x;
                ballSpeed.y = -ballSpeed.y;
            }
            else if(paddleBox2.intersects(ballBox)){
                ballSpeed.x = -ballSpeed.x;
                ballSpeed.y = -ballSpeed.y;
            }
            ball.move(ballSpeed.x, ballSpeed.y);
            if(posBall.x <= 0){
=======
            ballMovement(ball, posBall);
            if(posBall.x >= 1280 ){
>>>>>>> d67dd77007809ba300c2dd27e389547dca023cd2
                end.setString("Game Over, You Win!");
            }
            else if(posBall.x <= 0){
                end.setString("Game Over, You Lost!");
            }
            ballMovement(ballBox, paddleBox1, paddleBox2, ballSpeed);
            aiMovement(paddle2, pos2);

        }
        mainWindow.clear(sf::Color::Black);

        mainWindow.draw(paddle1);
        mainWindow.draw(paddle2);
        mainWindow.draw(ball);
        mainWindow.draw(centerLine);
        mainWindow.draw(end);

        mainWindow.display();
    }

    return 0;
}

void aiMovement(sf::RectangleShape &paddle, sf::Vector2f pos){

}
<<<<<<< HEAD
void ballMovement(sf::FloatRect &ball, sf::FloatRect &paddle1, sf::FloatRect &paddle2, sf::Vector2f &ballSpeed){
    if(paddle1.intersects(ball)){
        ballSpeed.x = -ballSpeed.x;
        ballSpeed.y = -ballSpeed.y;
    }
    else if(paddle2.intersects(ball)){
        ballSpeed.x = -ballSpeed.x;
        ballSpeed.y = -ballSpeed.y;
    }
=======
void ballMovement(sf::CircleShape &ball, sf::Vector2f pos){
    ball.move(-20.f, 0.f);
>>>>>>> d67dd77007809ba300c2dd27e389547dca023cd2
}
