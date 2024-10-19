// Fill out your copyright notice in the Description page of Project Settings.


#include "SyncDeleteLibrary.h"
#include <filesystem>
#include "SyncDeleWindowsTools.h"

bool USyncDeleteLibrary::DeletePath(const FString& Path)
{
	//FString FullFileName = FPaths::GetPath(Path);
	IFileManager& FileManager = IFileManager::Get();
	if(FileManager.FileExists(*Path))
	{
		return FileManager.Delete(*Path,true,true,false);
		
	}
	if(FileManager.DirectoryExists(*Path))
	{
		return FileManager.DeleteDirectory(*Path,true,true);
	}
	UE_LOG(LogClass, Error, TEXT("USyncDeleteLibrary::DeleteFile：%s删除失败。没有找到（既不是文件，也不是路径）"), *Path);
	return false;
}


int32 USyncDeleteLibrary::DeletePathToRecycleBin(const FString& Path)
{
#if PLATFORM_WINDOWS
	return SyncDeleWindowsTools::MoveToRecycleBin(Path);
#endif
	return 0;
	
}


FString USyncDeleteLibrary::GetProjectDirPath()
{
	return FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());
}



FString USyncDeleteLibrary::GetParentPath(const FString& Path)
{
	std::string StdStr(TCHAR_TO_UTF8(*Path));
	std::filesystem::path FilePath(StdStr);
	if (FilePath.has_relative_path() && FilePath.filename().string().empty()) {
		FilePath = FilePath.parent_path();
	}
	FString TempPath = UTF8_TO_TCHAR(FilePath.parent_path().string().c_str());
	
	return TempPath.Append(TEXT("/"));
}

FString USyncDeleteLibrary::GetProjectDirParentPath()
{

#if WITH_EDITOR
	return GetParentPath(GetProjectDirPath());
#else
	return GetParentPath(GetParentPath(GetProjectDirPath()));
#endif
}

TArray<FString> USyncDeleteLibrary::SplitFStringByNewline(const FString& Input)
{
	TArray<FString> Result;
	TArray<FString> Temp;
	Input.ParseIntoArray(Temp, TEXT("\n"), true);
	for (auto& Str : Temp)
	{
		//Str.TrimStartAndEnd();
		Str.TrimStartAndEndInline();
		if (!Str.Equals(""))
		{
			Result.Add(Str);
		}
	}
	return MoveTemp(Result);
}


