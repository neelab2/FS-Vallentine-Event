modded class MissionBase extends MissionBaseWorld
{
	void MissionBase()
	{
		if (!GetGame().IsDedicatedServer()) // Register server->client RPCs
		{
			GetRPCManager().AddRPC("FSV_RPC", "RPC_SendValentineDataToClient", this, SingeplayerExecutionType.Client);
		}
	}

	// This is used by the server to send important server-side config data to the client
	void RPC_SendValentineDataToClient(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Client && !GetGame().IsDedicatedServer())
		{
			Param1< bool > data;
			if (!ctx.Read(data)) 
			{
				Print("[Valentine] Error sync'ing server-side data to client in RPC_SendValentineDataToClient");
				return;
			}

			PlayerBase player;
			PlayerBase.CastTo(player, GetGame().GetPlayer());
			if (player)
			{
				// Bools
				player.m_isvalentineactive = data.param1;
				
				player.m_valentineconfigreceived = true;

			}
		}
	}
}