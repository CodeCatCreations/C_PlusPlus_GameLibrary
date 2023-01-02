#include <SDL2/SDL.h>

#include <string>

#include "Button.h"
#include "Label.h"
#include "Session.h"
using namespace std;
using namespace cwing;

int value = 0;

class OkaKnapp : public Button {
   public:
    OkaKnapp(Label* lbl) : Button(100, 100, 200, 70, "Öka"), label(lbl){};
    void perform(Button* source) {
        value++;
        label->setText(to_string(value));
    }

   private:
    Label* label;
};

// test

int main(int argc, char** argv) {
    Session ses;
    Label* lbl = Label::getInstance(400, 100, 200, 70, "0");
    // Button* b = Button::getInstance(100, 100, 200, 70, "Knapp");
    // ses.add(b);

    ses.add(lbl);

    Button* b1 = new OkaKnapp(lbl);
    ses.add(b1);
    lbl->setText("Hoppsan");
    ses.run();

    return 0;
}