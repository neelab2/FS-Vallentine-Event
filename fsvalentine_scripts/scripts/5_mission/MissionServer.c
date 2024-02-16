modded class MissionServer
{
	override void OnInit()
	{
		GetValentineEventConfig();
		super.OnInit();
		Print("[ValentineEvent] OnInit - Loaded config successfully.");
		Print("[ValentineEvent] active = " +GetValentineEventConfig().active);
	}
	
}