#pragma once
#include "windows.h"
class __declspec(dllexport) SimplePlayerSDK
{
public:
	void setPlayUrl(char* url);
	void setPlayWnd(HWND wnd);
	void setIsPlaying(bool playing);
	char* getPlayUrl();
	HWND getPlayWnd();
	bool getIsPlaying();
	void play();
	void stop();
	SimplePlayerSDK();
	~SimplePlayerSDK();
private:
	void* m_player;
};

