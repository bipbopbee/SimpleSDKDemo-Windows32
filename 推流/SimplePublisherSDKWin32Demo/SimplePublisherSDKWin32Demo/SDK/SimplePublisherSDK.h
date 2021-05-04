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

	//0��X264, 1:X265
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

	//��Ƶ��������
	void setEnableAudio(bool enableAudio);
	//0:��������Ĭ�ϣ�1:��˷�
	void selectAudioSource(int audiosource);
	//�ɼ�����
	//0:����ɼ�  1������ͷ�ɼ�
	void setCaptureType(int type);
	//����Ԥ������
	void setPreviewWindow(HWND wind);
	//�������ͷ�б�
	std::map<int, std::string> getCameraList();
	//ѡ���������ͷ
	void setCameraIndex(int index);
	//����Ԥ��
	void startPreview();
private:
	void* m_publisher;
	std::thread m_autherthread;
};

