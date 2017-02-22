#include"domain.h"
#include<stdio.h>
#include "repo.h"
#include "controller.h"
#include "UI.h"
#include<windows.h>
#include<assert.h>
#include"tests.h"


int main() {
	//Title Genre Trailer Year Likes
	UI ui;
	tests testing;
	ui.mainLoop();
	return 0;
}