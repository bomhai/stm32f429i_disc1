#include <gui/screen1_screen/Screen1View.hpp>

//#include <touchgfx/Color.hpp>
//#include <texts/TextKeysAndLanguages.hpp>

#include "stdio.h"
#include "string.h"
Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();

    textViewBuffer[0] = 0;

    Screen1ViewBase::textView.setPosition(0, 38, 240, 282);
    Screen1ViewBase::textView.setWildcard(textViewBuffer);
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::toggleButtonClicked()
{
	if(toggleButton.getState())
	{
		Unicode::strncpy(textViewBuffer, (const char*)"button is pressed", strlen("button is pressed"));
		Screen1ViewBase::textView.invalidate();
	}
	else
	{
		Unicode::strncpy(textViewBuffer, (const char*)"button is released", strlen("button is released"));
		Screen1ViewBase::textView.invalidate();
	}
}
