#include "Session.h"
#include "Label.h"
#include <SDL2/SDL.h>
#include "Button.h"
#include <string>
using namespace std;
using namespace cwing;

int value = 0;

class OkaKnapp : public Button {
    public:
        OkaKnapp(Label *lbl):Button(100, 100, 200, 70, "Öka"), label(lbl) {};
        void perform(Button* source) {
            value++;
            label->setText(to_string(value));
        }
    private:
        Label* label;
};

//test

int main(int argc, char** argv){

/*
    Session ses;
    Label* lbl = Label::getInstance(400, 100, 200, 70, "0");

    ses.add(lbl);

    Button* b = new OkaKnapp(lbl);
    ses.add(b);
    lbl->setText("Hoppsan");
    ses.run();

    return 0;

    */ 
    Session ses;
    Button* b = Button::getInstance(100, 100, 200, 70, "Hoppsan");
    ses.add(b);
    ses.run();
    return 0;


}