// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SLASHSOULS_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AItem();
	
	virtual void Tick(float DeltaTime) override;
	
protected:
	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure)
	float TransformedSin() const;

	UFUNCTION(BlueprintPure)
	float TransformedCos() const;

	template<typename T>
	T Avg(T First, T Second);
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Sine Parameters")
	float Amplitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Sine Parameters")
	float TimeConstant;
	
private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true), Category = "Item")
	float RunningTime;

};

template <typename T>
T AItem::Avg(T First, T Second)
{
	return (First + Second) / 2;
}
