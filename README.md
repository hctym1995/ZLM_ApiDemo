# ZLM_ApiDemo

+ 基于流媒体服务器ZLMediakit的c-api实现的拉流推流最简Demo(vs2019 vs2015)
+ 注:如果需要linux版,所有的demo代码基本不用修改,只需要下载ZLM的源码编译，按照linux下C++的开发流程链接并调用对应的api库
+ __记得阅读ZLM的wiki以及api头文件的代码注释__

# 库文件(lib & dll)

(静态库文件体积比较大,制作了单独的网盘链接)

+ 库文件通过编译zlmdiakit生成,编译时使用的代码为2020-8-5拉取的最新代码
+ 其中inclue是头文件,lib是静态库文件,dll是动态库文件(库文件在vs release x64环境下生成)
+ 链接：https://pan.baidu.com/s/1NX2xlddh2O0WF2jS3mWKTA   提取码：anvq
+ __如果后续zlm有更新,你可能需要自己用新的代码编译新的库__

# 关于ZLMediakit

一个优秀而强大的流媒体服务器,致敬作者,致敬开源

<https://github.com/xia-chu/ZLMediaKit>

