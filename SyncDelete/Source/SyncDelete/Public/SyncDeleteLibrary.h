// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SyncDeleteLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SYNCDELETE_API USyncDeleteLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/**
	 * 删除文件或文件夹。
	 * 当Path为文件路径时，删除文件。
	 * 当Path为文件夹路径时，删除文件夹。
	 * 注意：此为跨平台设计，是直接删除文件，不是移动到回收站，请谨慎使用此函数，后果自负。
	 * @param Path
	 * @return 如果找到文件并成功删除，返回false。否则返回true。
	 */
	UFUNCTION(BlueprintCallable, Category = "SyncDelete")
	static bool DeletePath(const FString& Path);

	/**
	 * 将文件删除。删除到回收站。目前仅支持Windows平台
	 * 注意，此函数不知道为什么，经常失败，尤其是打包后。请先使用DeletePath。
	 * @param Path
	 * @return 如果为0，则成功。如果为非0值，则失败。请参考windows平台的错误代码
	 */
	UFUNCTION(BlueprintCallable, Category = "SyncDelete")
	static int32 DeletePathToRecycleBin(const FString& Path);

	/**
	 * 获取项目根目录的的绝对路径
	 * 如SyncDelete项目，获取的话 磁盘符:/.../SyncDelete/
	 * @return 
	 */
	UFUNCTION(BlueprintCallable, Category = "SyncDelete")
	static FString GetProjectDirPath();
	
	/**
	 * 获取父路径
	 * @param Path 
	 * @return 
	 */
	UFUNCTION(BlueprintCallable, Category = "SyncDelete")
	static FString GetParentPath(const FString& Path);

	/**
	 * 获取项目路径的父路径
	 * 打包前。获取的是项目文件夹所在的文件夹。
	 * 打包后，获取的是exe程序所在的文件夹的父文件夹。如D:/aa/Windows/SyncDelete.exe,获取的就是D:/aa/
	 * 这样保证一致性。
	 * @return 
	 */
	UFUNCTION(BlueprintCallable, Category = "SyncDelete")
	static FString GetProjectDirParentPath();

	/**
	 * 按换行符分割字符串。分割成字符数组
	 * @param Input 
	 * @return 
	 */
	UFUNCTION(BlueprintCallable, Category = "SyncDelete")
	static TArray<FString> SplitFStringByNewline(const FString& Input);
};
