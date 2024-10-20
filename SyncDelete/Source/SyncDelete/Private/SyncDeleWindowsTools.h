/*
Copyright(c) 2024 裴鸿喆. All Rights Reserved.
版权所有(c) 2024 裴鸿喆，保留所有权利。

B站：https://space.bilibili.com/381317561
寿光市鸿喆电脑科技服务中心
*/

#pragma once


class SyncDeleWindowsTools
{

public:
	/**
	 * Windows平台，把文件删除到回收站。
	 * @param InPath - 路径
	 * @return 如果返回值为0，那么代表成功。非0则失败
	 */
	static int32 MoveToRecycleBin(FString InPath);

};
