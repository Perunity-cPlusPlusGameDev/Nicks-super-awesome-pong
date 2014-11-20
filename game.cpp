//game.cpp

#include "Game.h"

//Game::Start() is global and shouldnt be called more than once
void Game::Start(void)
{
	/*"Uninitialized" is default value, when game created it will start
	uninitialized which is useless*/
	if(_gamestate != Uninitialized)
		return

	// VideoMode(Resoultion(1024x768),32bpp color),"Title"
	_mainWindow.Create(sd::VideoMode(1024,768,32),"Pong!");
	//switching game to playin state
	_gameState = Game::Playing;

	while(!IsExiting())
	{
	GameLoop();
	}

	_mainWindow.Close();
}

//closing the game
bool Game::IsExiting()
{
	if(_gameSAtate == Game::Exiting)
		return true;
	else
		return false;
}

//most important function, where everything happens
void Game::GameLoop()
{
	sf::Event currentEvent;
	//any new event is assigned to currentEvent, if no new than returns false
	while(_mainWindow.GetEvent(currentEvent))
	{

	  switch(_gameState) //gameState == Running, only one state at a time
	  {
		case Game::Playing:
		 {
		 _mainWindow.Clear(sf::Color(255,0,0));
		 _mainWindow.Display();

		 if(currentEvent.Type == sf::Event::Closed)
		   {
		     _gameState = Game::Exiting;
		   }
		 break;
		 }
		}
	}
}

//"Game's two member variables"
Game::GameState game::_gameState = Uninitialized;
sf:: RenderWindow Game::_mainWindow;