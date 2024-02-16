class CfgPatches
{
	class fsvalentine_scripts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"fsvalentine"
		};
	};
};
class CfgMods
{
	class fsvalentine_scripts
	{
		dir="fsvalentine_scripts";
		name="fsvalentine_scripts";
		picture="";
		action="";
		extra=0;
		hideName=1;
		hidePicture=1;
		credits="";
		version="0";
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"fsvalentine_scripts/scripts/3_game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"fsvalentine_scripts/scripts/4_world"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"fsvalentine_scripts/scripts/5_mission"
				};
			};
		};
	};
};