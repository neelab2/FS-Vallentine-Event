class CfgPatches
{
	class fsvalentine
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Consumables"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class FSValentineHeart: Inventory_Base
	{
		scope=2;
		displayName="Valentins Herz";
		descriptionShort="I <3 Zombies Event item";
		model="\fsvalentine\heart.p3d";
		weight=10;
		itemSize[]={1,1};
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=1000;
		varQuantityDestroyOnMin=1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=15;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"fsvalentine\data\heart.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"fsvalentine\data\heart.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"fsvalentine\data\heart_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"fsvalentine\data\heart_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"fsvalentine\data\heart_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
};