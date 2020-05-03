#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


sf::RenderWindow window;
sf::Texture player;
sf::Sprite sprite_player;
sf::CircleShape shape(10.f);
enum Dir{ Down, Left, Right, Up };
sf::Vector2i anim(1,Down);
bool updatefps =true;
void gestion_clavier();
int blockSize = 32;
    float fpsCount = 0,
          switchFps = 10,
          fpsSpeed = 50;

int main()
{
    window.create(sf::VideoMode(600, 600), "First game");
    window.setFramerateLimit(30);
    
    shape.setFillColor(sf::Color(245,134,45));
    
    std::cout << "lancement du jeu" << std::endl;
    sf::Clock time;


    if(!player.loadFromFile("player2.png"))
    {

        std::cout << "erreur de chargement de player.png" << std::endl;
    }
    player.setSmooth(true);

    sprite_player.setTexture(player);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        gestion_clavier();
        if (updatefps)
          {
              fpsCount += fpsSpeed;
          }
        else
         {
             fpsCount = 0;
             updatefps = true;
         }

         if (fpsCount >= switchFps)
        {
            anim.x++;
        if(anim.x * blockSize >= player.getSize().x)
            anim.x = 0;
            updatefps= false;
            sprite_player.setTextureRect(sf::IntRect(anim.x * blockSize ,anim.y * blockSize,blockSize,blockSize));
          }

        
        
        

        //mise a jour
        window.clear();
        window.draw(shape);
        window.draw(sprite_player);
        window.display();
    }

    return 0;
}
void gestion_clavier()
{
        int m_i;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if (m_i>=switchFps)
            {
                updatefps = true;
                m_i=0;
            }

            m_i++;
            anim.y = Up;
            sprite_player.move(0,-1);
            
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (m_i>=switchFps)
            {
                updatefps = true;
                m_i=0;
            }

            m_i++;
            anim.y = Down;
            sprite_player.move(0,1);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (m_i>=switchFps)
            {
                updatefps = true;
                m_i=0;
            }

            m_i++;
            anim.y = Left;
            sprite_player.move(-1,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (m_i>=switchFps)
            {
                updatefps = true;
                m_i=0;
            }

            m_i++;
            anim.y = Right;
            sprite_player.move(1,0);
        }
        // Collision des bords
        /*
        if(sprite_player.getPosition.x <= 0)
        sprite_player.setPosition(sf::Vector2f(0, sprite_player.getPosition.y));
        
        if(sprite_player.getPosition.y <= 0)
        sprite_player.setPosition(sf::Vector2f(sprite_player.getPosition.x, 0));
        */

}