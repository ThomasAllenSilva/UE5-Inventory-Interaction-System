// Thomas Learning Project

#include "UI/Components/WidgetCreator/WidgetCreatorComponent.h"
#include "Blueprint/UserWidget.h"
#include "UI/Base/ContextualUserWidget.h"
#include "Data/DataAsset_WidgetDefinitions.h"
#include "Data/DataAsset_WidgetComponentConfigs.h"
#include "Components/WidgetComponent.h"
#include "UI/Subsystem/CommonHUDSubsystem.h"
#include "UI/Widgets/HUDLayoutUserWidget.h"

UWidgetCreatorComponent::UWidgetCreatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	PrimaryComponentTick.bStartWithTickEnabled = false;

	PrimaryComponentTick.bAllowTickOnDedicatedServer = false;
}

void UWidgetCreatorComponent::CreateDefaultWidgets()
{
	for (const UDataAsset_WidgetDefinitions* WidgetDefinition : WidgetDefinitions)
	{
		if (WidgetDefinition == nullptr)
		{
			continue;
		}

		for (const TPair< FGameplayTag, FWidgetSetupSettings>& WidgetSetupSettings : WidgetDefinition->GetWidgetsSettingsMap())
		{
			if (WidgetSetupSettings.Value.Widget == nullptr)
			{
				return;
			}

			if (WidgetSetupSettings.Value.ShouldCreateWithStartupWidgets)
			{
				ConstructWidgetUsingSettings(WidgetSetupSettings.Value);
			}
		}
	}
}

UUserWidget* UWidgetCreatorComponent::ConstructWidgetUsingSettings(const FWidgetSetupSettings& WidgetSetupSettings)
{
	UWorld* World = GetWorld();

	ULocalPlayer* LocalPlayer = World->GetFirstLocalPlayerFromController();

	APlayerController* PlayerController = LocalPlayer->GetPlayerController(World);

	UUserWidget* WidgetInstance = CreateWidget<UUserWidget>(PlayerController, WidgetSetupSettings.Widget);

	check(WidgetInstance);

	AActor* OwningActor = GetOwner();

	WidgetInstance->SetVisibility(WidgetSetupSettings.DefaultVisibility);

	if (WidgetSetupSettings.WidgetCreationType == EWidgetCreationType::AddToViewport)
	{
		WidgetInstance->AddToViewport();

		UCommonHUDSubsystem* CommonHUDSubsystem = ULocalPlayer::GetSubsystem<UCommonHUDSubsystem>(LocalPlayer);

		FWidgetContentInfo WidgetContentInfo(WidgetSetupSettings.WidgetTag, WidgetInstance);

		CommonHUDSubsystem->PushToOverlayLayer(WidgetSetupSettings.OverlayLayerTag, WidgetContentInfo);
	}

	else
	{
		UDataAsset_WidgetComponentConfigs* ComponentSettings = WidgetSetupSettings.WidgetComponentSettings;

		UWidgetComponent* WidgetComponent = NewObject<UWidgetComponent>(OwningActor);

		WidgetComponent->SetupAttachment(OwningActor->GetRootComponent());

		WidgetComponent->RegisterComponent();

		WidgetComponent->SetWidget(WidgetInstance);

		WidgetComponent->SetWidgetSpace(ComponentSettings->GetWidgetSpace());

		WidgetComponent->SetTickMode(ComponentSettings->GetTickMode());

		WidgetComponent->SetDrawSize(ComponentSettings->GetDrawSize());

		WidgetComponent->SetDrawAtDesiredSize(ComponentSettings->bDrawAtDesiredSize);

		WidgetComponent->SetPivot(ComponentSettings->GetPivot());

		WidgetComponent->SetRelativeLocation(ComponentSettings->GetRelativeLocation());

		WidgetComponent->SetRelativeRotation(ComponentSettings->GetRelativeRotation());

		WidgetComponent->SetCollisionEnabled(ComponentSettings->CollisionEnabled);

		WidgetComponent->SetGenerateOverlapEvents(ComponentSettings->bGenerateOverlapEvents);

		WidgetComponent->SetCollisionResponseToAllChannels(ComponentSettings->CollisionResponse);
	}

	if (UContextualUserWidget* ContextObject = Cast<UContextualUserWidget>(WidgetInstance))
	{
		ContextObject->SetOwningActor(OwningActor);
	}

	CachedWidgetsMap.Add(WidgetSetupSettings.WidgetTag, WidgetInstance);

	return WidgetInstance;
}

UUserWidget* UWidgetCreatorComponent::GetCachedWidgetByTagChecked(const FGameplayTag WidgetTag) const
{
	checkf(CachedWidgetsMap.Contains(WidgetTag), TEXT("Could not find cached widget with the tag: %s"), *WidgetTag.ToString());

	return CachedWidgetsMap[WidgetTag];
}
