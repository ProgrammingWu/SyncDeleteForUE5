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
