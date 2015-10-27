#pragma once
#include <string>

using namespace std;

/*This class is used for defining and setting up the (G)UI. It includes 
  functions for loading the different screens, as well as functions for 
  creating buttons, headers, overlays and the like.*/

class UIHandler
{
public:
	UIHandler();					//constructor.
	void loadScreenStart();			//TODO loading the Start screen GUI.
	void loadScreenLetters();		//TODO loading the Choose Letters screen GUI.
	void loadScreenInstruction();	//TODO loading the Instructions screen GUI.
	void loadScreenLearn();			//TODO loading the Learning screen GUI.

private:
	void button(string text, int posX, int posY);			//TODO creates a regular button with the input text at the input (x,y)
	void exitButton(int posX, int posY);					//TODO creates an exit-button at position (x,y)
	void letterButton(string text, int posX, int posY);		//TODO creates a letter button which can be selected or de-selected
	void overlay();											//TODO creates an overlay
	void header(string text, int posX, int posY);			//TODO creates a header with the input text at the input (x,y).
};

