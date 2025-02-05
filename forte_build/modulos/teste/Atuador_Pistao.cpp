/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Atuador_Pistao
 *** Description: Template for a Basic Function Block Type
 *** Version:
***     1.0: 2025-02-04/FESTO -  - 
 *************************************************************************/

#include "Atuador_Pistao.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Atuador_Pistao_gen.cpp"
#endif


DEFINE_FIRMWARE_FB(FORTE_Atuador_Pistao, g_nStringIdAtuador_Pistao)

const CStringDictionary::TStringId FORTE_Atuador_Pistao::scm_anDataInputNames[] = {g_nStringIdTem_peca, g_nStringIdPeca_inicio_esteira, g_nStringIdPosicao_Pistao_Recuo, g_nStringIdPosicao_Pistao_Avanco, g_nStringIdPosicao_Rotativo_Recuo, g_nStringIdPosicao_Rotativo_Avanco};

const CStringDictionary::TStringId FORTE_Atuador_Pistao::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_Atuador_Pistao::scm_anDataOutputNames[] = {g_nStringIdAvanco_Atuador};

const CStringDictionary::TStringId FORTE_Atuador_Pistao::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TDataIOID FORTE_Atuador_Pistao::scm_anEIWith[] = {0, 1, 2, 3, 4, 5, 255, 0, 1, 2, 3, 4, 5, 255};
const TForteInt16 FORTE_Atuador_Pistao::scm_anEIWithIndexes[] = {0, 7};
const CStringDictionary::TStringId FORTE_Atuador_Pistao::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdUPDT};

const TDataIOID FORTE_Atuador_Pistao::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_Atuador_Pistao::scm_anEOWithIndexes[] = {0, 2};
const CStringDictionary::TStringId FORTE_Atuador_Pistao::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};


const SFBInterfaceSpec FORTE_Atuador_Pistao::scm_stFBInterfaceSpec = {
  2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  6, scm_anDataInputNames, scm_anDataInputTypeIds,
  1, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

void FORTE_Atuador_Pistao::setInitialValues() {
}

void FORTE_Atuador_Pistao::alg_Init_(void) {
  st_Avanco_Atuador() = false;
}

void FORTE_Atuador_Pistao::alg_Update_(void) {
  st_Avanco_Atuador() = false;
  if((((! st_Tem_peca()) && st_Posicao_Pistao_Recuo()) && st_Posicao_Rotativo_Avanco())) {
  	st_Avanco_Atuador() = true;
  }
}


void FORTE_Atuador_Pistao::enterStateSTART(void) {
  m_nECCState = scm_nStateSTART;
}

void FORTE_Atuador_Pistao::enterStateInit(void) {
  m_nECCState = scm_nStateInit;
  alg_Init_();
  sendOutputEvent(scm_nEventINITOID);
}

void FORTE_Atuador_Pistao::enterStateUpdate(void) {
  m_nECCState = scm_nStateUpdate;
  alg_Update_();
  sendOutputEvent(scm_nEventCNFID);
}


void FORTE_Atuador_Pistao::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do {
    bTransitionCleared = true;
    switch(m_nECCState) {
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateInit();
        else
        if(scm_nEventUPDTID == pa_nEIID)
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


