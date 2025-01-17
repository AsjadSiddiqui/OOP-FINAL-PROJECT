#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
//#include "game.h"
class Well
{ 
friend class I_tetrimino;
private:    
    int grid[20][10];
    sf::RectangleShape* square;
    float xpos;
    float ypos;
    int squareindex;
public:
    Well()
    {
        squareindex = 0;
        xpos = 0;
        ypos = 0;
        for(int i = 0; i < 20; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                grid[i][j] = 0;
            }
        }
        square = new sf::RectangleShape[200];
        for(int i = 0; i < 20; i++)
        {
            xpos = 0;
            for(int j = 0; j < 10; j++)
            {
                square[squareindex] = sf::RectangleShape();
                square[squareindex].setPosition(sf::Vector2f(xpos,ypos));
                square[squareindex].setSize(sf::Vector2f(50.0f,50.0f));
                square[squareindex].setFillColor(sf::Color::Cyan);
                square[squareindex].setOutlineColor(sf::Color::Blue);
                squareindex++;
                xpos += 55;
            }
            ypos += 55;
        }
        
    }
    void setXpos(int x)
    {
        xpos = x;
    }
    int getXpos()
    {
        return xpos;
    }
    void setYpos(int y)
    {
        ypos = y;
    }
    int getYpos()
    {
        return ypos;
    }
    int* operator [] (int index)
    {
        return grid[index];
    }
    void operator = (Well& RHS)
    {
        for(int i = 0; i < 20; i++)
        {
            for(int j = 0; j < 20; j++)
            {
                grid[i][j] = RHS.grid[i][j];
            }
        }
    }
    sf::RectangleShape getSquare(int index)
    {
        return square[index];
    }
    void DrawWell(sf::RenderWindow* window)
    {
        squareindex = 0;
        for(int i = 0; i < 20; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(grid[i][j] == 0)
                {
                    square[squareindex].setFillColor(sf::Color::Cyan);
                }
                else if(grid[i][j] == 1)
                {
                    square[squareindex].setFillColor(sf::Color::Red);
                }
                squareindex++;
            }
        }
        for(int i = 0; i < 200; i++)
            window->draw(square[i]);
    }
    ~Well()
    {
        delete[] square;
    }
};