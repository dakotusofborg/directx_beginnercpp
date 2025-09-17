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

	const int left_dynamic = dynamicX - 5;
	const int right_dynamic = dynamicX + 5;
	const int top_dynamic = dynamicY - 5;
	const int bottom_dynamic = dynamicY + 5;

	const int left_static = staticX - 5;
	const int right_static = staticX + 5;
	const int top_static = staticY - 5;
	const int bottom_static = staticY + 5;

    if( left_dynamic < right_static &&
        right_dynamic > left_static &&
        top_dynamic < bottom_static &&
        bottom_dynamic > top_static )
    {
        colliding = true;
    }
    else
    {
        colliding = false;
	}

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

    /*if (x >= staticX - tolerance && x <= staticX + tolerance && y >= staticY - tolerance && y <= staticY + tolerance)
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
    if (colliding)
    {
        dynamicR = 255;
        dynamicG = 0;
        dynamicB = 0;
    }
    else
    {
        dynamicR = 255;
        dynamicG = 255;
        dynamicB = 255;
	}
    
    if (shapeIsChanged)
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
    else
    {
        gfx.PutPixel(-5 + dynamicX, -5 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(-5 + dynamicX, -4 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(-5 + dynamicX, -3 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(-4 + dynamicX, -5 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(-3 + dynamicX, -5 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(-5 + dynamicX, 5 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(-5 + dynamicX, 4 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(-5 + dynamicX, 3 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(-4 + dynamicX, 5 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(-3 + dynamicX, 5 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(5 + dynamicX, -5 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(5 + dynamicX, -4 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(5 + dynamicX, -3 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(4 + dynamicX, -5 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(3 + dynamicX, -5 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(5 + dynamicX, 5 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(5 + dynamicX, 4 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(5 + dynamicX, 3 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(4 + dynamicX, 5 + dynamicY, dynamicR, dynamicG, dynamicB);
        gfx.PutPixel(3 + dynamicX, 5 + dynamicY, dynamicR, dynamicG, dynamicB);
    }

    gfx.PutPixel(-5 + staticX, -5 + staticY, staticR, staticG, staticB);
    gfx.PutPixel(-5 + staticX, -4 + staticY, staticR, staticG, staticB);
    gfx.PutPixel(-5 + staticX, -3 + staticY, staticR, staticG, staticB);
    gfx.PutPixel(-4 + staticX, -5 + staticY, staticR, staticG, staticB);
    gfx.PutPixel(-3 + staticX, -5 + staticY, staticR, staticG, staticB);

    gfx.PutPixel(-5 + staticX, 5 + staticY, staticR, staticG, staticB);
    gfx.PutPixel(-5 + staticX, 4 + staticY, staticR, staticG, staticB);
    gfx.PutPixel(-5 + staticX, 3 + staticY, staticR, staticG, staticB);
    gfx.PutPixel(-4 + staticX, 5 + staticY, staticR, staticG, staticB);
    gfx.PutPixel(-3 + staticX, 5 + staticY, staticR, staticG, staticB);
                                                      
    gfx.PutPixel(5 + staticX, -5 + staticY, staticR, staticG, staticB);
    gfx.PutPixel(5 + staticX, -4 + staticY, staticR, staticG, staticB);
    gfx.PutPixel(5 + staticX, -3 + staticY, staticR, staticG, staticB);
    gfx.PutPixel(4 + staticX, -5 + staticY, staticR, staticG, staticB);
    gfx.PutPixel(3 + staticX, -5 + staticY, staticR, staticG, staticB);

    gfx.PutPixel(5 + staticX, 5 + staticY, staticR, staticG, staticB);
    gfx.PutPixel(5 + staticX, 4 + staticY, staticR, staticG, staticB);
    gfx.PutPixel(5 + staticX, 3 + staticY, staticR, staticG, staticB);
    gfx.PutPixel(4 + staticX, 5 + staticY, staticR, staticG, staticB);
    gfx.PutPixel(3 + staticX, 5 + staticY, staticR, staticG, staticB);
}
