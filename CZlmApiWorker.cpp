#include "CZlmApiWorker.h"

//所有的api介绍都可以在对应头文件找到

void API_CALL PushResultCB(void *user_data, int err_code, const char *err_msg)
{
	printf("err_code:%d\n", err_code);
	printf("err_msg:%s\n", err_msg);
}

void API_CALL MediasourceRegistCB(void *user_data, mk_media_source sender, int regist)
{
	printf("mk_media_source:%x\n", sender);
	printf("regist type:%x\n", regist);

	if (regist == 1)
	{
		CZLMWorker* ptr = (CZLMWorker*)user_data;
		ptr->ZLM_PusherInit();
		ptr->ZLM_PusherStart(ptr->ZLM_GetPushUrl().c_str());
	}
	
}

void API_CALL StreamDataCB(void *user_data, int track_type, int codec_id, void *data, int len, uint32_t dts, uint32_t pts)
{
	//忽略音频
	if (track_type != 0)
	{
		return;
	}

	CZLMWorker* ptr = (CZLMWorker*)user_data;
	mk_media pMedia = ptr->ZLM_GetMediaHandle();
	mk_media_input_h264(pMedia, data, len, dts, pts);
	return;
}

CZLMWorker::CZLMWorker()
{
}

CZLMWorker::~CZLMWorker()
{
}

void CZLMWorker::ZLM_PlayerInit(std::string strSrcUrl)
{
	_mk_PlayerHandle = mk_player_create();
	mk_player_set_on_data(_mk_PlayerHandle, StreamDataCB, this);
	mk_player_play(_mk_PlayerHandle, strSrcUrl.c_str());
}

void CZLMWorker::ZLM_MediaInit()
{
	_mk_MediaHandle = mk_media_create( \
		"__defaultVhost__", "live", "camera1", \
		0, 0, 1, 0, 0
	);
	mk_media_init_video(_mk_MediaHandle, 0, 1920, 1080, 25);
	mk_media_set_on_regist(_mk_MediaHandle, MediasourceRegistCB, this);
	mk_media_init_complete(_mk_MediaHandle);
}

mk_media CZLMWorker::ZLM_GetMediaHandle()
{
	return _mk_MediaHandle;
}

void CZLMWorker::ZLM_PusherInit()
{
	_mk_PusherHandle = mk_pusher_create("rtmp", "__defaultVhost__", "live", "camera1");
	mk_pusher_set_on_result(_mk_PusherHandle, PushResultCB, this);
}

void CZLMWorker::ZLM_PusherStart(std::string strPushUrl)
{
	mk_pusher_publish(_mk_PusherHandle, strPushUrl.c_str());
}

void CZLMWorker::ZLM_SetPushUrl(std::string strPushUrl)
{
	_strPushUrl = strPushUrl;
}

std::string  CZLMWorker::ZLM_GetPushUrl()
{
	return _strPushUrl;
}