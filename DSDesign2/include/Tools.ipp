

void drawGraph(sf::RenderWindow &window, vector<pair<int, int>> pos, vector<int> &path, bool path_state, Graph<int> &G) {
    //draw circle
    for (int i = 1; i <= G.vex_num; i++) {
        sf::CircleShape circle(10);
        circle.setPosition(pos[i].first - 10, pos[i].second - 10);
        circle.setFillColor(sf::Color::White);
        circle.setOutlineThickness(3);
        circle.setOutlineColor(sf::Color::Black);
        window.draw(circle);

        sf::Text text = createText(to_string(i),pos[i].first - 5, pos[i].second - 15);
        text.setFillColor(sf::Color::Blue);
        window.draw(text);
    }
    //draw line
    for (int i = 1; i <= G.vex_num; i++) {
        for (int j = 0; j < G.G[i].size(); j++) {
            Edge e = G.G[i][j];
            int u = i, v = e.to;

            sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(pos[u].first, pos[u].second), sf::Color::Black),
                    sf::Vertex(sf::Vector2f(pos[v].first, pos[v].second), sf::Color::Black)
            };
            window.draw(line, 2, sf::Lines);

            sf::Text text = createText(to_string(e.cost),  pos[u].first + pos[v].first >> 1,
                                       pos[u].second + pos[v].second >> 1);
            text.setCharacterSize(15);
            text.setFillColor(sf::Color::Red);

            window.draw(text);
        }
    }
    //draw path
    if (path_state) {
        for (int i = 0; i < path.size() - 1; i++) {
            sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(pos[path[i]].first, pos[path[i]].second), sf::Color::Red),
                    sf::Vertex(sf::Vector2f(pos[path[i + 1]].first, pos[path[i + 1]].second), sf::Color::Red)
            };
            window.draw(line, 2, sf::Lines);
        }
    }

}

void textInputProcess(sf::Event &event, sf::Text &input_text, bool &input_selected) {
    // 如果输入框被选中
    if (input_selected) {
        // 如果按下了退格键，并且输入框中有字符
        if (event.text.unicode == 8 && input_text.getString().getSize() > 0) {
            // 从输入框中删除最后一个字符
            input_text.setString(input_text.getString().substring(0, input_text.getString().getSize() - 1));
        }
            // 如果输入数字键
        else if (event.text.unicode >= '0' && event.text.unicode <= '9') {
            // 在输入框中添加字符
            input_text.setString(input_text.getString() + static_cast<char>(event.text.unicode));
        }
    }
}


void handleMouseButtonPressed(sf::RenderWindow &window, sf::Event &event, sf::Text &input1_text, sf::Text &input2_text,
                              bool &input1_selected, bool &input2_selected, sf::RectangleShape &input1,
                              sf::RectangleShape &input2, sf::RectangleShape &button, bool &path_state,
                              vector<int> &path, Graph<int> &G, sf::Text &output_text) {
    // 检查是否为鼠标左键按下事件
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        // 获取鼠标位置
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

        // 检查鼠标是否在输入框1内
        if (input1.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y)) {
            input1_selected = true;
            input2_selected = false;
        }
            // 检查鼠标是否在输入框2内
        else if (input2.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y)) {
            input1_selected = false;
            input2_selected = true;
        }
            // 检查鼠标是否在提交内
        else if (button.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y)) {
            // 解析输入框中的数字
            int s, t;
            stringstream ss1(input1_text.getString()), ss2(input2_text.getString());
            ss1 >> s;
            ss2 >> t;

            // 进行 Dijkstra 算法，并记录路径
            auto d_pre = G.dijkstra(s);
            if (d_pre.first[t] == (1 << 30)) {
                // 如果无法到达目标节点，则更新输出文本和路径状态
                output_text.setString("UNABLE");
                path_state = false;
            } else {
                // 否则，更新输出文本、路径和路径状态
                output_text.setString(to_string(d_pre.first[t]));
                path = G.findPath(t, d_pre.second);
                path_state = true;
            }

            // 取消输入框的选中状态
            input1_selected = input2_selected = false;
        }
            // 如果鼠标不在任何元素内，则取消输入框的选中状态
        else {
            input1_selected = input2_selected = false;
        }
    }
}


sf::Text createText(string content, int x, int y) {
    sf::Text text(content, font, 20);
    text.setPosition(x, y);
    text.setFillColor(sf::Color::Black);
    return text;
}

sf::RectangleShape createRect(sf::Vector2f shape, int x, int y) {
    sf::RectangleShape rect(shape);
    rect.setPosition(x, y);
    rect.setFillColor(sf::Color::Black);
    rect.setOutlineThickness(2);
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::Black);
    return rect;
}
