#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>

void renderShop(sf::RenderWindow& window, const std::string& shopImagePath, const std::string& coinsFilePath) {
    sf::Texture shopTexture;
    !shopTexture.loadFromFile(shopImagePath);
    shopTexture.setRepeated(true);
    sf::Sprite shopSprite(shopTexture);
    float offest = 0;
    // Game loop
    sf::Clock clock;
    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Right) {
                    offest += 800;
                }
                else if (event.key.code == sf::Keyboard::Left) {
                    offest -= 800;
                }
                else if (event.key.code == sf::Keyboard::Escape) {
                    return;
                }
            }
        }
        shopSprite.setTextureRect(sf::IntRect(offest, 0, shopTexture.getSize().x * 2, shopTexture.getSize().y));
        window.clear();
        window.draw(shopSprite);
        window.display();
    }
}
