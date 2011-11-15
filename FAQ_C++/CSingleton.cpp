

#include "CSingleton.h"

CSingleton* CSingleton::m_pInstance = NULL;

CSingleton* CSingleton::getInstance() {
     if(NULL == m_pInstance ) {
            m_pInstance = new CSingleton();
     }
     return m_pInstance;
}

void CSingleton::destroyInstance() {
     delete m_pInstance;
     m_pInstance = NULL;
}

void CSingleton::doSomething() {
     cout<<"Am one and only one" << endl;
}
