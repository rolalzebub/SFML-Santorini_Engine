#include "gameTile.h"
//void gameTile::draw(sf::RenderWindow& w)
//{
//    sf::RectangleShape rectangle;
//    rectangle.setOutlineThickness(5);
//    sf::Color cOutline;
//    sf::Color cFill;
//    cOutline = sf::Color(0xf2f0e6ff);
//    cFill = sf::Color(0xdfd8bfff);
//
//    if (level == 0) {
//        cFill = sf::Color(0x769D66ff);
//        rectangle.setSize(sf::Vector2f(110, 110));
//        rectangle.setPosition(x * 120 + 5, y * 120 + 5);
//        rectangle.setFillColor(cFill);
//        w.draw(rectangle);
//    }
//    else {
//        int limit = (level < 4) ? level : 3;
//        for (int i = 0; i < limit; i++) {
//            int s = 110 - (i * 20);
//            rectangle.setSize(sf::Vector2f(s, s));
//            rectangle.setPosition((x * 120) + (i * 10) + 5, (y * 120) + (i * 10) + 5);
//            rectangle.setOutlineColor(cOutline);
//            rectangle.setFillColor(cFill);
//            w.draw(rectangle);
//        }
//    }
//    if (level == 4) {
//        sf::CircleShape circle(40);
//        circle.setPosition(x * 120 + 20, y * 120 + 20);
//        circle.setFillColor(sf::Color(0x0000afff));
//        w.draw(circle);
//    }
//}

bool gameTile::build()
{
    std::cout << "Build: " << GetTransform()->GetTransformable().getPosition().x << " " << GetTransform()->GetTransformable().getPosition().y << " " << level << std::endl;
    if (level < 4) {
        level++;
        return true;
    }
    return false;
}