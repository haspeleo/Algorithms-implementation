#include <iostream>

using namespace std;

class button
{
enum button_status {off, on};
public:
button(button_status = off);
void switch_on();
void switch_off();
bool is_off() ; //c
bool is_on() ; //c
private:
button_status state;
};

button::button(button_status s) : state(s) {}

void button::switch_on()
{
if(state == on)
cout << "Please be patient \n"; //it's already pushed
else
state = on;
}

void button::switch_off()
{
state = off;
}

bool button::is_off() //c
{
return state == off;
}

bool button::is_on() //c
{
return state == on;
}

class Panel
{
public:
Panel(int n);
~Panel();
void press(int n);
void reset(int n);
bool is_off(int n) const;
bool is_on(int n) const;
bool is_valid(int n) const;
private:
button** panel;
int number;
Panel(const Panel&);
};

Panel::Panel(int n) : panel(0), number(n)
{
panel = new button*[number + 1];
for(int i = 0; i < number + 1; ++i)
panel[i] = new button;
}

Panel::~Panel()
{
for(int i = number; i >= 0; --i)
delete panel[i];
delete [] panel;
}

bool Panel::is_off(int n) const
{
return panel[n]->is_off();
}

bool Panel::is_on(int n) const
{
return panel[n]->is_on();
}

bool Panel::is_valid(int n) const
{
return n != 13;
}

void Panel::press(int n)
{
if(!is_valid(n))
cout << "No such floor!\n";
else
panel[n]->switch_on();
}

void Panel::reset(int n)
{
panel[n]->switch_off();
}

class elevator
{
public:
elevator(int = 1, int = 0);
~elevator();
void prompt();
private:
Panel buttons;
int current_floor;
const int top_floor;
bool button_active(int) const;
void press(int);
void close_doors();
bool floor_is_valid(int) const;
elevator(const elevator&);
};


elevator::elevator(int n, int w) : buttons(n), current_floor(1),
top_floor(n) {}

elevator::~elevator()
{
cout << "Elevator will self destruct\n";
}

void elevator::prompt()
{
cout << "Key in the floor you would like to visit, from 1 to " <<
top_floor << ", 0 to close doors, EOF to exit: ";
int floor;
while(!(cin >> floor).eof()) {
if(floor == 0) {
if(!button_active(1) && current_floor != 1)
press(1);
if(button_active(1))
close_doors();
}
else if(floor < 1 || floor top_floor)
cout << "---Floor " << floor << " is not valid\n";
else if(floor == current_floor)
cout << "---You have reached your floor now\n";
else
press(floor);
cout << "Next floor: ";
}
}

void elevator::press(int n)
{
buttons.press(n);
}

void elevator::close_doors()
{
cout << "Doors are closing\n";
cout << "\a\a\a\a\a";
// If a button is pushed on a floor higher than the current
// floor, then the elevator always moves up.
if(button_active(current_floor))
cout << "Elevator accending\n";
else
cout << "Elevator decending\n";
sleep(1);
// Keep looping as long as the floor buton is off
while(buttons.is_off(current_floor))
{
if(button_active(current_floor))
++current_floor;
else
--current_floor;
if(buttons.is_off(current_floor) &&
floor_is_valid(current_floor))
{
cout << "\tPassing floor " << current_floor << '\a' << '\n';
sleep(1);
}
}
cout << "\tNow on floor " << current_floor << "\a\a\a" << '\n';
sleep(1);
buttons.reset(current_floor);
cout << "Doors are open\n";
sleep(1);
}

bool elevator::button_active(int f) const
{
for(int i = f; i <= top_floor; ++i)
if(buttons.is_on(i))
return true;
return false;
}

bool elevator::floor_is_valid(int f) const
{
return buttons.is_valid(f);
}

int main()
{
const int top = 9;
elevator otis(top);
otis.prompt();
return 0;
}

