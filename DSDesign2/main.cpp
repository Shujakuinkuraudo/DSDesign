#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

sf::Font font;
#include "include/Graph.hpp"
#include "include/Tools.hpp"
using namespace std;


int main() {
    srand(time(0));
    Graph<int> G;
    G.readFromFile("graph.txt");
    G.generatePos(0,150,500,500);


    font.loadFromFile("FiraCode-Bold.ttf");

    // 起终点 文本
    sf::Text input1_out_text = createText("start", 30, 20);
    sf::Text input2_out_text = createText("end", 30, 70);

    //起终点 输入框
    sf::Text input1_in_text = createText("", 205, 20);
    sf::Text input2_in_text = createText("", 205, 70);

    sf::RectangleShape input1_rect = createRect(sf::Vector2f(80, 30), 200, 20);
    sf::RectangleShape input2_rect = createRect(sf::Vector2f(80, 30), 200, 70);

    //提交按钮
    sf::RectangleShape button_rect = createRect(sf::Vector2f(90, 30), 150, 120);
    sf::Text button_out_text = createText("Submit", 160, 125);

    //距离
    sf::RectangleShape distance_rect = createRect(sf::Vector2f(150, 50), 400, 30);
    sf::Text distance_out_text = createText("INIT", 0, 0);
    distance_out_text.setCharacterSize(24);
    distance_out_text.setPosition(distance_rect.getPosition() + sf::Vector2f(10, 10));


    bool input1_selected = false,input2_selected = false;


    sf::RenderWindow window(sf::VideoMode(600, 600), "Visualization");

    bool draw_path_state = 0;
    vector<int> path;

    window.setFramerateLimit(30);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    handleMouseButtonPressed(window, event, input1_in_text, input2_in_text, input1_selected, input2_selected,
                                             input1_rect, input2_rect, button_rect, draw_path_state, path, G, distance_out_text);
                    break;
                case sf::Event::TextEntered:
                    textInputProcess(event, input1_in_text, input1_selected);
                    textInputProcess(event, input2_in_text, input2_selected);
                    break;

                default:
                    break;
            }
        }
        input1_rect.setOutlineColor(input1_selected ? sf::Color::Red : sf::Color::Black);
        input2_rect.setOutlineColor(input2_selected ? sf::Color::Red : sf::Color::Black);

        window.clear(sf::Color::White);

        vector<sf::Drawable*> elements = {&input1_out_text, &input1_rect, &input1_in_text, &input2_out_text, &input2_rect, &input2_in_text, &button_rect, &button_out_text, &distance_out_text, &distance_rect};
        for (auto element : elements) window.draw(*element);

        drawGraph(window, G.pos, path, draw_path_state, G );

        window.display();
    }



    return 0;
}
