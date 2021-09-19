// Copyright 2016 Andreas Schoch (aka Minaosis). All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "TerrainEditorStuff.h"
#include "TerrainSection.generated.h"

class URuntimeMeshComponentStatic;
class UProceduralMeshComponent;
class ATerrainGenerator;

UCLASS()
class TWISTEDGROUNDS_API ATerrainSection : public AActor
{
	GENERATED_BODY()

public:
	ATerrainSection();
	void InitializeOnSpawn(int32 SectionIndex, ATerrainGenerator* Terrain);
	void CreateSection();
	void UpdateSection();

	FVector SectionCoordinates;
	FVector CenterLocation;

	UPROPERTY(EditAnywhere, Category = "ProceduralMeshGeneration")
		bool bUseRuntimeMeshComponent = true;

	UFUNCTION(BlueprintCallable, Category = "ProceduralMeshGeneration")
		void RequestSculpting(const FSculptSettings& Settings, const FSculptInputInfo& InputInfo);

private:
	virtual void BeginPlay() override;
	void SetVisibility();

	UPROPERTY(VisibleAnywhere, Category = "Components")
		USceneComponent* SceneRoot = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		URuntimeMeshComponentStatic* RuntimeMeshComponent = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UProceduralMeshComponent* ProceduralMeshComponent = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		URuntimeMeshComponentStatic* RuntimeMeshComponentLOD1 = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UProceduralMeshComponent* ProceduralMeshComponentLOD1 = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		URuntimeMeshComponentStatic* RuntimeMeshComponentLOD2 = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UProceduralMeshComponent* ProceduralMeshComponentLOD2 = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		URuntimeMeshComponentStatic* RuntimeMeshComponentLOD3 = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UProceduralMeshComponent* ProceduralMeshComponentLOD3 = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		URuntimeMeshComponentStatic* RuntimeMeshComponentLOD4 = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UProceduralMeshComponent* ProceduralMeshComponentLOD4 = nullptr;


	TArray<UProceduralMeshComponent*> ProceduralMeshLODs;
	TArray<URuntimeMeshComponentStatic*> RuntimeMeshLODs;


	APlayerController* PlayerControllerReference = nullptr;

	int32 SectionIndexLocal = 0;

	TArray<int32> IndexBufferLocal;

	FTimerHandle VisibilityTimerHandle;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sculpting")
		ATerrainGenerator* OwningTerrain = nullptr;
};
