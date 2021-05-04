#pragma once
#include "windows.h"
#include <thread>
#include <map>
#include <iostream>
class __declspec(dllexport) SimplePublisherSDK
{
public:
	SimplePublisherSDK();
	~SimplePublisherSDK();
	void setFrameRate(int rate);

	void setResolvtion(int width, int height);

	void setEncodeRate(int rate);

	//0：X264, 1:X265
	void setEncodeType(int type);

	void setHardwareEncode(bool flag);

	void setRtmpUrl(char* url);

	void startPush();

	void stopPush();

	void setIsPushing(bool isPushing);

	bool getIsPushing();

	char* getUrl();

	//0:RTSP, 1:RTMP
	void setPushType(int type);

	void setRtspPort(int port);
	void setRtspStream(char* stream);
	int getPushType();

	//音频开启设置
	void setEnableAudio(bool enableAudio);
	//0:扬声器（默认）1:麦克风
	void selectAudioSource(int audiosource);
	//采集设置
	//0:桌面采集  1：摄像头采集
	void setCaptureType(int type);
	//设置预览窗口
	void setPreviewWindow(HWND wind);
	//获得摄像头列表
	std::map<int, std::string> getCameraList();
	//选择操作摄像头
	void setCameraIndex(int index);
	//开启预览
	void startPreview();
private:
	void* m_publisher;
	std::thread m_autherthread;
};

