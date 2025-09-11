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
}

void Game::ComposeFrame()
{
    // Reticle centered in lower right quadrant (center: 599, 449)
    // Horizontal line (left)
    gfx.PutPixel(594, 449, 255, 255, 255);
    gfx.PutPixel(595, 449, 255, 255, 255);
    gfx.PutPixel(596, 449, 255, 255, 255);

    // Horizontal line (right)
    gfx.PutPixel(602, 449, 255, 255, 255);
    gfx.PutPixel(603, 449, 255, 255, 255);
    gfx.PutPixel(604, 449, 255, 255, 255);

    // Vertical line (top)
    gfx.PutPixel(599, 444, 255, 255, 255);
    gfx.PutPixel(599, 445, 255, 255, 255);
    gfx.PutPixel(599, 446, 255, 255, 255);

    // Vertical line (bottom)
    gfx.PutPixel(599, 452, 255, 255, 255);
    gfx.PutPixel(599, 453, 255, 255, 255);
    gfx.PutPixel(599, 454, 255, 255, 255);
}
