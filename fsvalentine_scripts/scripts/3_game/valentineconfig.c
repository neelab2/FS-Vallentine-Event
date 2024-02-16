class ValentineEventConfig
{
	// Set actual config version (doesn't save to json)
	private static const string CONFIG_VERSION = "1";

	// Config location
	private const static string valentineModFolder = "$profile:\\ValentineEvent\\";
	private const static string valentineConfigName = "ValentineEventConfig.json";

	// Config version 
	string ConfigVersion = "";

	// Main config data
	int active = 0;

	// Load config file or create default file if config doesn't exsit
	void Load() 
	{
		if (FileExist(valentineModFolder + valentineConfigName))
		{	// If config exists, load file
			JsonFileLoader<ValentineEventConfig>.JsonLoadFile(valentineModFolder + valentineConfigName, this);

			// If version mismatch, backup old version of json before replacing it
			if (ConfigVersion != CONFIG_VERSION)
			{
				JsonFileLoader<ValentineEventConfig>.JsonSaveFile(valentineModFolder + valentineConfigName + "_old", this);
			}
			else
			{
				// Config exists and version matches, stop here.
				return;
			}
		}

		// Config file does not exist, create default file
		ConfigVersion = CONFIG_VERSION;


		// Save config
		Save();
	}

	// Save config
	void Save() 
	{
		if(!FileExist(valentineModFolder))
		{ // If config folder doesn't exist, create it.
			MakeDirectory(valentineModFolder);
		}

		// Save JSON config
		JsonFileLoader<ValentineEventConfig>.JsonSaveFile(valentineModFolder + valentineConfigName, this);
	}


};



// Save config data
ref ValentineEventConfig m_ValentineEventConfig;

// Helper function to return Config data storage object
static ValentineEventConfig GetValentineEventConfig()
{
	if(!m_ValentineEventConfig && GetGame().IsServer())
	{
		Print("[ValentineEventConfig] Init");
		m_ValentineEventConfig = new ValentineEventConfig;
		m_ValentineEventConfig.Load();
	}

	return m_ValentineEventConfig;
};