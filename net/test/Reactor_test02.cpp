#include "EventLoop.h"

#include <stdio.h>

using namespace xnet;
using namespace xnet::net;

EventLoop* g_loop;

void threadFunc()
{
	g_loop->loop();
}

int main(void)
{
	EventLoop loop;
	g_loop = &loop;
	Thread t(threadFunc);
	t.start();
	t.join();
	return 0;
}

