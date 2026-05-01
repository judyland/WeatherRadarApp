#pragma once

#include <memory>

#include "MMPLibrary.h"
#include "MMPDataElement.h"
#include "whrdrData.h"
#include "MMPReceiverMgr.h"

//#include "CoordTranslations.h"

#include "qryMultiModelsIsector.h"


namespace whrdr
{
	class Channel;

	class Comm
	{
	public:
		Comm();
		~Comm();
		void update(Channel* pChan);
		void initMMP();

		enum Role
		{
			PILOT,
			COPILOT
		};
	private:

		Role m_currRole;
		std::vector<int>	m_aCloudsIds[num_of_clouds];
		void readClouds(MMPDataElement<blk_WXROutPilotMessage>& data);
		using IMMPReceiver = MMP::IMMPReceiver;
		using MMPReceiverPtr = std::unique_ptr<IMMPReceiver, std::function<void(IMMPReceiver*)>>;
		
		
		
		std::unique_ptr<MMPReceiverMgr>		m_pMMPMgr;
		MMPReceiverPtr						m_pReceiver;
		MMPDataElement<blk_WXROutPilotMessage>			m_cWheaterData;
		//MMPDataElement<blk_WXROutPilotMessage>		m_cWheaterCopilotData;
		static qryIsectDB::ModelPtr					m_pModel;
		static qryIsectDB::UniquePtr				m_pDB;
	};

}