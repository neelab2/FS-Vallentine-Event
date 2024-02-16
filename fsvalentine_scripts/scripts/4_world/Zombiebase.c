modded class ZombieBase extends DayZInfected
{
	bool m_isvalentineactive;
	
	override void EOnInit(IEntity other, int extra)
	{
		
		super.EOnInit(other, extra);
		
		if (GetGame().IsDedicatedServer())
		{
			SyncValentineConfig();
		}
	}
	
	void SyncValentineConfig()
	{
		// Bools
		m_isvalentineactive = GetValentineEventConfig().active;
		
	}
	
	override bool HandleDeath(int pCurrentCommandID)
	{
		if ( !IsAlive() || m_FinisherInProgress )
		{
			StartCommand_Death(m_DeathType, m_DamageHitDirection);
			m_MovementSpeed = -1;
			m_MindState = -1;
			if (m_isvalentineactive) 
			{
				int chance = Math.RandomInt(0, 4);
				if (chance == 1) this.GetInventory().CreateInInventory("FSValentineHeart");
			}
			SetSynchDirty();
			return true;
		}

		return false;
	}
}