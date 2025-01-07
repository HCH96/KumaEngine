#pragma once


#define SINGLETON(classtype)			\
private:								\
	classtype();						\
	virtual ~classtype();				\
	friend CSingleton<classtype>;


