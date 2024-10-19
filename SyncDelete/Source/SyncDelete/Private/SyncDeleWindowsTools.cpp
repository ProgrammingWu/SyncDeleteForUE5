#include "SyncDeleWindowsTools.h"

#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#include <ShlObj.h>
#include <Shellapi.h>
#include "Windows/HideWindowsPlatformTypes.h"
#endif

int32 SyncDeleWindowsTools::MoveToRecycleBin(FString InPath)
{
#if PLATFORM_WINDOWS
		//InPath.ReplaceInline(TEXT("/"), TEXT("\\"));
		UE_LOG(LogClass, Log, TEXT("SyncDeleWindowsTools::MoveToRecycleBin路径为：%s"), *InPath);
		const TCHAR* Path = *InPath;
		// 使用 SHFILEOPSTRUCT 进行文件操作
		SHFILEOPSTRUCT FileOp;
		ZeroMemory(&FileOp, sizeof(FileOp));
		FileOp.wFunc = FO_DELETE;  // 指定操作为删除
		FileOp.pFrom = Path;       // 源文件路径
		FileOp.fFlags = FOF_ALLOWUNDO | FOF_NOCONFIRMATION|FOF_SILENT; // 允许撤销（即放入回收站）并且不显示确认对话框
		return SHFileOperation(&FileOp); //执行操作
#endif
}