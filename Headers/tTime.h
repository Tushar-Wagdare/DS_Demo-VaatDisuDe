#pragma once

#include<winnt.h>

double time;
double fps = 0.0;
double deltaTime;
float rotAntenaWeight = -10.0f;


typedef struct Timer
{
	LARGE_INTEGER firstTick;
	LARGE_INTEGER lastTick;
	LARGE_INTEGER frequency;

	double elapsedTime;
	int frameCount;
	int etCounter;
	double splitTime;
	
	char titleBuffer[256];

	Timer() : elapsedTime(0.0), frameCount(0), splitTime(0.5) {}

	void initializeTimer()
	{
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&firstTick);
	}

	void startTimer()
	{
		QueryPerformanceCounter(&lastTick);
	}

	double getElapsedTime()
	{
		elapsedTime = (double)(lastTick.QuadPart - firstTick.QuadPart) / (double)(frequency.QuadPart);
		if(bProgressBar)
		time = elapsedTime + etCounter * splitTime;

		return(elapsedTime * 1000000.0);
	}

	void evaluateTimer()
	{
		if (elapsedTime >= splitTime)
		{
			fps = frameCount / elapsedTime;
			deltaTime = 1.0 / fps;
			frameCount = 0;

			if (bProgressBar)
			etCounter++;

			QueryPerformanceCounter(&firstTick);
		}
	}

	void displayTime(HWND targetWindowHandle)
	{
		sprintf(titleBuffer, "FPS:%u||splitTime:%.2lf||TIME:%.2lf,||CR:%.2f,||X:%.2f,Y:%.2f,Z:%.2f,R:%.2f||FOVY:%.2f", (unsigned int)fps, splitTime, time, cloudRot,xxx,yyy,zzz,rrr,fovy);
		SetWindowText(targetWindowHandle, titleBuffer);
	}

}Timer;

