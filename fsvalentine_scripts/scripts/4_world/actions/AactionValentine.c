class ActionValentine : ActionSingleUseBase
{
	protected Particle m_ParticleValentine;

	void ActionValentine()
	{
		m_Text 				= "Love";
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem 	= new CCINone();
		m_ConditionTarget 	= new CCTNone();
	}
	
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if ( item && item.IsInherited(FSValentineHeart) ) 
		{
			return true;
		}
		return false;
	}
	
	override void OnExecuteServer(ActionData action_data)
	{
		
		if (!GetGame().IsMultiplayer()) 
			PhysicalValentineEffect(action_data);
		
		
	}
	
	override void OnExecuteClient(ActionData action_data)
	{
		super.OnExecuteClient(action_data);

		PhysicalValentineEffect(action_data);
	}
	
	void PhysicalValentineEffect( ActionData action_data )
	{
		ItemBase targetItem = ItemBase.Cast(action_data.m_Player.GetItemInHands());
		if (targetItem.IsInherited(FSValentineHeart))
		{
			if (m_ParticleValentine)
				m_ParticleValentine.Stop();
		
			m_ParticleValentine =ParticleManager.GetInstance().PlayInWorld(ParticleList.VALENTINEHEART, targetItem.GetPosition());
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(StopValentineEffect, 2000, false);
		}
		
	}
	
	void StopValentineEffect()
	{
		if (m_ParticleValentine)
				m_ParticleValentine.Stop();
	}
}
