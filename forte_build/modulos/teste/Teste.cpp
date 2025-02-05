/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Teste
 *** Description: Basic FB with empty ECC
 *** Version:
***     1.0: 2024-12-17/Bruno -  - 
 *************************************************************************/

#include "Teste.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Teste_gen.cpp"
#endif


DEFINE_FIRMWARE_FB(FORTE_Teste, g_nStringIdTeste)

const CStringDictionary::TStringId FORTE_Teste::scm_anDataInputNames[] = {g_nStringIdE1};

const CStringDictionary::TStringId FORTE_Teste::scm_anDataInputTypeIds[] = {g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_Teste::scm_anDataOutputNames[] = {g_nStringIdE2};

const CStringDictionary::TStringId FORTE_Teste::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TDataIOID FORTE_Teste::scm_anEIWith[] = {0, 255};
const TForteInt16 FORTE_Teste::scm_anEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_Teste::scm_anEventInputNames[] = {g_nStringIdEI1};

const TDataIOID FORTE_Teste::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_Teste::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_Teste::scm_anEventOutputNames[] = {g_nStringIdEO1};


const SFBInterfaceSpec FORTE_Teste::scm_stFBInterfaceSpec = {
  1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  1, scm_anDataInputNames, scm_anDataInputTypeIds,
  1, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

void FORTE_Teste::setInitialValues() {
}

void FORTE_Teste::alg_Alg1(void) {
  st_E2() = (! st_E2());
}


void FORTE_Teste::enterStateSTART(void) {
  m_nECCState = scm_nStateSTART;
}

void FORTE_Teste::enterStateInit(void) {
  m_nECCState = scm_nStateInit;
  alg_Alg1();
  sendOutputEvent(scm_nEventEO1ID);
}


void FORTE_Teste::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do {
    bTransitionCleared = true;
    switch(m_nECCState) {
      case scm_nStateSTART:
        if(scm_nEventEI1ID == pa_nEIID)
          enterStateInit();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInit:
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
        DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 2.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; // 0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID; // we have to clear the event after the first check in order to ensure correct behavior
  } while(bTransitionCleared);
}


