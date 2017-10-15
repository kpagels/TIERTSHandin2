#include "systemx/ui/consoledisplay.hpp"
#include "systemx/app/app.hpp"
#include "systemx/app/iapp.hpp"


using namespace systemx;

class UIThread : public os::thread {
public:
	UIThread(app::App* app) : app(app) {}

	void run(void) {
		char a;
		std::cin >> a;
		while (a != 'q') {
			if (a == 's')
				app->Simulate();
			if (a == 'r')
				app->RunRealTime();
			if (a == 'c')
				app->chMode();
			if (a == 'e')
				app->Restart();
			if (a == 'a')
				app->Start();
			if (a == 't')
				app->systemSelftest_ = true;
			std::cin >> a;
		}
	}

private:
	app::App* app;
};

int main(void) {
	ui::ConsoleDisplay display;
	app::App app(&display);	
	app::IApp* app_ptr = &app;
	UIThread ui(&app);

	ui.start();
	
	app_ptr->start();

   return 0;
}