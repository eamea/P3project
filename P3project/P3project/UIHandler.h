#pragma once
#include <string>

using namespace std;

/*This class is used for defining and setting up the (G)UI. It includes 
  functions for loading the different screens, as well as functions for 
  creating buttons, headers, overlays and the like.*/

class UIHandler
{
public:
	UIHandler();					//constructor
	void loadScreenStart();			//loading the Start screen
	void loadScreenLetters();		//loading the Choose Letters screen.
	void loadScreenInstruction();	//loading the Instructions screen.
	void loadScreenLearn();			//loading the Learning screen.

private:
	void button(string text, int posX, int posY);			//creates a regular button with the input text at the input (x,y)
	void exitButton(int posX, int posY);					//creates an exit-button at position (x,y)
	void letterButton(string text, int posX, int posY);		//creates a letter button which can be selected or de-selected
	void overlay();											//creates an overlay
	void header(string text, int posX, int posY);			//creates a header with the input text at the input (x,y).
};

