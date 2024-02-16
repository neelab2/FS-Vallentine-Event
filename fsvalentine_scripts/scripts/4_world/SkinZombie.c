modded class ActionSkinning extends ActionContinuousBase
{
	
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Object targetObject = target.GetObject();
		
		if (targetObject.CanBeSkinned() && !targetObject.IsAlive())
		{
			EntityAI target_EAI;
			if (Class.CastTo(target_EAI, targetObject) && target_EAI.CanBeSkinnedWith(item))
				return true;
		}
		

			if (targetObject.IsInherited(ZombieBase) && !targetObject.IsAlive() && player.m_isvalentineactive)
			{
				EntityAI target_EAI_Z;
				if (Class.CastTo(target_EAI_Z, targetObject) && target_EAI_Z.CanBeSkinnedWith(item))
					return true;
			}
		
		
		return false;
	}
	
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);

        if (action_data.m_Target)
        {
            EntityAI body;
            Class.CastTo(body, action_data.m_Target.GetObject());

            if (body.IsInherited(ZombieBase))
            {
                ItemBase added_item;

					body.SetAsSkinned();
                    vector pos_rnd = body.GetPosition() + Vector(Math.RandomFloat01() - 0.5, 0, Math.RandomFloat01() - 0.5);
                    pos_rnd[1] = GetGame().SurfaceY(pos_rnd[0], pos_rnd[2]);
                    Class.CastTo(added_item, GetGame().CreateObject("FSValentineHeart", pos_rnd, false));
                    added_item.PlaceOnSurface();
            
            }
        }
    }
}