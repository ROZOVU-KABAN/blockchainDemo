#ifndef __C_STORAGE_NONE_INCLUDED__
#define __C_STORAGE_NONE_INCLUDED__

#include "IStorage.h"
#include "../CBlock.h"

namespace blockchain
{
  namespace 
  {
     class CStorageNone:: public IStorage
     {
	public:
		virtual void load Chain(std::vector<CBlock*> chain){}
		virtual void load(CBlock* block){}
		virtual void save(CBlock* block,uint64_t blockCount){}

		virtual void dispose(){delete this;}
     };
  }
}

#endif