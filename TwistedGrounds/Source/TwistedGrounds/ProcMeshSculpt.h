// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "ProcMeshSculpt.generated.h"

UCLASS()
class TWISTEDGROUNDS_API AProcMeshSculpt : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProcMeshSculpt();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
		UProceduralMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere)
		int32 Width;

	UPROPERTY(EditAnywhere)
		int32 Height;

	UPROPERTY(EditAnywhere)
		float GridSize;

	UPROPERTY(BlueprintReadWrite)
		FHitResult HitResult;

	TArray<FVector> Vertices;

	TArray<int32> Triangles;

	TArray<FVector2D> UVCoords;

	float PerlinOffset;

	UPROPERTY(EditAnywhere)
		float PerlinScale;

	UPROPERTY(EditAnywhere)
		float PerlinRoughness;

	UFUNCTION(BlueprintCallable)
		void GenerateMap();

	UPROPERTY(EditAnywhere)
		bool bRegenerateMap;

	void ClearMap();

	virtual bool ShouldTickIfViewportsOnly() const override;

	TArray<FVector> Normals;

	TArray<FProcMeshTangent> Tangents;

	UFUNCTION(BlueprintCallable)
	void Sculpt();

	TArray<int32> AffectedVertNormals;
};
