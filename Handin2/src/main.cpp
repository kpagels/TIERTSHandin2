#include "systemx/ui/consoledisplay.hpp"
#include "systemx/app/app.hpp"
#include "systemx/app/iapp.hpp"


using namespace systemx;

int main(void) {
	ui::ConsoleDisplay display;
	app::App app(&display);	
	app::IApp* app_ptr = &app;

	
	app_ptr->start();

	char a;
	std::cin >> a;
	while (a != 'q') {
		if (a == 's')
			app.Simulate();
		if (a == 'r')
			app.RunRealTime();
		if (a == 'c')
			app.chMode();
		std::cin >> a;
	}
	
   return 0;
}