/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Teste01
 *** Description: Template for a Basic Function Block Type
 *** Version:
***     1.0: 2024-12-17/Bruno -  - 
 *************************************************************************/

#include "Teste01.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Teste01_gen.cpp"
#endif


DEFINE_FIRMWARE_FB(FORTE_Teste01, g_nStringIdTeste01)

const CStringDictionary::TStringId FORTE_Teste01::scm_anDataInputNames[] = {g_nStringIdQI};

const CStringDictionary::TStringId FORTE_Teste01::scm_anDataInputTypeIds[] = {g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_Teste01::scm_anDataOutputNames[] = {g_nStringIdQO};

const CStringDictionary::TStringId FORTE_Teste01::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TDataIOID FORTE_Teste01::scm_anEIWith[] = {0, 255};
const TForteInt16 FORTE_Teste01::scm_anEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_Teste01::scm_anEventInputNames[] = {g_nStringIdINIT};

const TDataIOID FORTE_Teste01::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_Teste01::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_Teste01::scm_anEventOutputNames[] = {g_nStringIdINITO};


const SFBInterfaceSpec FORTE_Teste01::scm_stFBInterfaceSpec = {
  1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  1, scm_anDataInputNames, scm_anDataInputTypeIds,
  1, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

void FORTE_Teste01::setInitialValues() {
}

void FORTE_Teste01::alg_Change(void) {
  st_QO() = (! st_QO());
}


void FORTE_Teste01::enterStateSTART(void) {
  m_nECCState = scm_nStateSTART;
}

void FORTE_Teste01::enterStateTroca(void) {
  m_nECCState = scm_nStateTroca;
  alg_Change();
  sendOutputEvent(scm_nEventINITOID);
}


void FORTE_Teste01::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do {
    bTransitionCleared = true;
    switch(m_nECCState) {
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateTroca();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateTroca:
        if(1)
          enterStateSTART();
        else
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


