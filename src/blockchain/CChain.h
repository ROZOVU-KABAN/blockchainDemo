#ifndef __C_CHAIN_INCLUDED__
#define __C_CHAIN_INCLUDED__
#include "CBlock.h"
#include <vector>
#include "storage/EStorageType.h"
#include "storage/IStorage.h"


namespace blockchain
{
  
  class CChain
  {
  private:
	  std::vector<CBlock*> mChain;
	  CBlock* mCurrentBlock;
	  int mDifficulty;
	  storage::IStorage* mStorage;	  
  public:
	  CChain(int difficulty, storage::E_STORAGE_TYPE storageType = storage::EST_NONE);
	  ~CChain();
	  void appendToCurrentBlock(uint8_t* data,uint32_t size);
	  void nextBlock(bool save = true);
	  CBlock* getCurrentBlock();
	  void load();
	  size_t getBlockCount();
	  bool isValid();
  };
}

#endif
