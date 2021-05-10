#pragma once
#include "windows.h"
#include <thread>
class __declspec(dllexport) SimplePlayerSDK
{
public:
	void setRotate(int degree);
	void setPlayUrl(char* url);
	void setPlayWnd(HWND wnd);
	void setIsPlaying(bool playing);
	void setBufferSize(int buffersize);
	char* getPlayUrl();
	HWND getPlayWnd();
	bool getIsPlaying();
	void play();
	void stop();
	//Â¼ÖÆMP4
	void setRecordPath(char* path);
	void setEnableRecord(bool enableRecord);
	void startRecord();
	void stopRecord();
	SimplePlayerSDK();
	~SimplePlayerSDK();
private:
	void* m_player;
	std::thread m_authorthread;
};

