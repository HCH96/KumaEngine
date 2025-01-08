#pragma once

#define DEVICE GDevice->GetDevice()
#define CONTEXT GDevice->GetContext()

#define SINGLETON(classtype)			\
private:								\
	classtype();						\
	virtual ~classtype();				\
	friend CSingleton<classtype>;


