#include <gui/screen1_screen/Screen1View.hpp>
#include "gpio.h"
Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::toggleButtonClicked()
{
	if(toggleButton.getState())			HAL_GPIO_WritePin(GPIOG, LD4_Pin, GPIO_PIN_SET);
	else								HAL_GPIO_WritePin(GPIOG, LD4_Pin, GPIO_PIN_RESET);
}
