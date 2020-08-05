#ifndef _CZLMAPIWORKER_H_
#define _CZLMAPIWORKER_H_

#include "stdafx.h"
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include "mk_media.h"
#include "mk_player.h"
#include "mk_pusher.h"

#pragma comment(lib, "jsoncpp.lib")
#pragma comment(lib, "flv.lib")
#pragma comment(lib, "mov.lib")
#pragma comment(lib, "mpeg.lib")
#pragma comment(lib, "rtp.lib")
#pragma comment(lib, "mk_api.lib")
#pragma comment(lib, "zlmediakit.lib")
#pragma comment(lib, "zltoolkit.lib")

class CZLMWorker
{
public:
	CZLMWorker();
	~CZLMWorker();

	//初始化播放器,拉流使用
	void ZLM_PlayerInit(std::string strSrcUrl);
	//初始化MediaSource,推流使用
	void ZLM_MediaInit();
	mk_media ZLM_GetMediaHandle();
	//初始化推流器
	void ZLM_PusherInit();
	void ZLM_PusherStart(std::string strPushUrl);
	void ZLM_SetPushUrl(std::string strPushUrl);
	std::string  ZLM_GetPushUrl();
private:
	mk_player _mk_PlayerHandle;
	mk_media  _mk_MediaHandle;
	mk_pusher _mk_PusherHandle;

	std::string _strPushUrl;
	FILE* _fp = fopen("zlm.h264", "wb+");
};
#endif // !_CZLMAPIWORKER_H_

