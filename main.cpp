#include <iostream>
#include <particle.h>
#include <vector>

sf::RenderWindow window(sf::VideoMode(800, 800), "Gravity Physics",sf::Style::Titlebar | sf::Style::Close);
std::vector <particle> pList;
std::vector <gravitySource> sList;

int main()
{
    window.setFramerateLimit(120);
    gravitySource s1(200.0f,400.0f,15.0f); sList.push_back(s1);
    gravitySource s2(600.0f,400.0f,15.0f); sList.push_back(s2);

    particle p1(200.0f,200.0f,0.2f,0.0f,sf::Color::Red); pList.push_back(p1);
    particle p2(600.0f,200.0f,-0.2f,0.0f,sf::Color::Blue); pList.push_back(p2);
    particle p3(600.0f,600.0f,-0.2f,0.0f,sf::Color::Green); pList.push_back(p3);
    particle p4(200.0f,600.0f,0.2f,0.0f,sf::Color::Magenta); pList.push_back(p4);
    particle p5(400.0f,400.0f,0.2f,0.2f,sf::Color::Cyan); pList.push_back(p5);
    particle p6(400.0f,400.0f,-0.2f,-0.2f,sf::Color::Cyan); pList.push_back(p6);
    //there's gotta be a better way to do this

    while (window.isOpen())
    {
        sf::Event event;
        
        window.clear();

        for (int i =0; i<sList.size();i++){
            for(int j=0; j<pList.size(); j++) {
                pList[j].update(sList[i]);
                pList[j].render(window);
            };
        }
        
        s1.render(window);
        s2.render(window);

        window.display();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close(); //closes the window
            // if (sf::Keyboard::Escape)
        }
    }
    return 0;
}
