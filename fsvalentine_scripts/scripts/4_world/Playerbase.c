modded class PlayerBase
{
	bool m_isvalentineactive;
	bool m_valentineconfigreceived = false;
	
	
	// Called when the player is loaded
	override void OnPlayerLoaded()
	{
		super.OnPlayerLoaded();

		if (GetGame().IsDedicatedServer())
		{
			SyncValentineConfig();
			SendValentineDataToClient();
		}
	}
	
	// (Server-side) Sets the server-side settings that the player client must sync
	void SyncValentineConfig()
	{
		// Bools
		m_isvalentineactive = GetValentineEventConfig().active;
		
	}
	
	// (Server-side) Sends an RPC containing all of the server-side sleep config settings that the client needs to be aware of
	void SendValentineDataToClient()
	{
		if (!IsPlayerDisconnected())
		{
			GetRPCManager().SendRPC("FSV_RPC", "RPC_SendValentineDataToClient", new Param1< bool >(m_isvalentineactive), true, this.GetIdentity());
		}
	}
}