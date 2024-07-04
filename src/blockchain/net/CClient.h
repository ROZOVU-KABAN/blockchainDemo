#ifndef __C_CLIENT_INCLUDED__
#define __C_CLIENT_INCLUDED__

#include "INet.h"
#include "../CLog.h"
#include "../CBlock.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdint.h>
#include <string>
#include <pthread.h>
#include <queue>


namespace blockchain
{
  namespace net
  {
     class CClient : protected INet
     {
	private:
 	void* mChain;
	uint32_t mPort;
	bool mRunning;
	bool mStoped;
	struct sockaddr_in mAddr;
	pthread_t mWorkerThread;
	bool mPingConfirm;
	bool mChild;
	bool mReady;
	CLog mLog;

	std::string mHost;

	std::queue<CPacket> mQueue;

	protected:

	void startWorker();
	static void* static_worker(void* param);
	void worker();
	void processPacket(Cpacket* packet, EMessageType responseTo);
	void init();


	public:
	CClient(void* chain, const std::string& host, uint32_t port, bool child);
	~CClient();

	void start();
	void stop();
	void sendBlock(CBlock* block);


	std::string getHost(){return mHost;}
	uint32_t getPort(){return mPort;}
	bool isStopped(){return mStopped;}
	bool isReady(){return mReady;}
     };

  }
}
#endif
