#include "Canvas.hpp"
#include <cstdlib>
#include <iostream>
#include <unistd.h>

int main() {
	Canvas c = Canvas("sssddddxssxwxd", 10, 10);
	
	c.simulate(200);
}
