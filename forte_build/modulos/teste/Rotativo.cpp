/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Rotativo
 *** Description: Template for a Basic Function Block Type
 *** Version:
***     1.0: 2025-02-05/Bruno -  - 
 *************************************************************************/

#include "Rotativo.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Rotativo_gen.cpp"
#endif


DEFINE_FIRMWARE_FB(FORTE_Rotativo, g_nStringIdRotativo)

const CStringDictionary::TStringId FORTE_Rotativo::scm_anDataInputNames[] = {g_nStringIdPosicao_Rotativo_Recuo, g_nStringIdPosicao_Rotativo_Avanco, g_nStringIdVacuoostato};

const CStringDictionary::TStringId FORTE_Rotativo::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_Rotativo::scm_anDataOutputNames[] = {g_nStringIdAvanco, g_nStringIdRecuo};

const CStringDictionary::TStringId FORTE_Rotativo::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const TDataIOID FORTE_Rotativo::scm_anEIWith[] = {0, 1, 2, 255, 0, 1, 2, 255};
const TForteInt16 FORTE_Rotativo::scm_anEIWithIndexes[] = {0, 4};
const CStringDictionary::TStringId FORTE_Rotativo::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_Rotativo::scm_anEOWith[] = {0, 1, 255, 0, 1, 255};
const TForteInt16 FORTE_Rotativo::scm_anEOWithIndexes[] = {0, 3};
const CStringDictionary::TStringId FORTE_Rotativo::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};


const SFBInterfaceSpec FORTE_Rotativo::scm_stFBInterfaceSpec = {
  2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  3, scm_anDataInputNames, scm_anDataInputTypeIds,
  2, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

void FORTE_Rotativo::setInitialValues() {
}

void FORTE_Rotativo::alg_Init(void) {
  st_Avanco() = false;
  st_Recuo() = false;
}

void FORTE_Rotativo::alg_Update(void) {
  if((st_Posicao_Rotativo_Recuo() && st_Vacuoostato())) {
  	st_Avanco() = true;
  	st_Recuo() = false;
  }
  if((st_Posicao_Rotativo_Avanco() && (! st_Vacuoostato()))) {
  	st_Recuo() = true;
  	st_Avanco() = false;
  }
}


void FORTE_Rotativo::enterStateSTART(void) {
  m_nECCState = scm_nStateSTART;
}

void FORTE_Rotativo::enterStateInit_(void) {
  m_nECCState = scm_nStateInit_;
  alg_Init();
  sendOutputEvent(scm_nEventINITOID);
}

void FORTE_Rotativo::enterStateUpdate_(void) {
  m_nECCState = scm_nStateUpdate_;
  alg_Update();
  sendOutputEvent(scm_nEventCNFID);
}


void FORTE_Rotativo::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do {
    bTransitionCleared = true;
    switch(m_nECCState) {
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateInit_();
        else
        if(scm_nEventREQID == pa_nEIID)
          enterStateUpdate_();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInit_:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateUpdate_:
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


