#include <iostream>
#include <string>

class Engine {

public:
	Engine(std::string title) {
		windowTitle = title;
		running = false;
	}

	void start();
	void stop();
	void update();
	void shutdown();

	bool is_running() const;

private:
	std::string windowTitle;
	
	bool running;
};
