#pragma once

#include "bits/stdc++.h"

using namespace std;


/**
@brief 使用SFML图形库绘制由Graph对象表示的图形。
@param window SFML窗口。
@param pos 顶点(x, y)坐标。
@param path 路径顶点
@param path_state 是否绘制路径
@param G 图。
**/
void drawGraph(sf::RenderWindow &window, vector<pair<int, int>> pos, vector<int> &path, bool path_state, Graph<int> &G);

/**
@brief 创建一个 SFML 文本对象，设置其内容、位置和颜色。
@param content 文本对象的内容。
@param x 文本对象的 x 坐标。
@param y 文本对象的 y 坐标。
@return  SFML 文本对象。
**/
sf::Text createText(string content,  int x, int y);

/**

@brief 创建一个 SFML 矩形形状对象，设置其大小、位置、填充颜色和边框样式。
@param shape 矩形对象的大小。
@param x 矩形对象的 x 坐标。
@param y 矩形对象的 y 坐标。
@return SFML 矩形对象。
**/
sf::RectangleShape createRect(sf::Vector2f shape, int x, int y);


/**
@brief 处理 SFML 事件，根据输入框是否被选中，相应输入。
@param event SFML 事件对象。
@param input_text 要处理的 SFML 文本对象，表示输入框中的文本。
@param input_selected 表示输入框是否被选中。
**/
void textInputProcess(sf::Event &event, sf::Text &input_text, bool &input_selected);

/**
@brief 处理鼠标左键按下事件,判断点击输入框或提交按钮。
@param window 游戏窗口对象
@param event 事件对象
@param input1_text 输入框1文本对象
@param input2_text 输入框2文本对象
@param input1_selected 输入框1选中状态
@param input2_selected 输入框2选中状态
@param input1 输入框1矩形对象
@param input2 输入框2矩形对象
@param button 按钮对象
@param path_state 路径状态
@param path 路径数组
@param G 图对象
@param output_text 输出文本对象
*/
void handleMouseButtonPressed(sf::RenderWindow &window, sf::Event &event, sf::Text &input1_text, sf::Text &input2_text,
                              bool &input1_selected, bool &input2_selected, sf::RectangleShape &input1,
                              sf::RectangleShape &input2, sf::RectangleShape &button, bool &path_state,
                              vector<int> &path, Graph<int> &G, sf::Text &output_text);


#include "Tools.ipp"
