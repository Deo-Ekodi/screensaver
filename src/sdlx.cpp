// #include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
 
void draw(sf::RenderWindow& window) {
    // Clear the screen
    window.clear(sf::Color::Black);

    // Draw random shapes
    srand(time(NULL));
    for (int i = 0; i < 100; ++i) {
        int x = rand() % SCREEN_WIDTH;
        int y = rand() % SCREEN_HEIGHT;
        int w = rand() % 100 + 20;
        int h = rand() % 100 + 20;
        sf::RectangleShape rect(sf::Vector2f(w, h));
        rect.setPosition(x, y);
        rect.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        window.draw(rect);
    }

    // Update the screen
    window.display();
}

int main() {
    // Create the window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Screensaver");

    // Main loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Draw
        draw(window);
    }

    return 0;
}
