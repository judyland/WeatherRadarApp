#pragma once

#include <memory>

#include "MMPLibrary.h"
#include "MMPDataElement.h"
#include "whrdrData.h"
#include "MMPReceiverMgr.h"

#include "CoordTranslations.h"

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

	private:
		std::vector<int>	m_aCloudsIds[num_of_clouds];
		void readClouds();
		using IMMPReceiver = MMP::IMMPReceiver;
		using MMPReceiverPtr = std::unique_ptr<IMMPReceiver, std::function<void(IMMPReceiver*)>>;
		
		
		
		std::unique_ptr<MMPReceiverMgr>		m_pMMPMgr;
		MMPReceiverPtr						m_pReceiver;
		MMPDataElement<blk_WXROutMessage>			m_cWheaterData;
	};

}