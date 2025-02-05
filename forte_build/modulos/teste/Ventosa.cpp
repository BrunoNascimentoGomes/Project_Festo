/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Ventosa
 *** Description: Template for a Basic Function Block Type
 *** Version:
***     1.0: 2025-02-05/Bruno -  - 
 *************************************************************************/

#include "Ventosa.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Ventosa_gen.cpp"
#endif


DEFINE_FIRMWARE_FB(FORTE_Ventosa, g_nStringIdVentosa)

const CStringDictionary::TStringId FORTE_Ventosa::scm_anDataInputNames[] = {g_nStringIdPosicao_Rotativo_Recuo, g_nStringIdPosicao_Rotativo_Avanco, g_nStringIdPosicao_Atuador_Recuo, g_nStringIdPosicao_Atuador_Avanco};

const CStringDictionary::TStringId FORTE_Ventosa::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_Ventosa::scm_anDataOutputNames[] = {g_nStringIdVacuo_On};

const CStringDictionary::TStringId FORTE_Ventosa::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TDataIOID FORTE_Ventosa::scm_anEIWith[] = {0, 1, 2, 3, 255, 0, 1, 2, 3, 255};
const TForteInt16 FORTE_Ventosa::scm_anEIWithIndexes[] = {0, 5};
const CStringDictionary::TStringId FORTE_Ventosa::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_Ventosa::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_Ventosa::scm_anEOWithIndexes[] = {0, 2};
const CStringDictionary::TStringId FORTE_Ventosa::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};


const SFBInterfaceSpec FORTE_Ventosa::scm_stFBInterfaceSpec = {
  2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  4, scm_anDataInputNames, scm_anDataInputTypeIds,
  1, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

void FORTE_Ventosa::setInitialValues() {
}

void FORTE_Ventosa::alg_Init_(void) {
  st_Vacuo_On() = true;
}

void FORTE_Ventosa::alg_Update(void) {
  st_Vacuo_On() = true;
  if(st_Posicao_Rotativo_Recuo()) {
  	st_Vacuo_On() = false;
  }
}


void FORTE_Ventosa::enterStateSTART(void) {
  m_nECCState = scm_nStateSTART;
}

void FORTE_Ventosa::enterStateInit(void) {
  m_nECCState = scm_nStateInit;
  alg_Init_();
  sendOutputEvent(scm_nEventINITOID);
}

void FORTE_Ventosa::enterStateUpdate(void) {
  m_nECCState = scm_nStateUpdate;
  alg_Update();
  sendOutputEvent(scm_nEventCNFID);
}


void FORTE_Ventosa::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do {
    bTransitionCleared = true;
    switch(m_nECCState) {
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateInit();
        else
        if(scm_nEventREQID == pa_nEIID)
          enterStateUpdate();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInit:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateUpdate:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
        DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 3.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; // 0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID; // we have to clear the event after the first check in order to ensure correct behavior
  } while(bTransitionCleared);
}


