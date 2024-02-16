modded class ModItemRegisterCallbacks
{
	
	
	override void RegisterTwoHanded( DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior )
	{
		super.RegisterTwoHanded( pType, pBehavior );
		
		//!Valentine
		pType.AddItemInHandsProfileIK("FSValentineHeart",						"dz/anims/workspaces/player/player_main/player_main_2h.asi",						pBehavior,					"dz/anims/anm/player/ik/two_handed/drysackbag.anm"); //TODO - placeholder, make a proper IK
	}

	
}
