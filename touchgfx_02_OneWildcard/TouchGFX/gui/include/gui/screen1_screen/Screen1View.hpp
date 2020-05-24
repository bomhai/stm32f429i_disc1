#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void toggleButtonClicked();

protected:
    static const uint16_t TEXTVIEW_BUFF_SIZE = 50;
    Unicode::UnicodeChar textViewBuffer[TEXTVIEW_BUFF_SIZE];


};

#endif // SCREEN1VIEW_HPP
