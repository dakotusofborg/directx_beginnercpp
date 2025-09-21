/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
    if (wnd.kbd.KeyIsPressed(VK_RIGHT))
    {
        if (inhibitRight)
        {
        }
        else
        {
            vX = vX + 1;
            inhibitRight = true;
        }
    }
    else
    {
		inhibitRight = false;
    }

    if (wnd.kbd.KeyIsPressed(VK_LEFT))
    {
        if (inhibitLeft)
        {
        }
        else
        {
            vX = vX - 1;
            inhibitLeft = true;
		}
    }
    else
    {
		inhibitLeft = false;
    }

    if (wnd.kbd.KeyIsPressed(VK_DOWN))
    {
        if (inhibitDown)
        {
        }
        else
        {
            vY = vY + 1;
            inhibitDown = true;
        }
    }
    else
    {
		inhibitDown = false;
    }

    if (wnd.kbd.KeyIsPressed(VK_UP))
    {
        if (inhibitUp)
        {
        }
        else
        {
            vY = vY - 1;
            inhibitUp = true;
		}
    }
    else
    {
		inhibitUp = false;
    }

    colliding = 
        OverlapTest(staticX0, staticY0, dynamicX, dynamicY) ||
        OverlapTest(staticX1, staticY1, dynamicX, dynamicY) ||
        OverlapTest(staticX2, staticY2, dynamicX, dynamicY) ||
        OverlapTest(staticX3, staticY3, dynamicX, dynamicY);
	
    dynamicX = dynamicX + vX;
	dynamicY = dynamicY + vY;

    if (dynamicX + 5 >= gfx.ScreenWidth)
    {
        dynamicX = gfx.ScreenWidth - 6;
        vX = 0;
    }
    if (dynamicX - 5 < 0)
    {
        dynamicX = 5;
        vX = 0;
    }
    if (dynamicY + 5 >= gfx.ScreenHeight)
    {
        dynamicY = gfx.ScreenHeight - 6;
        vY = 0;
    }
    if (dynamicY - 5 < 0)
    {
        dynamicY = 5;
        vY = 0;
    }

    /*shapeIsChanged = false;
    if (!(x > 200 && x < 300))
    {
        shapeIsChanged = true;
    }*/

    /*if (x >= x - tolerance && x <= x + tolerance && y >= y - tolerance && y <= y + tolerance)
    {
        r = 255; g = 0; b = 0;
    }
    else
    {
        r = 255; g = 255; b = 255;
	}*/
}

void Game::ComposeFrame()
{
    DrawBox(staticX0, staticY0, 0, 255, 0);
    DrawBox(staticX1, staticY1, 0, 255, 0);
    DrawBox(staticX2, staticY2, 0, 255, 0);
    DrawBox(staticX3, staticY3, 0, 255, 0);

    DrawBox(dynamicX, dynamicY, 255, 255, 255);

    if (colliding)
    {
        DrawBox(dynamicX, dynamicY, 255, 0, 0);
    }
    else
    {
        DrawBox(dynamicX, dynamicY, 255, 255, 255);
	}
    
    /*if (shapeIsChanged)
    {
        gfx.PutPixel(-5 + dynamicX, dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(-4 + dynamicX, dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(-3 + dynamicX, dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(3 + dynamicX, dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(4 + dynamicX, dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(5 + dynamicX, dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(dynamicX, -5 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(dynamicX, -4 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(dynamicX, -3 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(dynamicX, 3 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(dynamicX, 4 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(dynamicX, 5 + dynamicY, dynamicR, dynamicG, dynamicB);
    }
    else*/
 
	
}

void  Game::DrawBox(int x, int y, int r, int g, int b)
{
    gfx.PutPixel(-5 + x, -5 + y, r, g, b);
    gfx.PutPixel(-5 + x, -4 + y, r, g, b);
    gfx.PutPixel(-5 + x, -3 + y, r, g, b);
    gfx.PutPixel(-4 + x, -5 + y, r, g, b);
    gfx.PutPixel(-3 + x, -5 + y, r, g, b);

    gfx.PutPixel(-5 + x, 5 + y, r, g, b);
    gfx.PutPixel(-5 + x, 4 + y, r, g, b);
    gfx.PutPixel(-5 + x, 3 + y, r, g, b);
    gfx.PutPixel(-4 + x, 5 + y, r, g, b);
    gfx.PutPixel(-3 + x, 5 + y, r, g, b);

    gfx.PutPixel(5 + x, -5 + y, r, g, b);
    gfx.PutPixel(5 + x, -4 + y, r, g, b);
    gfx.PutPixel(5 + x, -3 + y, r, g, b);
    gfx.PutPixel(4 + x, -5 + y, r, g, b);
    gfx.PutPixel(3 + x, -5 + y, r, g, b);

    gfx.PutPixel(5 + x, 5 + y, r, g, b);
    gfx.PutPixel(5 + x, 4 + y, r, g, b);
    gfx.PutPixel(5 + x, 3 + y, r, g, b);
    gfx.PutPixel(4 + x, 5 + y, r, g, b);
    gfx.PutPixel(3 + x, 5 + y, r, g, b);
}

bool Game::OverlapTest(int box0x, int box0y, int box1x, int box1y)
{
    const int left_box0 = box0x - 5;
    const int right_box0 = box0x + 5;
    const int top_box0 = box0y - 5;
    const int bottom_box0 = box0y + 5;

    const int left_box1 = box1x - 5;
    const int right_box1 = box1x + 5;
    const int top_box1 = box1y - 5;
    const int bottom_box1 = box1y + 5;

    return
        left_box0 <= right_box1 &&
        right_box0 >= left_box1 &&
        top_box0 <= bottom_box1 &&
        bottom_box0 >= top_box1;
}
