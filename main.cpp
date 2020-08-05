#include "CZlmApiWorker.h"

int main()
{
	std::string strYourSrcUrl;		//e.g:rtsp://127.0.0.1/live/
	std::string strYourPushUrl;		//e.g:rtmp://127.0.0.1/live/camera1
	CZLMWorker zlmworker;
	zlmworker.ZLM_SetPushUrl(strYourPushUrl);
	zlmworker.ZLM_MediaInit();
	zlmworker.ZLM_PlayerInit(strYourSrcUrl);

	while (true)
	{

	}
    return 0;
}

