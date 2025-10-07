#include "Canvas.hpp"
#include <cstdlib>
#include <iostream>
#include <unistd.h>

int main() {
	Canvas c = Canvas("ddddddddsssssssssxdddddddxddxddddxdddxddxddddddxddddddxddxdddd", 60, 20);
	
	c.simulate(1000000);
}
