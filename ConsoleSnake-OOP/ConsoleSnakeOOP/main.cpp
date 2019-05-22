#include "Application.h"

int main()
{
	Application demo(40, 15);
	
	while (!demo.isDone())
	{
		demo.handleInput();
		demo.update();
		demo.Render();
	}

	return 0;
}