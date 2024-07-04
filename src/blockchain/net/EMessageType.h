#ifndef __E_MESSAGE_TYPE_INCLUDED__
#define __E_MESSAGE_TYPE_INCLUDED__

namespace
{
	namespace
	{
		enum EMessageType
		{
		  EMT_NULL,
		  EMT_PING,
		  EMT_ACT,
		  EMT_ERR,
		  EMT_NODE_REGISTER,
		  EMT_NODE_REGISTER_PORT,
		  EMT_INIT_CHAIN,
		  EMT_WRITE_BLOCK,
		  EMT_CHAIN_NEW,
		  EMT_CHAIN_INFO,
		  EMT_COUNT
		};
	}
}

#endif
