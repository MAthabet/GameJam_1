#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>

void renderShop(sf::RenderWindow& window, const std::string& shopImagePath, const std::string& coinsFilePath) {
    sf::Texture shopTexture;
    !shopTexture.loadFromFile(shopImagePath);

    sf::Sprite shopSprite(shopTexture);

    sf::View shopView(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));

    float viewOffsetX = 0;

    // Game loop
    sf::Clock clock;
    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Right) {
                viewOffsetX += 10;
            }
            if (event.key.code == sf::Keyboard::Left) {
                viewOffsetX -= 50;
            }
            if (event.key.code == sf::Keyboard::Escape) {
                return;
            }
        }
        viewOffsetX = std::max(0.0f, std::min(viewOffsetX, shopTexture.getSize().x - shopView.getSize().x));

        shopView.setCenter(viewOffsetX + shopView.getSize().x / 2, shopView.getSize().y / 2);

        window.setView(shopView);
        window.clear();
        window.draw(shopSprite);
        window.setView(window.getDefaultView());
        window.display();
    }
}
